 #include "estbComFD.h"
#include <iostream>
#include <string> // For std::string
#include <utility> // For std::move
#include "httpReqResHandler.h"





// --- Helper Classes (Session and Listener) for Boost.Beast ---

// Session class: Handles a single HTTP server connection.
// Implemented as a helper class within the .cpp file for encapsulation.
class Session : public std::enable_shared_from_this<Session> {
    tcp::socket socket_;
    beast::flat_buffer buffer_; // Buffer for reads
    http::request_type req_;    // The HTTP request object

    // A function pointer/lambda to the request handler (e.g., estbComQT::handle_request)
    std::function<http::response_type(http::request_type const&)> request_handler_;

public:
    explicit Session(tcp::socket socket,
                     std::function<http::response_type(http::request_type const&)> handler)
        : socket_(std::move(socket)), request_handler_(std::move(handler)) {}

    // Start the session by initiating a read operation
    void run() {
        // Reset the request object for a new read, crucial for keep-alive connections
        req_ = {};
        do_read();
    }

private:
    // Initiates an asynchronous read for the HTTP request
    void do_read() {
        auto self(shared_from_this()); // Keep session alive
        http::async_read(socket_, buffer_, req_,
            [this, self](beast::error_code ec, std::size_t bytes_transferred) {
                // If no error, process the request and send a response
                if (!ec) {
                    do_write(request_handler_(req_));
                } else if (ec == http::error::end_of_stream) {
                    // Client closed the connection gracefully. Nothing to do.
                } else {
                    std::cerr << "Session read error: " << ec.message() << std::endl;
                }
            });
    }

    // Initiates an asynchronous write for the HTTP response
    void do_write(http::response_type res) {
        auto self(shared_from_this()); // Keep session alive
        // Use a shared_ptr for the response to ensure it lives until async_write completes
        auto sp = std::make_shared<http::response_type>(std::move(res));

        http::async_write(socket_, *sp,
            [this, self, sp](beast::error_code ec, std::size_t bytes_transferred) {
                if (!ec) {
                    // If the connection is keep-alive, initiate another read for the next request
                    if (sp->keep_alive()) {
                        run(); // Continue reading
                    } else {
                        // Otherwise, shut down the write half of the socket
                        beast::error_code ignored_ec;
                        socket_.shutdown(tcp::socket::shutdown_send, ignored_ec);
                    }
                } else {
                    std::cerr << "Session write error: " << ec.message() << std::endl;
                }
            });
    }
};

// Listener class: Accepts incoming TCP connections and creates Session objects.
// Implemented as a helper class within the .cpp file for encapsulation.
class Listener : public std::enable_shared_from_this<Listener> {
    net::io_context& ioc_;
    tcp::acceptor acceptor_;
    // A function pointer/lambda to the request handler (e.g., estbComQT::handle_request)
    std::function<http::response_type(http::request_type const&)> request_handler_;

public:
    Listener(net::io_context& ioc, tcp::endpoint endpoint,
             std::function<http::response_type(http::request_type const&)> handler)
        : ioc_(ioc), acceptor_(net::make_strand(ioc)), request_handler_(std::move(handler)) {
        beast::error_code ec;

        // Open the acceptor
        acceptor_.open(endpoint.protocol(), ec);
        if (ec) {
            std::cerr << "Listener open error: " << ec.message() << std::endl;
            // Handle error, maybe throw or log more robustly
            return;
        }

        // Allow address reuse (important for restarting servers quickly)
        acceptor_.set_option(net::socket_base::reuse_address(true), ec);
        if (ec) {
            std::cerr << "Listener set_option error: " << ec.message() << std::endl;
            // Handle error
            return;
        }

        // Bind to the specified address and port
        acceptor_.bind(endpoint, ec);
        if (ec) {
            std::cerr << "Listener bind error: " << ec.message() << std::endl;
            // Handle error
            return;
        }

        // Start listening for connections
        acceptor_.listen(net::socket_base::max_listen_connections, ec);
        if (ec) {
            std::cerr << "Listener listen error: " << ec.message() << std::endl;
            // Handle error
            return;
        }

        // Immediately start accepting the first connection
        do_accept();
    }

private:
    // Initiates an asynchronous accept operation
    void do_accept() {
        // The new connection is accepted on a new strand to prevent deadlock
        // if the handler also needs to access the acceptor's strand.
        acceptor_.async_accept(net::make_strand(ioc_),
                               [this](beast::error_code ec, tcp::socket socket) {
            if (!ec) {
                // On successful accept, create a new session and run it
                std::make_shared<Session>(std::move(socket), request_handler_)->run();
            } else {
                // An error occurred during accept. If it's not operation_aborted
                // (which happens when ioc.stop() is called), then print it.
                if (ec != net::error::operation_aborted) {
                    std::cerr << "Listener accept error: " << ec.message() << std::endl;
                }
            }
            // Always continue to accept new connections, unless acceptor was explicitly closed
            if (!acceptor_.is_open()) return;
            do_accept();
        });
    }

public:
    // A dummy run method, primarily to align with previous examples.
    // The actual accepting starts in the constructor.
    void run() {
        // do_accept() is called in the constructor, so nothing more is strictly needed here.
    }
};

// --- estbComQT Class Implementation ---

estbComFD::estbComFD() : running(false) {
    // Boost.Asio handles its own platform-specific initialization (e.g., Winsock on Windows).
    // No explicit WSAStartup/WSACleanup needed here for Boost.Asio's usage.
}

estbComFD::~estbComFD() {
    stopServer(); // Ensure server is stopped and resources are released
}




void estbComFD::createServer(int port, std::string ip_addr) {
    if (running) {
        std::cerr << "Server is already running." << std::endl;
        return;
    }
    setupHandler();

    // The io_context must be created here, as it will be run in the current thread.
    ioc_ = std::make_unique<net::io_context>(1); // One thread hint

    try {
        running = true; // Set flag to true

        // Set up the endpoint to listen on (e.g., 0.0.0.0:8080)
        auto const address = net::ip::make_address(ip_addr.c_str());
        tcp::endpoint endpoint{address, static_cast<unsigned short>(port)};
    // Important
        // Create and start the listener, passing the static request handler
        listener_ = std::make_shared<Listener>(
    *ioc_,
        endpoint,
        *global_handler
        );

        listener_->run(); // Initiates the first accept operation

        std::cout << "HTTP Server is listening on: " << ip_addr << ':' << port << std::endl;

        // Run the io_context. This call will block until io_context::stop() is called.
         ioc_->run();
         std::cout << "HTTP Server io_context stopped cleanly." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "HTTP Server error: " << e.what() << std::endl;
        running = false; // Mark as not running if an exception occurs
    }

    // Clean up members after ioc_->run() returns
    listener_.reset(); // Release the listener shared_ptr
    ioc_.reset();      // Destroy the io_context
    running = false;   // Ensure running flag is false
}

void estbComFD::stopServer() {
    if (!running) {
        std::cout << "Server is not running." << std::endl;
        return;
    }

    // Signal the io_context to stop processing events.
    // This will cause ioc_->run() (which is blocking in the thread launched by main) to return.
    if (ioc_) { // Check if ioc_ was initialized
        ioc_->stop();
    }
    // No need to join a thread here, as main() manages the thread.
    // The destructor will ensure cleanup happens if stopServer() wasn't explicitly called.
    std::cout << "HTTP Server stop signal sent." << std::endl;
}
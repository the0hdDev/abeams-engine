#ifndef ESTBCOMQT_H
#define ESTBCOMQT_H

#include <atomic>
#include <memory> // For std::unique_ptr and std::shared_ptr
#include <functional> // For std::function

// Boost.Beast and Boost.Asio includes
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp> // For BOOST_BEAST_VERSION_STRING

// Forward declarations for Boost.Beast components to avoid including full headers in .h
namespace boost {
namespace asio {
class io_context;
namespace ip {
class tcp;
} // namespace ip
} // namespace asio
namespace beast {
namespace http {
// Forward declare specific HTTP message types we use
template<bool isRequest, class Body, class Fields> class message;
using string_body = boost::beast::http::string_body; // Alias for convenience
using request_type = message<true, string_body, boost::beast::http::fields>;
using response_type = message<false, string_body, boost::beast::http::fields>;
} // namespace http
} // namespace beast
} // namespace boost

// Aliases for convenience, making code cleaner
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

// Forward declare Listener and Session classes which will be defined in the .cpp file
class Listener;
class Session;

class estbComFD {
public:
    estbComFD();                    // Constructor
    ~estbComFD();                   // Destructor

    // This function will now be blocking, as it calls ioc_.run().
    // It is intended to be called from a separate thread, as in your main().
    void createServer(int port, std::string ip_addr);

    void stopServer();              // Stop the HTTP server

private:
    // This function produces an HTTP response for the given request.
    // Made static as it doesn't depend on an estbComQT instance's state.
    static http::response_type handle_request(http::request_type const& req);

    std::atomic<bool> running;                  // Flag to indicate if server is running

    // Boost.Asio and Boost.Beast components
    std::unique_ptr<net::io_context> ioc_;      // The I/O context for asynchronous operations
    std::shared_ptr<Listener> listener_;        // The listener that accepts incoming connections
};

#endif // ESTBCOMQT_H
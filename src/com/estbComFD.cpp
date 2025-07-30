#include "estbComFD.h"
#include <../io/util/logsys/logsys.h>
#include <string>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket.hpp>
#include "httpReqResHandler.h"


namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;


estbComFD::estbComFD(uint16_t port)
{
      estbComFD::port = port;
      logSys.info("Starting File Descriptor");
}

estbComFD::~estbComFD() {
      websocket::close_code::normal;
      logSys.info("Communication Server stopped");
}


Handler handler;

void estbComFD::run() const {

   try {

      net::io_context ioc;

      // generate tcp acceptor at given port
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 3405));
      logSys.info("Communication Server is running at: " + std::to_string(estbComFD::port));
      // wait for incoming connections
      tcp::socket socket(ioc);
      acceptor.accept(socket);
       logSys.info("client connected");

      // initialise websocket
      websocket::stream<tcp::socket> ws(std::move(socket));
      ws.accept();
      logSys.info("websocket handshake completed successfully");

      // enter the main loop to handle incoming messages
      for (;;) {
         beast::flat_buffer buffer;
         handler.echo(ws, buffer);
      }
   } catch (const std::exception& e) {

      std::cout << "error" << e.what() << std::endl;
   }
}

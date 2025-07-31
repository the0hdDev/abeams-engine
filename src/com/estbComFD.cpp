#include "estbComFD.h"
#include <../io/util/logsys/logsys.h>
#include <string>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket.hpp>
#include "httpReqResHandler.h"
#include <../initialize.h>

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



void estbComFD::run() const {

   Handler* handler = new Handler();


   try {

      net::io_context ioc;

      // generate tcp acceptor at given port
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 3405));
      logSys.info("Communication Server is running at: " + 3405);
      // wait for incoming connections
      tcp::socket socket(ioc);
      acceptor.accept(socket);
       logSys.info("client connected");

      // initialise websocket
      websocket::stream<tcp::socket> ws(std::move(socket));
      ws.accept();
      logSys.info("websocket handshake completed successfully");

      // enter the main loop to handle incoming messages
      while (true) {

         beast::flat_buffer buffer;
         handler->echo(ws, buffer);
         handler->wsHandler(ws, buffer);

         // pretty cli thing on but in the com thread

         std::cout << "\n> ";
      }
      delete handler;
   } catch (const std::exception& e) {

      std::cout << "error" << e.what() << std::endl;
   }
}

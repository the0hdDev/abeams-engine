#include "wsServer.h"
#include <../io/util/logsys/logsys.h>
#include <string>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket.hpp>
#include "wsHandler.h"
#include <../initialize.h>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;


wsServer::wsServer(uint16_t port)
{
      wsServer::port = port;
      logSys.info("Starting File Descriptor");

}

wsServer::~wsServer() {
      websocket::close_code::normal;
      logSys.info("Communication Server stopped");

}



void wsServer::run() const {

   wsHandler* handler = new wsHandler();


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
         handler->wsHandlerLoop(ws, buffer);

      }
      delete handler;
   } catch (const std::exception& e) {

      std::cout << "error" << e.what() << std::endl;
   }
}

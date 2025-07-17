#include "estbComFD.h"
#include <../io/util/logsys/logsys.h>
#include <string>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

Log<std::string> logger;


estbComFD::estbComFD(uint16_t port)
    : port_(port) {}

Handler handler;

void estbComFD::run() const {

   try {

      net::io_context ioc;

      // generate tcp acceptor at given port
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port_));
      logger.info("Communication Server is running at: " + port_);
      // wait for incoming connections
      tcp::socket socket(ioc);
      acceptor.accept(socket);
       logger.info("client connected");

      // initialise websocket
      websocket::stream<tcp::socket> ws(std::move(socket));
      ws.accept();
      logger.info("websocket handshake completed successfully");

      // enter the main loop to handle incoming messages
      for (;;) {
         beast::flat_buffer buffer;
         handler.echo(ws, buffer);
      }
   } catch (const std::exception& e) {

      std::cout << "error" << e.what() << std::endl;
   }
}
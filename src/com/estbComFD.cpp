#include "estbComFD.h"
#include <../io/util/logsys/logsys.h>
#include <string>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;


estbComFD::estbComFD(unsigned short port)
    : port_(port) {
        logSys.info("Starting File Descriptor");
    }

Handler handler;

void estbComFD::run() const {

   try {

      net::io_context ioc;

      // generate tcp acceptor at given port
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port_));
      logSys.info("Communication Server is running at: " + std::to_string(port_));
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

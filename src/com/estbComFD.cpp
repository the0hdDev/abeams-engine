#include "estbComFD.h"
#include <boost/beast/core.hpp>
#include <../io/util/logsys/logsys.h>
#include <string>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

Log<std::string> logger;

// ---Konstruktor: Speichert Portnummer.
estbComFD::estbComFD(uint16_t port)
    : port_(port) {}


void estbComFD::run() {
      Handler handler;
   try {
      // 1. IO-Kontext für Netzwerkoperationen.
      net::io_context ioc;

      // 2. TCP-Akzeptor auf dem gewünschten Port erzeugen.
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port_));
      logger.info("comserv is runnning on: " + port_);
      // 3. Auf eine eingehende Verbindung warten.
      tcp::socket socket(ioc);
      acceptor.accept(socket);
       logger.info("client connected");

      // 4. WebSocket-Stream initialisieren.
      websocket::stream<tcp::socket> ws(std::move(socket));

      // 5. WebSocket-Handshake durchführen.
      ws.accept();
      logger.info("websocker handshake completed successfully");

      // 6. Nachrichten empfangen und zurückschicken (Echo).
      for (;;) {
         beast::flat_buffer buffer;
         handler.echo(ws, buffer);
      }
   } catch (const std::exception& e) {

      logger.error("error", 0);
   }
}
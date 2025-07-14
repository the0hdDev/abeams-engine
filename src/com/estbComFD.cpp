#include "estbComFD.h"
#include <boost/beast/core.hpp>
#include <iostream>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = net::ip::tcp;

// Konstruktor: Speichert Portnummer.
estbComFD::estbComFD(uint16_t port)
    : port_(port) {}

void estbComFD::run() {
   try {
      // 1. IO-Kontext für Netzwerkoperationen.
      net::io_context ioc;

      // 2. TCP-Akzeptor auf dem gewünschten Port erzeugen.
      tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port_));
      std::cout << "WebSocket Server läuft auf Port " << port_ << std::endl;

      // 3. Auf eine eingehende Verbindung warten.
      tcp::socket socket(ioc);
      acceptor.accept(socket);
      std::cout << "Client verbunden!" << std::endl;

      // 4. WebSocket-Stream initialisieren.
      websocket::stream<tcp::socket> ws(std::move(socket));

      // 5. WebSocket-Handshake durchführen.
      ws.accept();
      std::cout << "WebSocket Handshake abgeschlossen." << std::endl;

      // 6. Nachrichten empfangen und zurückschicken (Echo).
      for (;;) {
         beast::flat_buffer buffer;
         ws.read(buffer); // Empfang einer Nachricht
         std::string received = beast::buffers_to_string(buffer.data());
         std::cout << "Empfangen: " << received << std::endl;

         ws.text(ws.got_text()); // Modus setzen
         // Sende eine Nachricht aus beast::flat_buffer
         ws.write(boost::asio::buffer(buffer.data(), buffer.size()));
      }
   } catch (const std::exception& e) {
      std::cerr << "Fehler: " << e.what() << std::endl;
   }
}
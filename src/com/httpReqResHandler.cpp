#include "httpReqResHandler.h"

Log<std::string> logger3;

Handler::Handler()
{
    logger3.info("Handler created");
}

Handler::~Handler()
{
    logger3.info("Handler destroyed");
}

void Handler::wsHandler(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{

}

void Handler::echo(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{
    buffer.clear(); // Buffer leeren
    ws.read(buffer); // Nachricht lesen
    logger3.info("Received message: " + boost::beast::buffers_to_string(buffer.data()));
    ws.text(ws.got_text()); // Text/Binary setzen
    ws.write(buffer.data()); // Antwort schicken (Echo)

}

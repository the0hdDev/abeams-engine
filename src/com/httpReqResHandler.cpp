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
    ws.text(ws.got_text());
    ws.write(buffer.data());
}



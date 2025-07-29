#include "httpReqResHandler.h"

#include "../io/util/logsys/logsys.h"

Handler::Handler()
{
    logSys.info("WebSocketHandler created successfully");
}

Handler::~Handler()
{
    logSys.info("WebSocket Handler destroyed successfully");
}

void Handler::wsHandler(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{

}
void Handler::echo(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{
    buffer.clear();
    ws.read(buffer);
    logSys.info(std::to_string(ws.read(buffer)));
    ws.text(ws.got_text());
    ws.write(buffer.data());
}



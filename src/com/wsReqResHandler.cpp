#include "wsReqResHandler.h"

#include "../io/util/logsys/logsys.h"

Handler::Handler()
{
    logSys.info("WebSocket Handler created successfully");
}

Handler::~Handler()
{
    logSys.info("WebSocket Handler destroyed successfully");
}

void Handler::wsHandler(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{
    buffer.clear();
    ws.read(buffer);
    std::string receivedData = std::string(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));
    std::cout << Log::WHITE << "\nReceived (Handler): " << receivedData << Log::RESET << std::endl; 

    if (receivedData == "ping") {
        std::cout << Log::YELLOW << "Ping received, sending pong..." << Log::RESET << std::endl;
        ws.text(true);
        ws.write(boost::asio::buffer("pong"));
    } else if (receivedData == "close") {
        std::cout << Log::YELLOW << "Close request received, closing connection..." << Log::RESET << std::endl;
        ws.close(boost::beast::websocket::close_code::normal);
    } else {
        echo(ws, buffer);
    }

}
void Handler::echo(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
{
    buffer.clear();
    ws.read(buffer);
    // logSys.info(std::to_string(ws.read(buffer)));
    std::string receivedData = std::string(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));
    std::cout << Log::WHITE << "\nReceived: "<< receivedData << Log::RESET << std::endl;
    ws.text(ws.got_text());
    ws.write(buffer.data());
}


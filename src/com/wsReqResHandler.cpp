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

using ws_t = boost::beast::websocket::stream<boost::asio::ip::tcp::socket>;
using buffer_t = boost::beast::flat_buffer;
using handler_func = std::function<void(ws_t&, buffer_t&)>;


namespace keyFunction {


    void ping(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Ping");
    }

    void auth(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Auth");
    }

    void init(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Init");
    }

    void close(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Close");
    }

    void getData(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Get Data");
    }

    void postData(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Post Data");
    }

    void putData(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Put Data");
    }

    void deleteData(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Delete Data");
    }

    void updateData(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Update Data");
    }

    void subscribeStatus(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Subscribe Status");
    }

    void unsubscribeStatus(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer) {
        logSys.info("Unsubscribe Status");
    }

}


std::unordered_map<std::string, handler_func> keywordMap = {
        {"PING", keyFunction::ping},
        {"AUTH", keyFunction::auth},
        {"INIT", keyFunction::init},
        {"CLOSE", keyFunction::close},
        {"GET_DATA", keyFunction::getData},
        {"POST_DATA", keyFunction::postData},
        {"PUT_DATA", keyFunction::putData},
        {"DELETE_DATA", keyFunction::deleteData},
        {"UPDATE_DATA", keyFunction::updateData},
        {"SUBSCRIBE_STATUS", keyFunction::subscribeStatus},
        {"UNSUBSCRIBE_STATUS", keyFunction::unsubscribeStatus}
};


void Handler::wsHandler(ws_t& ws, buffer_t& buffer)
{
    buffer.clear();
    ws.read(buffer);
    std::string receivedData = std::string(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));
    for (const auto& [key, func] : keywordMap) {
        if (receivedData.find(key) != std::string::npos) {
            //  std::cout << Log::WHITE << "\nReceived: " << receivedData << Log::RESET << std::endl;
            func(ws, buffer);

            return;
        }
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



/* Ping
 * AUTH
 * INIT
 * CLOSE
 *
 * ---- Data ----
 * GET_DATA
 * POST_DATA
 * PUT_DATA
 * DELETE_DATA
 * UPDATE_DATA
 * SUBSCRIBE_STATUS
 * UNSUBSCRIBE_STATUS
*/



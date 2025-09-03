#include "wsHandler.h"

#include "util/logsys/logsys.h"

wsHandler::wsHandler()
{
    logSys.info("WebSocket Handler created successfully");
}

wsHandler::~wsHandler()
{
    logSys.info("WebSocket Handler destroyed successfully");
}

using ws_t = boost::beast::websocket::stream<boost::asio::ip::tcp::socket>;
using buffer_t = boost::beast::flat_buffer;
using handler_func = std::function<void(ws_t&, buffer_t&)>;

void internalServerError(ws_t& ws, buffer_t& buffer) {
    logSys.error("Internal Server Error");
    buffer.clear();
    std::string errorMessage = "Internal Server Error - 500 ERROR\n";
    auto preparedBuffer = buffer.prepare(errorMessage.size());
    std::memcpy(preparedBuffer.data(), errorMessage.data(), errorMessage.size());
    buffer.commit(errorMessage.size());
    ws.text(ws.got_text());
    ws.write(buffer.data());
}

namespace keyFunction {


    void ping(ws_t& ws, buffer_t& buffer) {
        buffer.clear();
        std::string pingMessage = "PONG - 200 OK \n";
        logSys.info("Ping received, sending response: " + pingMessage);
        auto preparedBuffer = buffer.prepare(pingMessage.size());
        std::memcpy(preparedBuffer.data(), pingMessage.data(), pingMessage.size());
        buffer.commit(pingMessage.size());
        ws.text(ws.got_text());
        ws.write(buffer.data());
    }

    void auth(ws_t& ws, buffer_t& buffer) {
        logSys.info("Auth");
    }

    void init(ws_t& ws, buffer_t& buffer) {
        logSys.info("Init");
    }

    void close(ws_t& ws, buffer_t& buffer) {
        try {
            logSys.info("Client requested to close the connection");
            buffer.clear();
            std::string pingMessage = "Closing connection on Clients request - 200 OK \n";
            logSys.info("Ping received, sending response: " + pingMessage);
            auto preparedBuffer = buffer.prepare(pingMessage.size());
            std::memcpy(preparedBuffer.data(), pingMessage.data(), pingMessage.size());
            buffer.commit(pingMessage.size());
            ws.text(ws.got_text());
            ws.write(buffer.data());
            ws.close(boost::beast::websocket::close_code::normal);
            logSys.info("WebSocket connection closed successfully\n");
        } catch (const std::exception& e) {
            internalServerError(ws, buffer);
        }
    }

    void getData(ws_t& ws, buffer_t& buffer) {
        logSys.info("Get Data");
    }

    void postData(ws_t& ws, buffer_t& buffer) {
        logSys.info("Post Data");
    }

    void putData(ws_t& ws, buffer_t& buffer) {
        logSys.info("Put Data");
    }

    void deleteData(ws_t& ws, buffer_t& buffer) {
        logSys.info("Delete Data");
    }

    void updateData(ws_t& ws, buffer_t& buffer) {
        logSys.info("Update Data");
    }

    void subscribeStatus(ws_t& ws, buffer_t& buffer) {
        logSys.info("Subscribe Status");
    }

    void unsubscribeStatus(ws_t& ws, buffer_t& buffer) {
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


void wsHandler::wsHandlerLoop(ws_t& ws, buffer_t& buffer)
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



void wsHandler::echo(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer)
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



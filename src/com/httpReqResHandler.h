#include <nlohmann/json.hpp>
#include <boost/beast/core.hpp>
#include <../io/util/logsys/logsys.h>
#include <string>

#include "boost/beast/websocket/stream.hpp"

class handler {
public:
    handler();
    ~handler();
    void handle(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer);
};

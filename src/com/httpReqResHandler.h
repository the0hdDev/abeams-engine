#pragma once
#include "boost/asio/ip/tcp.hpp"
#include "boost/beast/core/flat_buffer.hpp"
#include "boost/beast/websocket/stream.hpp"
#include <nlohmann/json.hpp>
#include <boost/beast/core.hpp>
#include <../io/util/logsys/logsys.h>
#include <string>


class Handler {
public:
    Handler();
    ~Handler();
    void wsHandler(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer);
    void echo(boost::beast::websocket::stream<boost::asio::ip::tcp::socket>& ws, boost::beast::flat_buffer& buffer);
};

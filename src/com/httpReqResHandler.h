//
// Created by theow on 05.07.2025.
//
#pragma once
#ifndef HANDLER_H
#define HANDLER_H

#include <functional>
#include <boost/beast/http.hpp>
#include <nlohmann/json.hpp>

namespace http = boost::beast::http;


class httpReqResHandler {

};

extern std::shared_ptr<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>> global_handler;
void setupHandler();

#endif //HANDLER_H

//
// Created by theow on 05.07.2025.
//

#include "httpReqResHandler.h"

std::shared_ptr<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>> global_handler = nullptr;


void setupHandler() {
    global_handler = std::make_shared<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>>(
        [](const http::request<http::string_body>& req) -> http::response<http::string_body> {
            http::response<http::string_body> res{http::status::ok, req.version()};
            res.set(http::field::content_type, "text/plain");
            res.body() = "Hello from heap-stored handler!";
            res.prepare_payload();
            return res;
        }
    );
}
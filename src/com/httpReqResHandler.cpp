//
// Created by theow on 05.07.2025.
//

#include "httpReqResHandler.h"

#include <iostream>

using nlohmann::json;




// Hilfsfunktion, um Antworten schnell zu bauen
http::response<http::string_body> make_response(
    const std::string& body,
    http::status status,
    unsigned version = 11,
    const std::string& content_type = "text/plain"
) {
    http::response<http::string_body> res{status, version};
    res.set(http::field::content_type, content_type);
    res.body() = body;
    res.prepare_payload();
    return res;
}



// global_handler als shared_ptr auf eine Funktion, die HTTP-Requests beantwortet
std::shared_ptr<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>> global_handler;

// Setup-Funktion, die den Handler mit mehreren Endpunkten initialisiert
void setupHandler() {

    global_handler = std::make_shared<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>>(
        [](const http::request<http::string_body>& req) -> http::response<http::string_body> {

            // JSON

            json rootResponse = {
            {"path", "/"},
            {"Response", "You are accessing '/' "}
            };

            json apiSoloResponse = {
            {"path", "/"},
            {"Response", "Please specify  '/' "}
            };

            std::string target = req.target();

            if (req.method() != http::verb::get) {
                std::cout << "Client tried to access with unallowed Method: " << target << ' ' << req.method() << std::endl;
                return make_response("Method not allowed", http::status::method_not_allowed, req.version());
            }
            // TODO
            else if (target == "/") {
                std::cout << "Client tried to access: " << target << ' ' << req.method() << std::endl;
                return make_response(rootResponse.dump(), http::status::ok, req.version());
            }
            else if (target == "/api/") {
                std::cout << "Client tried to access: " << target << ' ' << req.method() << std::endl;
                return make_response(" from /api/hello!", http::status::ok, req.version());
            }
            else if (target == "/api/status") {
                std::cout << "Client tried to access: " << target << ' ' << req.method()<< std::endl;
                return make_response("{\"status\":\"ok\"}", http::status::ok, req.version(), "application/json");
            }
            else {
                std::cout << "Client tried to access a not found Path: " << target << ' ' << req.method() << std::endl;
                return make_response("404 Not Found", http::status::not_found, req.version());
            }
        }
    );
}

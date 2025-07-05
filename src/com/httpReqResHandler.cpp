//
// Created by theow on 05.07.2025.
//

#include "httpReqResHandler.h"

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
std::shared_ptr<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>> global_handler = nullptr;

// Setup-Funktion, die den Handler mit mehreren Endpunkten initialisiert
void setupHandler() {
    global_handler = std::make_shared<std::function<http::response<http::string_body>(const http::request<http::string_body>&)>>(
        [](const http::request<http::string_body>& req) -> http::response<http::string_body> {
            std::string target = req.target().to_string();

            if (req.method() != http::verb::get) {
                return make_response("Method not allowed", http::status::method_not_allowed, req.version());
            }
            else if (target == "/") {
                return make_response("Hello from root endpoint!", http::status::ok, req.version());
            }
            else if (target == "/api/hello") {
                return make_response("Hello from /api/hello!", http::status::ok, req.version());
            }
            else if (target == "/api/status") {
                return make_response("{\"status\":\"ok\"}", http::status::ok, req.version(), "application/json");
            }
            else {
                return make_response("404 Not Found", http::status::not_found, req.version());
            }
        }
    );
}

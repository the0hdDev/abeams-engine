#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "com/httpReqResHandler.h"

        using std::cout;
        using std::endl;
        using std::cin;
        using std::string;

int main() {

    const uint16_t s_port = 3405;
    const string confpath = "mconf.json";
    bool running = true;
    string ip_addr = "127.0.0.1";
    ReadConfig* conf = new ReadConfig();
    bool isDebug = conf->isDebug(confpath);
    delete(conf);


    cout << isDebug << endl;

    estbComFD comServer;
    std::thread serverThread([&]() {
      comServer.createServer(s_port, ip_addr);

        if (global_handler) {
        // Beispiel-Request
        http::request<http::string_body> dummy_req{http::verb::get, "/", 11};
        auto res = (*global_handler)(dummy_req);
        std::cout << res.body() << std::endl;
    } else {
        std::cerr << "No handler assigned!" << std::endl;
    }


    });
    serverThread.detach();


    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    return 0;

}
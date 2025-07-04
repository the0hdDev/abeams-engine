#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"
#include <thread>

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

    estbComQT comServer;
    std::thread serverThread([&]() {
      comServer.createServer(s_port, ip_addr);
    });
    serverThread.detach();


    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    return 0;

}
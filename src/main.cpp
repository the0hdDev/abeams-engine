#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "com/httpReqResHandler.h"
#include "io/util/logsys/logsys.h"

        using std::cout;
        using std::endl;
        using std::cin;
        using std::string;

void setupHandler();

int main() {
    setupHandler();
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
    });
    serverThread.detach();

    cout << "threading working\n";
    logsys::print("ohio sigma");

    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    };
}
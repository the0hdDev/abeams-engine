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




int main()
{
    setupHandler();
    const uint16_t s_port = 3405;
    const string confpath = "mconf.json";
    bool running = true;
    string ip_addr = "127.0.0.1";
    ReadConfig conf;
    bool isDebug = conf.isDebug(confpath);


    estbComFD comServer;
    std::thread serverThread([&]()
    {
      comServer.createServer(s_port, ip_addr);
    });
    serverThread.detach();

    Log<string> log;

    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    };
}
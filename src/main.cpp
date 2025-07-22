#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"

using std::string;

int main()
{
    const string confPath = "config.json";
    logSys.info("LogSys started successfully");
    ReadConfig conf;
    // const uint32_t port = conf.getPort(confPath);
    const uint32_t port = 3405;

    logSys.setLogLevel(conf.getLogLevel("config.json"));

    estbComFD* comSocket = new estbComFD(port);
    std::thread serverThread([&]()
    {
      comSocket->run();
    });
    serverThread.detach();





    // Main loop
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    };
}
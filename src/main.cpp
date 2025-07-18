#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"

using std::string;




int main()
{
    const uint16_t s_port = 3405;
    const string confpath = "mconf.json";

    logSys.info("LogSys started successfully");
    ReadConfig conf;
    if (conf.isDebug(confpath) == true) {

    };


    estbComFD* comSocket = new estbComFD(3405);
    std::thread serverThread([&]()
    {

      comSocket->run();
    });
    serverThread.detach();

    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    };
}
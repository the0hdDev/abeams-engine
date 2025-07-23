#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"

using std::string;

void shutdownSystem();

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
    logSys.info("Entering main loop");
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        /* std::cin.get();
        std::string input{};
        std::cin >> input;
        if (input == "exit") {
            shutdownSystem();
            delete comSocket;
            break;
        } else if (input == "info") {
            logSys.info("Received info command");
        } else {
            logSys.warning("Unknown command: " + input);
        } */
    };

}

void shutdownSystem() {
    logSys.info("Shutting down system...");
    logSys.info("System shutdown complete.");
}
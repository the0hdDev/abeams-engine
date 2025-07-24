#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"
#include "io/thread/threadpool/threadpool.h"

using std::string;

void shutdownSystem();
estbComFD* comSocket = nullptr;

int main()
{
    logSys.info("LogSys started successfully");

    readConfig conf("config.json");
    estbComFD* comSocket = new estbComFD(conf.getPort());
    threadPool threadpool(4);
    logSys.setLogLevel(conf.getLogLevel());

    std::thread serverThread([&]()
    {
      comSocket->run();
    });
    serverThread.detach();


    // Main loop
    logSys.info("Entering main loop");
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // CLI
        std::cin.get();
        std::string input{};
        std::cin >> input;
        if (input == "exit") {
            shutdownSystem();
            return 0;
            break;
        } else if (input == "info") {
            logSys.info("Received info command");
        } else {
            logSys.warning("Unknown command: " + input);
        }
    };
}

void shutdownSystem() {
    logSys.info("Shutting down system...");
    delete comSocket;
}
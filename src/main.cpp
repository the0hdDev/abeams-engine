#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"
#include "thread/threadpool/threadpool.h"
#include "initalize.h"

using std::string;

void shutdownSystem();

int main()
{

    init::initialize();

    // Main loop
    logSys.info("Entering main loop");
    std::cout.clear();
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // CLI
        std::cin.get();
        std::string input{};
        std::cin >> input;
        if (input == "exit") {
            shutdownSystem();
            serverThread.join();
            return 0;
        } else if (input == "info") {
            logSys.info("Received info command");
        } else {
            logSys.warning("Unknown command: " + input);
        }
    };
}

void shutdownSystem() {
    logSys.info("Shutting down system...");
    delete comps->comSocket;
}
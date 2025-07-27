#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "io/util/logsys/logsys.h"
#include "thread/threadpool/threadpool.h"
#include "initalize.h"

using std::string;

void shutdownSystem();

components* comps = nullptr;

int main()
{

    init::initialize();
    comps = new components;

    // Main loop
    logSys.info("Entering main loop");
    std::cout.clear();
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // CLI
        std::string input{};
        std::cin >> input;
        if (input == "exit" || input == "eexit") {
            delete comps->comSocket;
            if (comps->serverThread->joinable()) {
                comps->serverThread->join();
            }
            shutdownSystem();
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
<<<<<<< HEAD
    delete components::comSocket;
=======
    delete comps;
>>>>>>> 6e0098629e83509c23b85073b537404d17951237
}
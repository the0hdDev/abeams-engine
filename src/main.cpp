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
    comps->cliInstance->printHeader();
    std::cout << "\n\n\n\n";
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // CLI
        comps->cliInstance->startCLI();


    };
}

void shutdownSystem() {
    logSys.info("Shutting down system...");
    delete comps;
    logSys.info("Shut down complete.");

}
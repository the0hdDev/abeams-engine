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
    while (true) {
        // CLI

        comps->cliInstance->startCLI();
    };
}

void shutdownSystem() {
    logSys.info("Shutting down system...");
    delete comps;
    logSys.info("Shut down complete.");

}
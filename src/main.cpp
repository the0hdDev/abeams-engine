#include "io/util/logsys/logsys.h"
#include "initalize.h"

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

#include "initialize.h"
#include "io/util/logsys/logsys.h"

components* comps = nullptr;

int main()
{
    init::initialize();

    logSys.info("Entering main loop");
    comps->cliInstance->printHeader();
    while (comps->cliInstance->isRunning()) {
        comps->cliInstance->startCLI();
    }

    delete comps;
    std::exit(0);
}

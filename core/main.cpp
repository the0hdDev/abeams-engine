#include "initialize.h"
#include "util/logsys/logsys.h"
#include "unilog/core/essentials.h"

components* comps = nullptr;


int main(int argc, char* arcv[])
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    init::initialize();

    core::currentDateTime();

    logSys.info("Entering main loop");

    while (comps->cliInstance->isRunning()) {
        comps->cliInstance->startCLI();
    }

    comps->stopRunning();
    delete comps;

    return 0;
}

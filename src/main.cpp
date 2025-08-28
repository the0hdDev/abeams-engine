#include "initialize.h"
#include "io/util/logsys/logsys.h"

components* comps = nullptr;




int main(int argc, char* arcv[])
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    init::initialize();

    logSys.info("Entering main loop");
    // comps->cliInstance->printHeader();
    // while (comps->cliInstance->isRunning()) {
    //    comps->cliInstance->startCLI();
    // }
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    comps->stopRunning();
    delete comps;

    return 0;
}

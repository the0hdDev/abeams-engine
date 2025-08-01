#include "initialize.h"
#include "io/util/logsys/logsys.h"

components* comps = nullptr;


int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
#ifdef NDEBUG
    if (!misc::utillity::isRootPrivileges()) {
        logSys.critical("Program is not running with root privileges. Please run as root / admin!");
        std::exit(2);
    }
#endif

    init::initialize();

    logSys.info("Entering main loop");
    comps->cliInstance->printHeader();
    while (comps->cliInstance->isRunning()) {
        comps->cliInstance->startCLI();
    }

    delete comps;
    std::exit(0);
}

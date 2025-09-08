#include "cli.h"
#include "cli_Implementations.h"
#include "CLIHandler/configHandler/configHandler.h"
#include "CLIHandler/simulationHandler/simulationHandler.h"


cli::cli()
{
    config::cliHandler configCLI = config::cliHandler();
    simulation::cliHandler simCLI = simulation::cliHandler();

    commandMap["help"] = printHelp;
    commandMap["version"] = printVersion;
    commandMap["shutdown"] = shutdown;
    commandMap["exit"] = shutdown;
    commandMap["poweroff"] = shutdown;
    commandMap["quit"] = shutdown;
    commandMap["restart"] = restart;
    commandMap["status"] = printStatus;
    commandMap["clear"] = clearCLI;
    // commandMap["echo"] = [](int argc, char* argv[]){  echo(argc, argv);  };
    commandMap["config"] = [&]() { configCLI.startCliHandler(); };
    commandMap["simulation"] = [&]() { simCLI.startHandler(); };
    commandMap["sim"] = [&]() { simCLI.startHandler(); };


}

void cli::startCLI()
{

}


void cli::printHeader()
{

}

void cli::stopRunning()
{

}



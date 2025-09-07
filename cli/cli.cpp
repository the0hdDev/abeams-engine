#include "cli.h"
#include "cli_Implementations.h"


cli::cli()
{
    commandMap["help"] = printHelp;
    commandMap["version"] = printVersion;
    commandMap["shutdown"] = shutdown;
    commandMap["exit"] = shutdown;
    commandMap["poweroff"] = shutdown;
    commandMap["quit"] = shutdown;
    commandMap["restart"] = restart;
    commandMap["status"] = printStatus;
    commandMap["config"] = configHandler;
    commandMap["clear"] = clearCLI;
    commandMap["echo"] = [](int argc, char* argv[]){  echo(argc, argv);  };
    commandMap["simulation"] = startCLISimulationHandler;
    commandMap["sim"] = startCLISimulationHandler;


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



#include "cli.h"
#include "cli_Implementations.h"
#include "CLIHandler/configHandler/configHandler.h"
#include "CLIHandler/simulationHandler/simulationHandler.h"


cli::cli()
{
    std::shared_ptr<config::cliHandler> configCLI = std::make_shared<config::cliHandler>();
    std::shared_ptr<simulation::cliHandler> simCLI = std::make_shared<simulation::cliHandler>();

    commandMap["help"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["version"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["shutdown"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["exit"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["poweroff"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["quit"] = [](int argc, char* argv[]) {  commands::shutdown(argc, argv); };
    commandMap["restart"] = [](int argc, char* argv[]) {  commands::restart(argc, argv); };
    commandMap["status"] = [](int argc, char* argv[]) {  commands::printStatus(argc, argv); };
    commandMap["clear"] = [](int argc, char* argv[]) {  commands::clearCLI(argc, argv); };
    commandMap["config"] = [configCLI](int argc, char* argv[]) { configCLI->startHandler(argc, argv); };
    commandMap["simulation"] = [simCLI](int argc, char* argv[]) { simCLI->startHandler(argc, argv); };
    commandMap["sim"] = [simCLI](int argc, char* argv[]) { simCLI->startHandler(argc, argv); };


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



#include "cli.h"


    static void printHelp(const std::string& input) {};
    static void printInfo(const std::string& input) {} ;
    static void shutdownSystem(const std::string& input) {};
    static void printVersion(const std::string& input, double& version) {};


cli::cli()
{
    logSys.info("cli::cli called successfully");
    commands["help"]  =   [this](const std::string& in){ printHelp(in); };
    commands["info"]  =   [this](const std::string& in){ printHelp(in); };
    commands["version"] = [this](const std::string& in){ printHelp(in); };
    // Exit Commands
    commands["exit"]  =    [this](const std::string& in){ printHelp(in); };
    commands["shutdown"]  =   [this](const std::string& in){ printHelp(in); };
    commands["poweroff"]  =   [this](const std::string& in){ printHelp(in); };







}

void cli::startCLI() {

}

void cli::printHeader() {

}
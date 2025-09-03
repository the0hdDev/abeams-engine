#include "cli.h"


    static void printHelp(const std::string& input);
    static void printInfo(const std::string& input);
    static void printVersion(const std::string& input, double& version);



cli::cli()
{
    logSys.info("cli::cli called successfully");
    commands["help"]     = [this](const std::string& in){ printHelp(in); };
    commands["info"]     = [this](const std::string& in){ printHelp(in); };
    commands["version"]  = [this](const std::string& in){ printHelp(in); };
    // Exit Commands
    commands["exit"]     = [this](const std::string& in){ printHelp(in); };
    commands["shutdown"] = [this](const std::string& in){ printHelp(in); };
    commands["poweroff"] = [this](const std::string& in){ printHelp(in); };
    logSys.info("cli constructor executed successfully");



}

void cli::startCLI() {
    logSys.info("starting cli");
    std::string input{};
    cli::printHeader();
    while (cli::running) {
        std::cout << "\n>";
        std::getline(std::cin, input);
        if (input.empty()) continue;

        if (auto it = cli::commands.find(input); it != cli::commands.end()) {
            it->second(input);
        } else {
            logSys.warning("Unknown command: " + input);
        }


    }
}

void cli::printHeader() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << logSys.GREEN << R"(

      █████╗ ██████╗  ███████╗ █████╗ ███╗   ███╗  ███████╗    ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
     ██╔══██╗██╔══██╗ ██╔════╝██╔══██╗████╗ ████║ ██╔══════╝   ██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
     ███████║██████ ║ █████╗  ███████║██╔████╔██║ ███████╗     █████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗
     ██╔══██║██╔══██║ ██╔══╝  ██╔══██║██║╚██╔╝██║ ╚══════██╗   ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝
     ██║  ██║██████╔╝ ███████╗██║  ██║██║ ╚═╝ ██║ █████████║   ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
     ╚═╝  ╚═╝╚═════╝  ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚════════╝   ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝)" << "\n";
}

void cli::stopRunning() {


    cli::running = false;
}

void printHelp(const std::string &input) {
    std::cout << R"(
        Here are some commands:
            - help --- shows you a list of commands
            - exit --- shutdown
            - shutdown --- shutdown
            - poweroff --- shutdown
            - info --- shows you general info
            - version --- shows you the version of the running program
)" << '\n';
}

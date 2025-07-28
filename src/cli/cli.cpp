//
// Created by Theo Wimber on 28.07.25.
//

#include "cli.h"
#include "../io/util/logsys/logsys.h"
#include "../io/util/logsys/logToFile.h"
#include <cstdlib>
#include <iostream>  // Für std::cout, std::cin
#include <algorithm> // Optional: für string tolower

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
std::unique_ptr<logToFile_c> logToFile = nullptr;

void cli::printHeader() {
    std::cout << Log::GREEN << R"(
     █████╗ ██████╗  ███████╗ █████╗ ███╗   ███╗  ███████╗    ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
     ██╔══██╗██╔══██╗ ██╔════╝██╔══██╗████╗ ████║ ██╔══════╝   ██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
     ███████║██████ ║ █████╗  ███████║██╔████╔██║ ███████╗     █████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗
     ██╔══██║██╔══██║ ██╔══╝  ██╔══██║██║╚██╔╝██║ ╚══════██╗   ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝
     ██║  ██║██████╔╝ ███████╗██║  ██║██║ ╚═╝ ██║ █████████║   ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
     ╚═╝  ╚═╝╚═════╝  ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚════════╝   ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
    )" << Log::RESET << std::endl;

    std::cout << Log::WHITE
              << "-------------------------------- [ Type 'help' for a list of commands. ] --------------------------------"
              << Log::RESET << std::endl;
    std::cout << "\n\n";
}

// Konstruktor
cli::cli() {
    logSys.info("Created CLI successfully");
    logToFile = std::make_unique<logToFile_c>("log/default.log");
}

// Muss definiert sein, sonst Linker Error
void cli::shutdownSystem(std::string& input) {
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
    logSys.info("Shutting down...");
    std::exit(0); // Oder Systemcalls, je nachdem
}

void cli::printHelp(std::string& input) {
    std::cout << Log::YELLOW << "Available commands:" << Log::RESET << std::endl;
    std::cout << "  help       - Show this help message" << std::endl;
    std::cout << "  info       - Show system information" << std::endl;
    std::cout << "  exit/quit/shutdown - Shutdown the system" << std::endl;
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
}

void cli::printInfo(std::string& input) {
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
    logSys.info("System information:");
}


void cli::startCLI() {
    clearConsole();

    std::string input{};
    std::cin >> input;

    // Optional: Input lowercase machen
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    if (input == "help") {
        printHelp(input);
    }
    else if (input == "info") {
        printInfo(input);
    }
    else if (input == "exit" || input == "quit" || input == "shutdown") {
        shutdownSystem(input);
    }
    else {
        logSys.warning("Unknown command: " + input);
    }
}

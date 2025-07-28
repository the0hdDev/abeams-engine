//
// Created by Theo Wimber on 28.07.25.
//

#include "cli.h"
#include "../io/util/logsys/logsys.h"
#include <cstdlib>
#include <iostream>  // Für std::cout, std::cin
#include <algorithm> // Optional: für string tolower

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

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
}

// Konstruktor
cli::cli() {
    logSys.info("Created CLI successfully");
}

// Muss definiert sein, sonst Linker Error
void cli::shutdownSystem() {
    logSys.info("Shutting down...");
    std::exit(0); // Oder Systemcalls, je nachdem
}

void cli::printHelp() {
    std::cout << Log::YELLOW << "Available commands:" << Log::RESET << std::endl;
    std::cout << "  help       - Show this help message" << std::endl;
    std::cout << "  info       - Show system information" << std::endl;
    std::cout << "  exit/quit/shutdown - Shutdown the system" << std::endl;
}

void cli::printInfo() {
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
        printHelp();
    }
    else if (input == "info") {
        printInfo();
    }
    else if (input == "exit" || input == "quit" || input == "shutdown") {
        shutdownSystem();
    }
    else {
        logSys.warning("Unknown command: " + input);
    }
}

//
// Created by Theo Wimber on 28.07.25.
//

#include "cli.h"
#include "../io/util/logsys/logsys.h"
#include "../io/util/logsys/logToFile.h"
#include <cstdlib>
#include <iostream>
#include <thread>
#include "../header/config.hpp"

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
std::unique_ptr<logToFile_c> logToFile = nullptr;

void cli::printHeader() {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    clearConsole();
    std::cout << Log::GREEN << R"(
      █████╗ ██████╗  ███████╗ █████╗ ███╗   ███╗  ███████╗    ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
     ██╔══██╗██╔══██╗ ██╔════╝██╔══██╗████╗ ████║ ██╔══════╝   ██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
     ███████║██████ ║ █████╗  ███████║██╔████╔██║ ███████╗     █████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗
     ██╔══██║██╔══██║ ██╔══╝  ██╔══██║██║╚██╔╝██║ ╚══════██╗   ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝
     ██║  ██║██████╔╝ ███████╗██║  ██║██║ ╚═╝ ██║ █████████║   ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
     ╚═╝  ╚═╝╚═════╝  ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚════════╝   ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
    )" << Log::RESET << std::endl;

    std::cout << Log::WHITE
              << "      -------------------------------- [ Type 'help' for a list of commands. ] --------------------------------"
              << Log::RESET << std::endl;
    std::cout << "\n\n";
    logToFile->writeInfo(logSys.currentDateTime(), "CLI header printed successfully");
}

// construktor
cli::cli() {
    logSys.info("Created CLI successfully");
    logToFile = std::make_unique<logToFile_c>("log/default.log");
}

void cli::shutdownSystem(const std::string& input) {
    cli::running = false;
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
    logSys.info("Shutting down...");
    // std::exit(0); // Exit syscall
}

void cli::printHelp(const std::string& input) {
    std::cout << Log::YELLOW << "Available commands:" << Log::RESET << std::endl;
    std::cout << "  help               - Show this help message" << std::endl;
    std::cout << "  info               - Show system information" << std::endl;
    std::cout << "  exit/quit/shutdown - Shutdown the system" << std::endl;
    std::cout << "  version            - Shows current version" << std::endl;
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
}

void cli::printInfo(const std::string& input) {
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
    logSys.info("System information:");
}

void cli::printVersion(const std::string& input, double& version) {
    logToFile->writeInfo(logSys.currentDateTime(), "User issued command: " + input);
    logSys.info("Current version: " + std::to_string(version));
}

void getInput(std::string& input) {

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "> ";
    std::cin >> input;
}

void cli::startCLI() {

    std::string input{};
    getInput(input);
    cli::running = true;

    if (input == "help") {
        printHelp(input);
    }
    else if (input == "info") {
        printInfo(input);
    }
    else if (input == "exit" || input == "quit" || input == "shutdown") {
        shutdownSystem(input);
    } else if (input == "version") {
        printVersion(input,  config::version); // Beispielversion
    }
    else if (input == "clear" || input == "cls") {
        clearConsole();
        logToFile->writeInfo(logSys.currentDateTime(), "Console cleared");
    }

    else {
        logSys.warning("Unknown command: " + input);
    }
}

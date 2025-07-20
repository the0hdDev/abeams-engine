#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "logToFile.h"

std::string currentDateTime();

class Log {
private:
    uint8_t LogLevel = 1; // Default to TRACE level
    logToFile_c logToFile; // persistent Logfile writer

public:
    Log() {
        std::cout << WHITE << "[INFO:] LogSys created successfully" << RESET << std::endl;
        logToFile.setLogPath("log/default.log");
    }

    ~Log() = default;

    void setLogLevel(uint8_t LogLevelSet) {
        LogLevel = LogLevelSet;
    }

    void print(const std::string& message) {
        std::cout << WHITE << message << RESET << std::endl;
    }

    void info(const std::string& msg) {
        if (LogLevel >= 0) {
            logToFile.writeInfo(currentDateTime(), msg);
            std::cout << WHITE << "[" << currentDateTime() << " | INFO:] " << msg << RESET << std::endl;
        }
    }

    void error(const std::string& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            std::cerr << RED << "[" << currentDateTime() << " | ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    void critical(const std::string& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            logToFile.writeCritical(currentDateTime(), msg);
            std::cerr << RED << "[" << currentDateTime() << " | CRITICAL ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    void severe(const std::string& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            logToFile.writeSevere(currentDateTime(), msg);
            std::cerr << RED << "[" << currentDateTime() << " | SEVERE ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    void trace(const std::string& msg) {
        if (LogLevel >= 3) {
            logToFile.writeTrace(currentDateTime(), msg);
            std::cout << BLUE << "[" << currentDateTime() << " | TRACE:] " << msg << RESET << std::endl;
        }
    }

    void debug(const std::string& msg) {
        if (LogLevel >= 1) {
            logToFile.writeDebug(currentDateTime(), msg);
            std::cout << GREEN << "[" << currentDateTime() << " | DEBUG:] " << msg << RESET << std::endl;
        }
    }

    void warning(const std::string& msg, uint16_t code = 0) {
        if (LogLevel >= 2) {
            logToFile.writeWarning(currentDateTime(), msg);
            std::cerr << YELLOW << "[" << currentDateTime() << " | WARNING:] " << msg << " Warning Code: " << code << RESET << std::endl;
        }
    }

    // Farben
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string BOLD;
    static const std::string UNDERLINE;
    static const std::string BG_CYAN;
    static const std::string WHITE;
    static const std::string RESET;
};

extern Log logSys;

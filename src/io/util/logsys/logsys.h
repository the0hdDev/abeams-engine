#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "logToFile.h"
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif

std::string currentDateTime();



class Log {
private:
    uint8_t LogLevel = 1; // Default to TRACE level
    logToFile_c logToFile; // persistent Logfile writer

public:
    std::string currentDateTime();
    Log() {
#ifdef _WIN32
        Log::enableANSIColors();
#endif
        logToFile.writeInfo(currentDateTime(), "LogSys created successfully");
        std::cout << WHITE << "[" << currentDateTime() << " | INFO:] " << "LogSys created Successfully" << RESET << std::endl;

    }

    ~Log() = default;
#ifdef _WIN32
    void enableANSIColors() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
#endif

    void setLogLevel(uint8_t LogLevelSet) {
        LogLevel = LogLevelSet;
    }
    template<typename T>
    void print(const T& message) {
        std::cout << WHITE << message << RESET << std::endl;
    }

    template<typename T>
    void info(const T& message) {
        if (LogLevel >= 0) {
            logToFile.writeInfo(currentDateTime(), message);
            std::cout << WHITE << "[" << currentDateTime() << " | INFO:] " << message << RESET << std::endl;
        }
    }

    template<typename T>
    void error(const T& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            std::cerr << RED << "[" << currentDateTime() << " | ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    template<typename T>
    void critical(const T& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            logToFile.writeCritical(currentDateTime(), msg);
            std::cerr << RED << "[" << currentDateTime() << " | CRITICAL ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    template<typename T>
    void severe(const T& msg, uint16_t code = 0) {
        if (LogLevel >= 0) {
            logToFile.writeSevere(currentDateTime(), msg);
            std::cerr << RED << "[" << currentDateTime() << " | SEVERE ERROR:] " << msg << " Error Code: " << code << RESET << std::endl;
        }
    }

    template<typename T>
    void trace(const T& msg) {
        if (LogLevel >= 3) {
            logToFile.writeTrace(currentDateTime(), msg);
            std::cout << BLUE << "[" << currentDateTime() << " | TRACE:] " << msg << RESET << std::endl;
        }
    }

    template<typename T>
    void debug(const T& msg) {
        if (LogLevel >= 1) {
            logToFile.writeDebug(currentDateTime(), msg);
            std::cout << GREEN << "[" << currentDateTime() << " | DEBUG:] " << msg << RESET << std::endl;
        }
    }

    template<typename T>
    void warning(const T& msg, uint16_t code = 0) {
        if (LogLevel >= 2) {
            if ((code != 0)) {
                logToFile.writeWarning(currentDateTime(), msg);
                std::cerr << YELLOW << "[" << currentDateTime() << " | WARNING:] " << msg << " Warning Code: " << code << RESET << std::endl;
            }
            else {
                logToFile.writeWarning(currentDateTime(), msg);
                std::cerr << YELLOW << "[" << currentDateTime() << " | WARNING:] " << msg << RESET << std::endl;
            }
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

#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <sstream>
#include "logToFile.h"
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif

static std::string currentDateTime();



class Log {
private:
    uint8_t LogLevel = 1; // Default to TRACE level
    logToFile_c logToFile; // persistent Logfile writer

public:
    static std::string currentDateTime();
    Log() {
#ifdef _WIN32
        Log::enableANSIColors();
#endif
        logToFile.writeInfo(currentDateTime(), "LogSys created successfully");
        std::cout << WHITE << "[" << currentDateTime() << " | INFO:] " << "LogSys created Successfully" << RESET;

    }

    ~Log() = default;
#ifdef _WIN32
    static void enableANSIColors() {
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
    static void print(const T& message) {
        std::cout << WHITE << message << RESET;
    }

    template<typename T>
    void info(const T& message) {
        logToFile.writeInfo(currentDateTime(), message);
        std::cout << WHITE << "\n[" << currentDateTime() << " | INFO:] " << message << RESET;

    }

    template<typename T>
    static void error(const T& msg, uint16_t code = 0) {

        std::cerr << RED << "\n[" << currentDateTime() << " | ERROR:] " << msg << " Error Code: " << code << RESET;

    }

    template<typename T>
    void critical(const T& msg, uint16_t code = 0) {
            logToFile.writeCritical(currentDateTime(), msg);
            std::cerr << RED << "\n[" << currentDateTime() << " | CRITICAL ERROR:] " << msg << " Error Code: " << code << RESET;
    }

    template<typename T>
    void severe(const T& msg, uint16_t code = 0) {
            logToFile.writeSevere(currentDateTime(), msg);
            std::cerr << RED << "\n[" << currentDateTime() << " | SEVERE ERROR:] " << msg << " Error Code: " << code << RESET;
    }

    template<typename T>
    void trace(const T& msg) {
        if (LogLevel >= 3) {
            logToFile.writeTrace(currentDateTime(), msg);
            std::cout << BLUE << "\n[" << currentDateTime() << " | TRACE:] " << msg << RESET;
        }
    }

    template<typename T>
    void debug(const T& msg) {
        if (LogLevel >= 1) {
            logToFile.writeDebug(currentDateTime(), msg);
            std::cout << GREEN << "\n[" << currentDateTime() << " | DEBUG:] " << msg << RESET;
        }
    }

    template<typename T>
    void warning(const T& msg, uint16_t code = 0) {
        if (LogLevel >= 2) {
            if ((code != 0)) {
                logToFile.writeWarning(currentDateTime(), msg);
                std::cerr << YELLOW << "\n[" << currentDateTime() << " | WARNING:] " << msg << " Warning Code: " << code << RESET;
            }
            else {
                logToFile.writeWarning(currentDateTime(), msg);
                std::cerr << YELLOW << "\n[" << currentDateTime() << " | WARNING:] " << msg << RESET;
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

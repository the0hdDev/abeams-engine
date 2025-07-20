#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "logToFile.h"

std::string currentDateTime();
class Log
{
private:
    uint8_t LogLevel = 1; // Default to TRACE level
public:
    Log() {
        std::cout << WHITE << "[INFO:] LogSys created successfully" << RESET << std::endl;
    };

    ~Log() = default;
    void setLogLevel(uint8_t LogLevelSet)
    {
        LogLevel = LogLevelSet;
    }

    void print(const std::string& message)
    {
        std::cout << WHITE << message << RESET << std::endl;
    }

    void info(const std::string& infcode)
    {
        if (LogLevel >= 0)
        {

            logToFile::writeToLogFile("skibidi.txt", "00:00", "goon");
            std::cout << WHITE << "[" << currentDateTime() <<" | INFO:] " << infcode << RESET << std::endl;
        }
    }

    void error(const std::string& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED << "[" << currentDateTime() << " | ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void critical(const std::string& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED  << "[" << currentDateTime() << " | CRITICAL ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void severe(const std::string& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED  << "[" << currentDateTime() << " | SEVERE ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void trace(const std::string& trcmsg)
    {
        if (LogLevel >= 3)
        {
            std::cout << BLUE  << "[ " << currentDateTime() << " | TRACE:] " << trcmsg << RESET << std::endl;
        }
    }

    void debug(const std::string& dbgmsg)
    {
        if (LogLevel >= 1)
        {
            std::cout << GREEN  << "[ " << currentDateTime() << " | DEBUG:] " << dbgmsg << RESET << std::endl;
        }
    }

    void warning(const std::string& warning, uint16_t warnint = 0)
    {
        if (LogLevel >= 2)
        {
            std::cerr << YELLOW  << "[ " << currentDateTime() << " | WARNING:] " << warning << " Warning Code: " << warnint << RESET << std::endl;
        }
    }

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


#pragma once
#include <iostream>
#include <string>
#include <cstdint>

template <typename T>
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

    void print(const T& message)
    {
        std::cout << WHITE << message << RESET << std::endl;
    }

    void info(const T& infcode)
    {
        if (LogLevel >= 0)
        {
            std::cout << WHITE << "[INFO:] " << infcode << RESET << std::endl;
        }
    }

    void error(const T& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED << "[ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void critical(const T& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED << "[CRITICAL ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void severe(const T& err, uint16_t errint = 0)
    {
        if (LogLevel >= 0)
        {
            std::cerr << RED << "[SEVERE ERROR:] " << err << " Error Code: " << errint << RESET << std::endl;
        }
    }

    void trace(const T& trcmsg)
    {
        if (LogLevel >= 3)
        {
            std::cout << BLUE << "[TRACE:] " << trcmsg << RESET << std::endl;
        }
    }

    void debug(const T& dbgmsg)
    {
        if (LogLevel >= 1)
        {
            std::cout << GREEN << "[DEBUG:] " << dbgmsg << RESET << std::endl;
        }
    }

    void warning(const T& warning, uint16_t warnint = 0)
    {
        if (LogLevel >= 2)
        {
            std::cerr << YELLOW << "[WARNING:] " << warning << " Warning Code: " << warnint << RESET << std::endl;
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

extern Log<std::string> logSys;


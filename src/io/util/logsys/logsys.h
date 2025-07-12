#pragma once
#include <iostream>
#include <string>
#include <cstdint>

enum class LogLevel {
    INFO, // 0
    SEVERE,  // 1
    CRITICAL, // 2
    ERROR, // 3
    WARNING, // 4
    DEBUG, // 5
    TRACE // 6
};

template <typename T>
class Log {
private:
    uint8_t LogLevel = 6; // Default to TRACE level
public:
    void setLogLevel(uint8_t& LogLevelSet) {
      LogLevel = LogLevelSet;
    }
    Log() {

    }
    ~Log() {

    }
    void print(const T& message)
    {
        std::cout << WHITE << message << RESET << std::endl;
    }

    void loginfo(const T& infcode, uint16_t errint)
    {
        if (LogLevel >= 0)
        {
            std::cout << WHITE << "[INFO:] " << infcode  << "Info Code: " << errint << RESET << std::endl;
        }
    }

    void logerr(const T& err, uint16_t errint)
    {
        if (LogLevel >= 3)
        {
            std::cerr << RED << "[ERROR:] " << err << "Error Code: " << errint << RESET << std::endl;
        }
    }

    void logcritical(const T& err, uint16_t errint)
    {
        if (LogLevel >= 2)
        {
            std::cerr << RED << "[CRITICAL ERROR:] " << err << "Error Code: " << errint << RESET<< std::endl;
        }
    }

    void logsevere(const T& err, uint16_t errint) {
        if (LogLevel >= 1)
        {
            std::cerr << RED << "[SEVERE ERROR:] " << err << "Error Code: " << errint << RESET << std::endl;
        }
    }

    void logtrace(const T& trcmsg, uint16_t dbgint) {
        if (LogLevel >= 6)
        {
            std::cout << BLUE << "[TRACE:] " << trcmsg << "Trace Code: " << dbgint << RESET << std::endl;
        }
    }

    void logdebug(const T& dbgmsg, uint16_t dbgint) {
        if (LogLevel >= 5)
        {
            std::cout << GREEN << "[DEBUG:] " << dbgmsg << "Debug Code: " << dbgint << RESET << std::endl;
        }

    }

    void logwarning(const T& warning, uint16_t warnint) {
        if (LogLevel >= 4)
        {
            std::cerr << YELLOW << "[WARNING:] " << warning << "Warning Code: " << warnint << RESET << std::endl;
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
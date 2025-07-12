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
public:
    int LogLevel = 0;

    Log() {

    }
    ~Log() {

    }
    void print(const T& message) {
        std::cout << WHITE << message << std::endl;
    }

    void loginfo(const T& infcode, uint16_t errint) {
        if (loglevel == 0) {
            std::cout << WHITE << "[INFO:] " << infcode << std::endl << "Info Code: " << errint << std::endl;
        }
    }

    void logerr(const T& err, uint16_t errint) {
        if (LogLevel <= 3) {
            std::cerr << RED << "[ERROR:] " << err << "Error Code: " << errint << std::endl;
        }

    }

    void logcritical(const T& err, uint16_t errint) {
        std::cerr << RED << "[CRITICAL ERROR:] " << err << "Error Code: " << errint << std::endl;
    }

    void logsevere(const T& err, uint16_t errint) {
        std::cerr << RED << "[SEVERE ERROR:] " << err << "Error Code: " << errint << std::endl;
    }

    void logtrace(const T& trcmsg, uint16_t dbgint) {
        std::cout << BLUE << "[TRACE:] " << trcmsg << "Trace Code: " << dbgint << std::endl;
    }

    void logdebug(const T& dbgmsg, uint16_t dbgint) {
        std::cout << YELLOW << "[DEBUG:] " << dbgmsg << "Debug Code: " << dbgint << std::endl;
    }

    void logwarning(const T& warning, uint16_t warnint) {
        std::cerr << YELLOW << "[WARNING:] " << warning << "Warning Code: " << warnint << std::endl;
    }

    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string BOLD;
    static const std::string UNDERLINE;
    static const std::string BG_CYAN;
    static const std::string WHITE;
};
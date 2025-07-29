#include "logToFile.h"
#include <iostream>
#include <utility>

logToFile_c::logToFile_c(std::string  path) : logPath(std::move(path)) {
    openLogFile();
}

logToFile_c::~logToFile_c() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void logToFile_c::openLogFile() {
    if (logFile.is_open()) logFile.close();
    logFile.open(logPath, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << logPath << std::endl;
    }
}

void logToFile_c::setLogPath(const std::string& path) {
    logPath = path;
    openLogFile();
}

void logToFile_c::writeLog(const std::string& level, const std::string& time, const std::string& message) {
    if (logFile.is_open()) {
        logFile << "[ " << time << " | " << level << ": ] " << message << std::endl;
    } else {
        std::cerr << "Log file not open!" << std::endl;
    }
}

void logToFile_c::writeInfo(const std::string& time, const std::string& message) {
    writeLog("INFO", time, message);
}

void logToFile_c::writeCritical(const std::string& time, const std::string& message) {
    writeLog("CRITICAL", time, message);
}

void logToFile_c::writeSevere(const std::string& time, const std::string& message) {
    writeLog("SEVERE", time, message);
}

void logToFile_c::writeDebug(const std::string& time, const std::string& message) {
    writeLog("DEBUG", time, message);
}

void logToFile_c::writeTrace(const std::string& time, const std::string& message) {
    writeLog("TRACE", time, message);
}

void logToFile_c::writeFatal(const std::string& time, const std::string& message) {
    writeLog("FATAL", time, message);
}

void logToFile_c::writeWarning(const std::string& time, const std::string& message) {
    writeLog("WARNING", time, message);
}

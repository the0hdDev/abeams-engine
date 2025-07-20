//
// Created by theo on 7/18/25.
//

#include "logToFile.h"

#include <iostream>

static void logToFile::writeInfoToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
    std::ofstream logFile(path);
    logFile << "[ " << time << " | " << "INFO: " << " ] " << premessage << std::endl;
}


static void logToFile::writeCriticalToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "CRITICAL: " << " ] " << premessage << std::endl;
}
static void logToFile::writeSevereToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "SEVERE: " << " ] " << premessage << std::endl;
}
static void logToFile::writeDebugToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "DEBUG: " << " ] " << premessage << std::endl;
}
static void logToFile::writeTraceToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "TRACE: " << " ] " << premessage << std::endl;
}
static void logToFile::writeFatalToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "FATAL: " << " ] " << premessage << std::endl;
}
static void logToFile::writeWarningToLogFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "WARNING: " << " ] " << premessage << std::endl;
}
static void logToFile::writeLogToFile(const std::string& path, std::string& time, std::string& premessage)
{
     std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "LOG: " << " ] " << premessage << std::endl;
}
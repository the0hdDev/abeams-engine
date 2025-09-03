#pragma once
#include <fstream>
#include <string>

class logToFile_c {
public:
    explicit logToFile_c(std::string  path = "log/default.log");
    ~logToFile_c();
    void writeLog(const std::string& level, const std::string& time, const std::string& message);
    void writeInfo(const std::string& time, const std::string& message);
    void writeCritical(const std::string& time, const std::string& message);
    void writeSevere(const std::string& time, const std::string& message);
    void writeDebug(const std::string& time, const std::string& message);
    void writeTrace(const std::string& time, const std::string& message);
    void writeFatal(const std::string& time, const std::string& message);
    void writeWarning(const std::string& time, const std::string& message);
    void setLogPath(const std::string& path);

private:
    std::ofstream logFile;
    std::string logPath;
    void openLogFile();
};

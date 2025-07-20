#pragma once
#include <fstream>
#include <string>

class logToFile {
public:
   static void writeInfoToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeErrorToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeCriticalToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeSevereToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeDebugToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeTraceToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeFatalToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeWarningToLogFile(const& std::string path, const std::string& time, const std::string& premessage);
   static void writeLogToFile(const& std::string path, const std::string& time, const std::string& premessage);
};

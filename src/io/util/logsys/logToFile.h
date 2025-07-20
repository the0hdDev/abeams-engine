#pragma once
#include <fstream>
#include <string>

class logToFile {
public:
   static void writeInfoToLogFile(const std::string path, std::string time, std::string premessage);
};

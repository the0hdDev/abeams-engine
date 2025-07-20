//
// Created by theo on 7/18/25.
//

#include "logToFile.h"

#include <iostream>

void logToFile::writeInfoToLogFile(const std::string path, std::string time, std::string premessage) {
    std::ofstream logFile(path);
    std::cout << path << std::endl;
    logFile << "[ " << time << " | " << "INFO: " << " ] " << premessage << std::endl;
}


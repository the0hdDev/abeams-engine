//
// Created by theo on 7/18/25.
//

#include "logToFile.h"


void logToFile::writeToLogFile(const std::string path, std::string time, std::string premessage) {
    std::ofstream logFile(path);
    logSys.info("Writing to log file: " + path);
    logFile << "goon";

}



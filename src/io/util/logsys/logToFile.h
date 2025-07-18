//
// Created by theo on 7/18/25.
//
#pragma once
#ifndef LOGTOFILE_H
#define LOGTOFILE_H
#include "logsys.h"
#include <fstream>
#include <string>


class logToFile {
public:
   static void writeToLogFile(const std::string path, std::string time, std::string premessage);
};



#endif //LOGTOFILE_H

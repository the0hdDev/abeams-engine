//
// Created by Theo Wimber on 11.07.25.
//
#include "logsys.h"
#include <iostream>
#include <string>


const std::string RESET   = "\033[0m";
const std::string RED     = "\033[31m";
const std::string GREEN   = "\033[32m";
const std::string YELLOW  = "\033[33m";
const std::string BLUE    = "\033[34m";
const std::string BOLD    = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string BG_CYAN = "\033[46m";


void  logsys::print(std::string& message) {
    std::cout << RED << message;
}
template<typename errstr>
void logsys::logerr(const errstr& err, uint16_t errint) {
    std::cerr << "Error Message: " << err << std::endl << "Error Code: " << errint << std::endl;
}


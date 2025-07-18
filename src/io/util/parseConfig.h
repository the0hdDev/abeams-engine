#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../../header/config.h"

class ReadConfig
{
public:
    nlohmann::json ParseConfig();
    uint32_t getPort(std::string confpath);
    uint32_t getLogLevel(std::string confpath);
private:
    std::string configPath;
};

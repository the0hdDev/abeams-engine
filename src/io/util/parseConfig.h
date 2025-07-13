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
    int getPort(std::string confpath);
    bool isDebug(std::string confpath);
private:
    std::string configPath;
};

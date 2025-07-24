#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../../header/config.hpp"

class readConfig
{
public:
    nlohmann::json parseConfig();
    void setConfPath();
    uint32_t getPort();
    uint32_t getLogLevel();
private:
    std::string configPath;
};

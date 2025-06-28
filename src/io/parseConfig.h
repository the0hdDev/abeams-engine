#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../header/config.h"

class ReadConfig {
public:

    explicit ReadConfig(const std::string& confPath);
    nlohmann::json parseConfig();
    int getPort();
    bool isDebug();




private:
    std::string configPath;
};

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../header/config.h"

class ReadConfig {
public:

    explicit ReadConfig(const std::string& confPath);


    Config parseConfig();




private:
    std::string configPath;
};

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "config.h"  // deine Config-Struktur

class ReadConfig {
public:

    explicit ReadConfig(const std::string& confPath);


    Config parseConfig();




private:
    std::string configPath;
};

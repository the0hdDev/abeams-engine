//
// Created by theow on 24.06.2025.
//

#include "parseConfig.h"

using json = nlohmann::json;



json ParseConfig(const std::string &confPath) {

    std::ifstream ifs(confPath);

    if (!ifs.is_open()) {
        std::cerr << "Cannot open config file " << confPath << std::endl;
    }

    nlohmann::json jsonConfig;

    ifs >> jsonConfig;

    if (confPath == "") {
        std::cerr << "No config file found or specified at: " << confPath << std::endl;
    }
    std::cout << "jsonconf was read" << std::endl;
    return jsonConfig;
}

int getPort(const std::string confPath) {

    json data = ParseConfig(confPath);
    int port = data["port"];
    std::cout << port << std::endl;
    return port;
}

int checkDebug(const std::string confPath) {
    json data = ParseConfig(confPath);
    bool dbgBool = data["general"]["isDebug"];
    std::cout << dbgBool << std::endl;
    return dbgBool;
}

nlohmann::json ReadConfig::ParseConfig() {
    std::ifstream ifs(configPath);

    if (!ifs.is_open()) {
        std::cerr << "Cannot open config file " << configPath << std::endl;
    }

    nlohmann::json jsonConfig;

    ifs >> jsonConfig;

    if (configPath == "") {
        std::cerr << "No config file found or specified at: " << configPath << std::endl;
    }
    std::cout << "jsonconf was read" << std::endl;
    return jsonConfig;
}
bool ReadConfig::isDebug(std::string confpath) {
    this->configPath = confpath;
    json data = ParseConfig();
    bool dbgBool = data["general"]["isDebug"];
    std::cout << dbgBool << std::endl;
    return dbgBool;
}
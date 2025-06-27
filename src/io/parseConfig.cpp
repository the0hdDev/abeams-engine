//
// Created by theow on 24.06.2025.
//

#include "parseConfig.h"

using json = nlohmann::json;

json parseConfig(const std::string &confPath) {

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

int getPort(const std::string &confPath) {

    json data = parseConfig(confPath);
    int port = data["port"];
    std::cout << port << std::endl;
    return port;
}

bool checkDebug(const std::string &confPath) {
    json data = parseConfig(confPath);
    bool dbgBool = data["isDebug"];
    std::cout << dbgBool << std::endl;
    return dbgBool;
}
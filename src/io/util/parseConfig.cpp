#include "parseConfig.h"
#include "logsys/logsys.h"
#include <fstream>

using json = nlohmann::json;

readConfig::readConfig(const std::string& path) : configPath(path) {}

json readConfig::parseConfig() {
    if (configPath.empty()) {
        logSys.error("No config path set.");
        return {};
    }

    std::ifstream ifs(configPath);
    if (!ifs.is_open()) {
        logSys.error("Cannot open config file: " + configPath);
        return {};
    }

    json configJson;
    try {
        ifs >> configJson;
    } catch (const std::exception& e) {
        logSys.error(std::string("JSON parse error: ") + e.what());
        return {};
    }

    logSys.info("Config loaded successfully from: " + configPath);
    return configJson;
}

uint32_t readConfig::getPort() {
    json data = parseConfig();
    if (data.contains("general") && data["general"].contains("communication")) {
        return data["general"]["communication"]["port"].get<uint32_t>();
    }
    logSys.error("Port not found in config.");
    return 0;
}

uint32_t readConfig::getLogLevel() {
    json data = parseConfig();
    if (data.contains("general") && data["general"].contains("logging")) {
        return data["general"]["logging"]["logLevel"].get<uint32_t>();
    }
    logSys.error("Log level not found.");
    return 0;
}

bool readConfig::isDebug() {
    json data = parseConfig();
    if (data.contains("general") && data["general"].contains("isDebug")) {
        return data["general"]["isDebug"].get<bool>();
    }

    logSys.warning("isDebug not set, defaulting to false.");
    return false;
}

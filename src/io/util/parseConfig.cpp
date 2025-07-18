#include "parseConfig.h"
#include "logsys/logsys.h"

using json = nlohmann::json;

nlohmann::json ParseConfig(const std::string confPath) {
    logSys.info("Parsing config file: " + confPath);
    std::ifstream ifs(confPath);
    nlohmann::json jsonConfig;
    if (!ifs.is_open()) {
        logSys.error("Cannot open config file " + confPath);
    }
    ifs >> jsonConfig;

    if (confPath.empty()) {
        logSys.error("No config file found or specified at: " + confPath);
    }

    logSys.info("Config was read successfully");
    return jsonConfig;
}

uint32_t getPort(const std::string confPath)
{
    json data = ParseConfig(confPath);
    uint32_t port = data["general"]["communication"]["port"];
    std::string stringPort = std::to_string(port);
    logSys.info(stringPort);
    return port;
}

int checkDebug(const std::string confPath) {
    json data = ParseConfig(confPath);
    bool dbgBool = data["general"]["isDebug"];
    std::string dbgBoolStr = std::to_string(dbgBool);
    logSys.info(dbgBoolStr);
    return dbgBool;
}

nlohmann::json ReadConfig::ParseConfig()
{
    std::ifstream ifs(configPath);
    nlohmann::json jsonConfig;
    if (!ifs.is_open())
    {
        logSys.error("Cannot open config file " + configPath);
        return 1;
    }
    ifs >> jsonConfig;

    if (configPath == "")
    {
        logSys.error("No config file found or specified at: " + configPath);
        return 404;
    }

    logSys.info("Config was read");
    return jsonConfig;
}

uint32_t ReadConfig::getLogLevel(std::string confpath) {
    this->configPath = confpath;
    json data = ParseConfig();
    uint32_t logLevel = data["general"]["logging"]["logLevel"];
    return logLevel;
}

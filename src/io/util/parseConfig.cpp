//
// Created by theow on 24.06.2025.
//

#include "parseConfig.h"
#include "logsys/logsys.h"

using json = nlohmann::json;



Log<std::string> logger2;
json ParseConfig(const std::string &confPath)
{

    nlohmann::json jsonConfig;
    std::ifstream ifs(confPath);
    ifs >> jsonConfig;


    if (!ifs.is_open())
    {
        logger2.error("Cannot open config file " + confPath, 403);
    }
    if (confPath == "")
    {
        logger2.error("No config file found or specified at: " + confPath, 404);
    }

    logger2.info("jsonconf was read");
    return jsonConfig;
}

int getPort(const std::string confPath)
{
    json data = ParseConfig(confPath);
    int port = data["port"];
    std::string stringPort = std::to_string(port);
    logger2.info(stringPort);
    return port;
}

int checkDebug(const std::string confPath) {
    json data = ParseConfig(confPath);
    bool dbgBool = data["general"]["isDebug"];
    std::string dbgBoolStr = std::to_string(dbgBool);
    logger2.info(dbgBoolStr);
    return dbgBool;
}

nlohmann::json ReadConfig::ParseConfig()
{
    std::ifstream ifs(configPath);
    nlohmann::json jsonConfig;
    if (!ifs.is_open())
    {
        logger2.error("Cannot open config file " + configPath);
    }
    ifs >> jsonConfig;

    if (configPath == "")
    {
        logger2.error("No config file found or specified at: " + configPath);
    }

    logger2.info("jsonconf was read");
    return jsonConfig;
}

bool ReadConfig::isDebug(std::string confpath) {
    this->configPath = confpath;
    json data = ParseConfig();
    bool dbgBool = data["general"]["isDebug"];
    std::string dbgBoolStr = std::to_string(dbgBool);
    logger2.info(dbgBoolStr);
    return dbgBool;
}
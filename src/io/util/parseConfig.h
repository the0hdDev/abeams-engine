#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "logsys/logsys.h"

class readConfig {
public:
    readConfig(std::string& confPath)
    {
        confPath = readConfig::configPath;
        logSys.info("Config path set to: " + confPath);
    };
    ;
    ~readConfig() {};
    explicit readConfig(const std::string& path);
    nlohmann::json parseConfig();
    uint32_t getPort();
    uint32_t getLogLevel();
    bool isDebug();

private:
    std::string configPath;
};

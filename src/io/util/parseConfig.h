#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "logsys/logsys.h"

class readConfig {
public:
    explicit readConfig(std::string& confPath)
    {
        confPath = readConfig::configPath;
        logSys.info("Config path set to: " + confPath);
    };
    ;
    ~readConfig() = default;
    explicit readConfig(std::string  path);
    nlohmann::json parseConfig();
    uint32_t getPort();
    uint32_t getLogLevel();
    bool isDebug();

private:
    std::string configPath;
};

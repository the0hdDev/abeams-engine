

#pragma once
#include <filesystem>
#include <fstream>
#include <thread>
#include "io/util/logsys/logsys.h"
#include "io/util/parseConfig.h"
#include "com/wsServer.h"
#include "thread/threadpool/threadpool.h"
#include "cli/cli.h"

extern class components* comps;

class components {
public:
    components() = default;

    ~components() {
        logSys.info("Destroying Components");
        delete conf;
        delete cliInstance;
        delete comSocket;
        delete threadpool;
        logSys.info("Components destroyed");
    }

    cli* cliInstance = nullptr;
    wsServer* comSocket = nullptr;
    std::shared_ptr<std::thread> serverThread = nullptr;
    readConfig* conf = nullptr;
    threadPool* threadpool = nullptr;
    static void stopRunning() {
        running = false;
    }
    static bool isRunning() {
        return running;
    }
    inline static bool running = true;
};

class init {
public:
    static void initialize() {
        // Init File System + Logging
        #ifdef NDEBUG
                if (!misc::utillity::isRootPrivileges()) {
                    logSys.critical("Program is not running with root privileges. Please run as root / admin!");
                    std::exit(2);
                }
        #endif

        if (!std::filesystem::exists("log/default.log")) {
            std::filesystem::create_directory("log");
            std::ofstream logFile("log/default.log");
        }
        std::ifstream configCheck("config.json");

        if (configCheck.tellg() == std::ifstream::traits_type::eof()) {
            std::ofstream configFile("config.json");
            if (!configFile.is_open()) {
                logSys.critical("Failed to create config.json file");
                return;
            }

            configFile << R"({
                "general": {
                    "communication": {
                        "port": 3405
                },
                "logging": {
                    "logLevel": 5,
                    "logFile": "app.log"
                    }
            })";
        }


        comps = new components();

        comps->conf = new readConfig("config.json");
        comps->comSocket = new wsServer(comps->conf->getPort());
        comps->threadpool = new threadPool(std::thread::hardware_concurrency());
        comps->cliInstance = new cli();
        logSys.setLogLevel(6);

        comps->serverThread = std::make_shared<std::thread>([compsPtr = comps]() {
            compsPtr->comSocket->run();
        });

        comps->serverThread->detach();
    }
};
namespace misc {
    class utillity {
        public:
            static bool isRootPrivileges() {
                #ifdef _WIN32
                    return true;
                #else
                    #include <unistd.h>
                return (geteuid() == 0);
                #endif
            }
    };

}

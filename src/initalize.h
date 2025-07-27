//
// Created by theow on 26.07.2025.
//
#pragma once
#include <filesystem>
#include <fstream>
#include <thread>
#include "io/util/logsys/logsys.h"
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include "thread/threadpool/threadpool.h"

class components {
public:
    components() = default;
    ~components() {
        delete conf;
        delete threadpool;
    }

    estbComFD* comSocket = nullptr;
    std::unique_ptr<std::thread> serverThread;
    readConfig* conf = nullptr;
    threadPool* threadpool = nullptr;
};

class init {
public:
    static void initialize() {
        // Init File System + Logging
        std::filesystem::create_directory("log");
        std::ofstream("log/default.log");

        // Init Components
        auto comps = std::make_unique<components>();

        // Variables
        uint16_t threadcount = std::thread::hardware_concurrency();

        comps->conf = new readConfig("config.json");
        comps->comSocket = new estbComFD(comps->conf->getPort());
        comps->threadpool = new threadPool(std::thread::hardware_concurrency());
        logSys.setLogLevel(6);


        comps->serverThread = std::make_unique<std::thread>([compsPtr = comps.get()]() {
            compsPtr->comSocket->run();
        });

        comps->serverThread->detach();
    }
};
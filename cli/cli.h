//
// Created by Theo Wimber on 28.07.25.
//
#pragma once
#include <string>
#include <unordered_map>
#include <functional>
#include "util/logsys/logsys.h"
#include <thread>
#include "util/logsys/logsys.h"
#include "util/logsys/logToFile.h"
#include <cstdlib>
#include <iostream>
#include <thread>
#include "util/abeams_deps/config.hpp"

class cli {
    public:
        cli();
        ~cli() = default;
        void startCLI();
        static void printHeader();
        static void stopRunning();
        inline static bool isRunning() { return running; }
    private:
        inline static bool running = true;
        std::unordered_map<std::string, std::function<void()>> commandMap;
};

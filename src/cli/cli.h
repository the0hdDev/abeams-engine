//
// Created by Theo Wimber on 28.07.25.
//
#pragma once
#include <string>
#include "../io/util/logsys/logsys.h"
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
        std::unordered_map<std::string, std::function<void(const std::string&)>> commands;
};

//
// Created by Theo Wimber on 28.07.25.
//
#pragma once
#include <string>
class cli {
    public:
        cli();
        ~cli() = default;
        void startCLI();
        static void printHeader();
        bool isRunning() const {
            return running;
        }
        inline static bool running = true;
    private:
        static void printHelp(const std::string& input);
        static void printInfo(const std::string& input);
        static void shutdownSystem(const std::string& input);
        static void printVersion(const std::string& input, double& version);
};

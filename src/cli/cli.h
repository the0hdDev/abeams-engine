//
// Created by Theo Wimber on 28.07.25.
//
#pragma once
#include <string>
class cli {
    public:
        cli();
        ~cli();
        void startCLI();
        void printHeader();
    private:
        void printHelp(std::string& input);
        void printInfo(std::string& input);
        void shutdownSystem(std::string& input);
        void printVersion(std::string& input, double& version);
        bool running = true;
};

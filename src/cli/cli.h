//
// Created by Theo Wimber on 28.07.25.
//
#pragma once
class cli {
    public:
        cli();
        ~cli();
        void startCLI();
        void printHeader();
    private:
        void printHelp();
        void printInfo();
        void shutdownSystem();
        bool running = true;
};

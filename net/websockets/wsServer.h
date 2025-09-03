#pragma once
#include <cstdint>
#include "wsHandler.h"
class wsServer {
    public:
        // Konstruktor: Port setzen (Standard 8080).
        explicit wsServer(uint16_t port = 3405);
        ~wsServer();
        void run() const;

    private:
        uint16_t port;
};
#pragma once
#include <cstdint>
#include "wsReqResHandler.h"
class estbComFD {
    public:
        // Konstruktor: Port setzen (Standard 8080).
        explicit estbComFD(uint16_t port = 3405);
        ~estbComFD();
        void run() const;

    private:
        uint16_t port;
};
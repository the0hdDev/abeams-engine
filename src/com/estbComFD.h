#pragma once
#include <cstdint>
class estbComFD {
    public:
        // Konstruktor: Port setzen (Standard 8080).
        explicit estbComFD(uint16_t port = 3405);
        ~estbComFD();
        void run() const;
    private:
        uint16_t port;
};
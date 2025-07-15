#pragma once
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket.hpp>
#include "httpReqResHandler.h"

// Einfache WebSocket-Server-Klasse mit Boost Beast.
// Benutze run(), um einen synchronen Echo-WebSocket-Server zu starten.

class estbComFD {
public:
    // Konstruktor: Port setzen (Standard 8080).
    estbComFD();
    ~estbComFD();
    explicit estbComFD(unsigned short port = 8080);

    // Startet den WebSocket-Server (blockierend, echo).
    void run();

private:
    unsigned short port_;
};
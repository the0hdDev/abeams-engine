#ifndef ESTBCOMQT_H
#define ESTBCOMQT_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdio>
#include <atomic>
#include <thread>

class estbComQT {
public:
    estbComQT();                    // Konstruktor
    ~estbComQT();                   // Destruktor

    void createServer(int port);    // Server starten
    void stopServer();              // Server stoppen

private:
    int serverSocket;               // Server-Socket-Descriptor
    std::atomic<bool> running;      // Flag, ob Server laufen soll
    std::thread serverThread;       // Thread, in dem der Server läuft
};

#endif //ESTBCOMQT_H

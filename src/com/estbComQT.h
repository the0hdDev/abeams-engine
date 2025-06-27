#ifndef ESTBCOMQT_H
#define ESTBCOMQT_H

// Plattformabhängige Includes
#ifdef _WIN32
    #include <winsock2.h>
    #include <Ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")
#else
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <unistd.h>
#endif

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
#ifdef _WIN32
    SOCKET serverSocket;            // Windows-Socket-Typ
#else
    int serverSocket;               // POSIX-Socket-Typ
#endif
    std::atomic<bool> running;      // Flag, ob Server laufen soll
    std::thread serverThread;       // Thread, in dem der Server läuft

#ifdef _WIN32
    WSADATA wsaData;                // Für WSAStartup/WSACleanup
#endif
};

#endif // ESTBCOMQT_H

#include "estbComQT.h"
#include <cstdio>      // printf, perror
#include <cstring>     // memset, strlen
#include <unistd.h>    // close()
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h> // socket functions
#include <arpa/inet.h>  // inet_ntoa()

estbComQT::estbComQT() {
    running = false;
}

void estbComQT::stopServer() {
    // Hier kannst du später clean shutdown logik bauen
}

estbComQT::~estbComQT() {
    // stopServer();
}

void estbComQT::createServer(int port) {
    // POSIX-Socket erstellen
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket failed");
        return;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(4000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed");
        close(serverSocket);
        return;
    }

    if (listen(serverSocket, SOMAXCONN) < 0) {
        perror("listen failed");
        close(serverSocket);
        return;
    }

    printf("Server is listening on port 4000\n");

    close(serverSocket);
}

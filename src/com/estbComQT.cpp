#include "estbComQT.h"
#include <cstdio>      // printf, perror
#include <cstring>     // memset, strlen
#include <iostream>
#include <unistd.h>    // close()
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h> // socket functions
#include <arpa/inet.h>  // inet_ntoa()

estbComQT::estbComQT() {
    running = false;
}

void estbComQT::stopServer() {
   // Shutdown logic
}

estbComQT::~estbComQT() {
    // stopServer();
}

void estbComQT::createServer(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket failed");
        return;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
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

    std::cout << "Server is listening on port: " << port << std::endl;

    while (true) {
        sockaddr_in clientAddress{};
        socklen_t clientLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientLen);
        if (clientSocket < 0) {
            perror("accept failed");
            break;
        }

        std::cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr) << std::endl;

        //  Com with Client Socket
        const char* msg = "Hello from server\n";
        send(clientSocket, msg, strlen(msg), 0);

    }


}

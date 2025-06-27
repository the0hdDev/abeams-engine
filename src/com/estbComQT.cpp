#include "estbComQT.h"
#include <cstdio>          // printf, perror
#include <cstring>         // memset, strlen


estbComQT::estbComQT() {
#ifdef _WIN32
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d\n", result);
    }
#endif
    running = false;
}
void estbComQT::stopServer() {

}

estbComQT::~estbComQT() {
   // stopServer();
#ifdef _WIN32
   // WSACleanup();
#endif
}



void estbComQT::createServer(int port) {
#ifdef _WIN32
    // Windows-Socket erstellen
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        printf("socket failed with error: %d\n", WSAGetLastError());
        return;
    }
#else
    // POSIX-Socket erstellen
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket failed");
        return;
    }
#endif

    // Serveradresse konfigurieren
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Binden
#ifdef _WIN32
    if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        return;
    }
#else
    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed");
        close(serverSocket);
        return;
    }
#endif

    // Lauschen
#ifdef _WIN32
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());

        return;
    }
#else
    if (listen(serverSocket, SOMAXCONN) < 0) {
        perror("listen failed");
        close(serverSocket);
        return;
    }
#endif

    printf("Server is listening on port: %d\n", port);

    // Akzeptieren
    sockaddr_in clientAddress{};
#ifdef _WIN32
    int clientLen = sizeof(clientAddress);
    SOCKET clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &clientLen);
    if (clientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());

        return;
    }
#else
    socklen_t clientLen = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientLen);
    if (clientSocket < 0) {
        perror("accept failed");
        close(serverSocket);
        return;
    }
#endif

    printf("Client connected\n");

    // Daten empfangen
    char buffer[1024] = {0};
#ifdef _WIN32
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
#else
    ssize_t bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
#endif
    if (bytesReceived > 0) {
        printf("Client handshake: %s\n", buffer);

        const char* reply = "Server rec handshake\n";
#ifdef _WIN32
        send(clientSocket, reply, (int)strlen(reply), 0);
#else
        send(clientSocket, reply, strlen(reply), 0);
#endif
    } else if (bytesReceived == 0) {
        printf("Client closed connection\n");
    } else {
#ifdef _WIN32
        printf("recv failed with error: %d\n", WSAGetLastError());
#else
        perror("recv failed");
#endif
    }

    // Sockets schließen
#ifdef _WIN32

#else

#endif

    printf("Connection closed\n");
}

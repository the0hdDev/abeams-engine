
#include "estbComQT.h"



void estbComQT::createServer(int port) {
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        perror("socket failed");
        return;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(server, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed");
        close(server);
        return;
    }

    if (listen(server, SOMAXCONN) < 0) {
        perror("listen failed");
        close(server);
        return;
    }

    printf("Server läuft auf Port %d\n", port);

    // Beispiel: eine Verbindung akzeptieren (blockiert!)
    sockaddr_in clientAddress{};
    socklen_t clientLen = sizeof(clientAddress);
    int clientSocket = accept(server, (sockaddr*)&clientAddress, &clientLen);
    if (clientSocket < 0) {
        perror("accept failed");
        close(server);
        return;
    }

    printf("Client verbunden\n");

    // Hier könntest du lesen/schreiben...

    close(clientSocket);
    close(server);
}

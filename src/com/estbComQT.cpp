#include "estbComQT.h"
#include <cstdio>          // Für printf, perror
#include <unistd.h>        // Für close()
#include <netinet/in.h>    // Für sockaddr_in
#include <sys/socket.h>    // Für socket(), bind(), listen(), accept()
#include <cstring>         // Für memset() falls du willst

void estbComQT::createServer(int port) {
    // 1) Socket erstellen
    // AF_INET = IPv4
    // SOCK_STREAM = TCP
    // 0 = Protokoll automatisch auswählen (für AF_INET + SOCK_STREAM => TCP)
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        perror("socket failed"); // Gibt Fehlermeldung aus
        return;
    }

    // 2) Serveradresse konfigurieren
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;           // IPv4
    serverAddress.sin_port = htons(port);         // Port in Netzwerk-Byte-Reihenfolge
    serverAddress.sin_addr.s_addr = INADDR_ANY;   // Auf allen Netzwerkinterfaces lauschen (0.0.0.0)

    // 3) Socket an die Adresse binden
    if (bind(server, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed"); // Z.B. wenn Port schon benutzt
        close(server);
        return;
    }

    // 4) Lauschen aktivieren (Verbindungseingang)
    if (listen(server, SOMAXCONN) < 0) {
        perror("listen failed"); // Fehler beim Übergang in den Lauschmodus
        close(server);
        return;
    }

    printf("server is listening on port: %d\n", port);

    // 5) Auf eingehende Verbindung warten
    sockaddr_in clientAddress{};              // Speichert Client-Infos (IP, Port)
    socklen_t clientLen = sizeof(clientAddress);
    int clientSocket = accept(server, (sockaddr*)&clientAddress, &clientLen);
    if (clientSocket < 0) {
        perror("accept failed"); // Z.B. wenn Verbindungsfehler auftritt
        close(server);
        return;
    }

    printf("client connected\n");

    // 6) Daten empfangen
    char buffer[1024] = {0};  // Empfangsbuffer für Daten
    ssize_t bytesReceived = read(clientSocket, buffer, sizeof(buffer) - 1);
    if (bytesReceived > 0) {
        printf("client-handshake: %s\n", buffer);

        // 7) Antwort zurückschicken
        const char* reply = "server rec handshake\n";
        send(clientSocket, reply, strlen(reply), 0);
    } else if (bytesReceived == 0) {
        printf("client closed connection\n");
    } else {
        perror("read failed");
    }


}

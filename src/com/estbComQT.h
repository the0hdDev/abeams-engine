//
// Created by theo on 6/27/25.
//

#ifndef ESTBCOMQT_H
#define ESTBCOMQT_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>



class estbComQT {
    public:
        void createServer(int port);


};



#endif //ESTBCOMQT_H

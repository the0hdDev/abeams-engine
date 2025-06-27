#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"
#include <thread>

int main() {

    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;



    int s_port = 4000;
    // bool isDebug = isDebug("mconf.json");



    // ReadConfig conf = ReadConfig("mconf.json");
    estbComQT comServer;

    std::thread serverThread([&]() {

    comServer.createServer(s_port);
    });




    return 0;


}
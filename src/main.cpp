#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"
#include <thread>

int main() {

    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;


<<<<<<< HEAD
    int s_port = 4000;
    // bool isDebug = isDebug("mconf.json");;
=======

    int s_port = 3405;
    bool running = true;
    // bool isDebug = isDebug("mconf.json");


>>>>>>> 680a2fb45fddbdf1d7bea4fb4fa584b4f19dc3eb

    // ReadConfig conf = ReadConfig("mconf.json");
    estbComQT comServer;
    std::thread serverThread([&]() {
      comServer.createServer(s_port);
    });
    serverThread.detach();

    cout << "threading working";
    while (running) {
        std::this_thread::sleep_for(std::chrono::hours(24));
    }


    return 0;

}
#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"
#include <thread>

int main() {

    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;



    int s_port = 3405;
    bool running = true;
    // bool isDebug = isDebug("mconf.json");



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
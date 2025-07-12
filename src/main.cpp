#include <iostream>
#include "io/util/parseConfig.h"
#include "com/estbComFD.h"
#include <thread>
#include "com/httpReqResHandler.h"
#include "io/util/logsys/logsys.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;




int main() {
    setupHandler();
    const uint16_t s_port = 3405;
    const string confpath = "mconf.json";
    bool running = true;
    string ip_addr = "127.0.0.1";
    ReadConfig* conf = new ReadConfig();
    bool isDebug = conf->isDebug(confpath);
    delete(conf);


    cout << isDebug << endl;

    estbComFD comServer;
    std::thread serverThread([&]() {
      comServer.createServer(s_port, ip_addr);
    });
    serverThread.detach();

    Log<string> log;

    log.logerr("normal error test", 2);
    log.logdebug("log debug test", 3);
    log.logcritical("critical test", 1);
    log.logtrace("log trace test", 4);
    log.loginfo("log info test", 5);
    log.logwarning("log warning test", 6);
    log.logsevere("log severe test", 7);

    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    };
}
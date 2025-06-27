#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"

int main() {

    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;



    int s_port = getPort();
    bool isDebug = isDebug();



    ReadConfig conf = ReadConfig("mconf.json");
    estbComQT comServer;

    comServer.createServer(s_port);





    return 0;


}
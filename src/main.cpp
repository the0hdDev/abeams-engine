#include <iostream>
#include "io/parseConfig.h"
#include "com/estbComQT.h"

int main() {

    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;


    int sport = 8080;

    ReadConfig conf = ReadConfig("mconf.json");
    estbComQT comServer;

    comServer.createServer(sport);



    return 0;


}
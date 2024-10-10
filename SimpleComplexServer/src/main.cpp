#include <iostream>
#include "simple_complex_rpg/server/server.h"

int main(int, char**){
    SimpleComplexRPG::Server::Server server = SimpleComplexRPG::Server::Server();
    server.run();
    return 0;
}

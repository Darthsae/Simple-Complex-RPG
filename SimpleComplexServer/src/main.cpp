#include <iostream>
#include "simple_complex_rpg/server/server.h"

int main(int, char**){
    boost::asio::io_context io_context;
    SimpleComplexRPG::Server::Server server(io_context, 12345);
    io_context.run();
    return 0;
}

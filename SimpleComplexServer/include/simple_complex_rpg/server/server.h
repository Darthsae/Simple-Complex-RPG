#ifndef SCRPG_SERVER_H
#define SCRPG_SERVER_H
#include <boost/asio.hpp>
#include "simple_complex_rpg/server/iserver.h"

namespace SimpleComplexRPG::Server
{
    class Server : public IServer {
    public:
        Server();
        void run();
    };
}

#endif
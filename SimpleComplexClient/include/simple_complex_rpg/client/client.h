#ifndef SCRPG_CLIENT_H
#define SCRPG_CLIENT_H
#include "simple_complex_rpg/client/iclient.h"
#include "simple_complex_rpg/server/iserver.h"

namespace SCServer = SimpleComplexRPG::Server;

namespace SimpleComplexRPG::Client
{
    class Client : public IClient {
    public:
        void deliver(const SCServer::Packet& msg) override;
    };
}

#endif
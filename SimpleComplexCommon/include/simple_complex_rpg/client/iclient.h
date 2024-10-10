#ifndef ICLIENT_H
#define ICLIENT_H
#include "simple_complex_rpg/server/iserver.h"
#include "simple_complex_rpg/server/packet.h"

#include <string>
#include <memory>

namespace SCServer = SimpleComplexRPG::Server;

namespace SimpleComplexRPG::Client {
    class IClient {
    public:
        virtual ~IClient() {}
        virtual void deliver(const SCServer::Packet& msg) = 0;
    };

    typedef std::shared_ptr<IClient> ClientPtr;
}

#endif
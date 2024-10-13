#ifndef SCRPG_SERVER_H
#define SCRPG_SERVER_H
#include <boost/asio.hpp>
#include "simple_complex_rpg/server/client_session.h"

using boost::asio::ip::tcp;

namespace SimpleComplexRPG::Server
{
    class Server {
    public:
        Server(boost::asio::io_context& io_context, int16_t port);
        void run();
    private:
        void acceptConnection();

        tcp::acceptor acceptor_;
    };
}

#endif
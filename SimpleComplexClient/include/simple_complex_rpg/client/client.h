#ifndef SCRPG_CLIENT_H
#define SCRPG_CLIENT_H
#include "simple_complex_rpg/server/packet.h"
#include <boost/asio.hpp>
#include <deque>

namespace SCServer = SimpleComplexRPG::Server;

using boost::asio::ip::tcp;

namespace SimpleComplexRPG::Client
{
    class Client {
    public:
        Client(boost::asio::io_context& io_context, tcp::resolver::results_type endpoints);

        void Write(const SCServer::Packet& message);

        void Close();

        uint8_t GetID() { return id; }

    private:
        void ConnectToServer(const tcp::resolver::results_type& endpoints);

        void ReadPacket();

        void WritePacket();

        uint8_t id = 0;

        uint64_t temp = 0;

        std::vector<uint8_t> buffer;

        tcp::socket socket_;
        uint8_t* readMsg_;
        uint32_t readHeader_;
        std::deque<SCServer::Packet> writeMessages_;
    };
}

#endif
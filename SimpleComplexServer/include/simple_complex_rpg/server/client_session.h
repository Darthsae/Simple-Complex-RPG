#ifndef CLIENT_SESSION_H
#define CLIENT_SESSION_H
#include <simple_complex_rpg/server/packet.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <memory>
#include <deque>

using boost::asio::ip::tcp;

namespace SimpleComplexRPG::Server {
    class ClientSession : public std::enable_shared_from_this<ClientSession> {
    public:
        ClientSession(tcp::socket socket);

        void Start(uint8_t id);

        void Deliver(const Packet& message);

        static std::vector<std::shared_ptr<ClientSession>> Participants;

        uint8_t GetID() { return id; }

    private:
        void ReadPacket();

        void SendPacket();

        uint8_t id = 0;

        uint64_t temp = 0;

        std::vector<uint8_t> buffer;

        tcp::socket socket_;
        uint8_t* readMsg_;
        uint32_t readHeader_;
        std::deque<Packet> writeMessages_;
    };
}
#endif
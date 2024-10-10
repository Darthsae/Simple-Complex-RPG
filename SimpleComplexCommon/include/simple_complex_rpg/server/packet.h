#ifndef PACKET_H
#define PACKET_H

namespace SimpleComplexRPG::Server {
    enum PacketID {
        INVD = -1,
        SYNC = 0,
        DELIVER = 1
    };

    struct Packet {
        int packet_id;
    };
}

#endif
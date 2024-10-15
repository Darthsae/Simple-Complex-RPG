#ifndef PACKET_H
#define PACKET_H
#include <stdint.h>
#include <vector>
#include <string>

namespace SimpleComplexRPG::Server {
    enum PacketID : uint8_t {
        INVD = 0,
        SYNC = 1,
        DELIVER = 2,
        ECHO = 3,
        QUIT = 4,
        UPDATE = 5
    };

    enum PacketVersion : uint16_t {
        V0 = 0,
        V1 = 1,
        V2 = 2
    };

    struct Packet {
        uint16_t packet_version;
        uint8_t packet_id;
        uint8_t packet_sender;

        std::vector<uint8_t> data;

        uint64_t place_holder = 0;

        uint32_t size = 0;

        Packet(uint16_t version, uint8_t id);
        Packet(uint16_t version, uint8_t* data);
        Packet(uint16_t version, std::vector<uint8_t> data);

        uint8_t* to_bytes();

        std::vector<uint8_t> to_vec();

        uint64_t get_indice();

        const static uint32_t MAX_PACKET_SIZE = 32;

        // Serialization
        void serialize(int8_t value);
        void serialize(uint8_t value);
        void serialize(int16_t value);
        void serialize(uint16_t value);
        void serialize(int32_t value);
        void serialize(uint32_t value);
        void serialize(int64_t value);
        void serialize(uint64_t value);
        void serialize(float value);
        void serialize(double value);
        void serialize(bool value);
        void serialize(std::string value);

        // Deserialization
        int8_t deserialize_int8();
        uint8_t deserialize_uint8();
        int16_t deserialize_int16();
        uint16_t deserialize_uint16();
        int32_t deserialize_int32();
        uint32_t deserialize_uint32();
        int64_t deserialize_int64();    
        uint64_t deserialize_uint64();
        float deserialize_float();
        double deserialize_double();
        bool deserialize_bool();
        std::string deserialize_string();
    };

    template<typename T>
    struct IPacketSerializable {
        virtual void serialize(Packet& packet) = 0;
        virtual T deserialize(const Packet& packet) = 0;
    };
}

#endif
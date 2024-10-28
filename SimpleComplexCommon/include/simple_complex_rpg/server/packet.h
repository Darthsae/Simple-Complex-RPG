/**
 * @file packet.h
 * @brief Defines the Packet structure and related enums for managing network packets in the SimpleComplexRPG Server.
 */

#ifndef PACKET_H
#define PACKET_H
#include <stdint.h>
#include <vector>
#include <string>

/**
 * @namespace SimpleComplexRPG::Server
 * @brief Contains all server-related networking structures and definitions for SimpleComplexRPG.
 */
namespace SimpleComplexRPG::Server {
    /**
     * @enum PacketID
     * @brief Represents unique identifiers for various packet types.
     *
     * Each packet type represents a distinct message or action within the server-client protocol.
     */
    enum PacketID : uint8_t {
        INVD = 0,   ///< Invalid packet.
        SYNC = 1,   ///< Synchronization packet.
        DELIVER = 2,///< Packet for delivering data.
        ECHO = 3,   ///< Packet used for echoing messages.
        QUIT = 4,   ///< Packet indicating a quit action.
        UPDATE = 5  ///< Packet indicating an update action.
    };

    /**
     * @enum PacketVersion
     * @brief Specifies the version of the packet format.
     */
    enum PacketVersion : uint16_t {
        V0 = 0, ///< Version 0.
        V1 = 1, ///< Version 1.
        V2 = 2  ///< Version 2.
    };

    /**
     * @struct Packet
     * @brief Represents a network packet for communication in the server.
     *
     * This structure encapsulates the data required for sending and receiving packets within the network,
     * including serialization and deserialization methods for various data types.
     */
    struct Packet {
        uint16_t packetVersion; ///< The version of the packet format.
        uint8_t packetID; ///< The identifier for the type of packet.
        uint8_t packetSender; ///< The ID of the packet's sender.

        std::vector<uint8_t> data; ///< The data payload of the packet.

        uint64_t placeHolder = 0; ///< Reserved placeholder for future use.

        uint32_t size = 0; ///< The size of the packet data.

        /**
         * @brief Constructs a Packet with specified version and ID.
         * @param version The packet version.
         * @param id The packet ID.
         */
        Packet(uint16_t version, uint8_t id);

        /**
         * @brief Constructs a Packet with specified version and data array.
         * @param version The packet version.
         * @param data Pointer to the data array.
         */
        Packet(uint16_t version, uint8_t* data);

        /**
         * @brief Constructs a Packet with specified version and data vector.
         * @param version The packet version.
         * @param data The data vector.
         */
        Packet(uint16_t version, std::vector<uint8_t> data);

        /**
         * @brief Converts the packet to a byte array.
         * @return A pointer to the byte array representing the packet.
         */
        uint8_t* ToBytes();

        /**
         * @brief Converts the packet to a vector of bytes.
         * @return A vector of bytes representing the packet.
         */
        std::vector<uint8_t> ToVec();

        /**
         * @brief Retrieves a unique index for the packet.
         * @return The unique index as a uint64_t.
         */
        uint64_t GetIndice();

        const static uint32_t MAX_PACKET_SIZE = 32; ///< Maximum allowable packet size in bytes.

        // Serialization Methods

        /**
         * @brief Serializes an int8_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(int8_t value);

        /**
         * @brief Serializes a uint8_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(uint8_t value);

        /**
         * @brief Serializes an int16_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(int16_t value);

        /**
         * @brief Serializes a uint16_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(uint16_t value);

        /**
         * @brief Serializes an int32_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(int32_t value);

        /**
         * @brief Serializes a uint32_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(uint32_t value);

        /**
         * @brief Serializes an int64_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(int64_t value);

        /**
         * @brief Serializes a uint64_t value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(uint64_t value);

        /**
         * @brief Serializes a float value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(float value);

        /**
         * @brief Serializes a double value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(double value);

        /**
         * @brief Serializes a boolean value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(bool value);

        /**
         * @brief Serializes a string value into the packet.
         * @param value The value to serialize.
         */
        void Serialize(std::string value);

        // Deserialization

        /**
         * @brief Deserializes an int8_t value from the packet.
         * @return The deserialized int8_t value.
         */
        int8_t DeserializeInt8();

        /**
         * @brief Deserializes a uint8_t value from the packet.
         * @return The deserialized uint8_t value.
         */
        uint8_t DeserializeUInt8();

        /**
         * @brief Deserializes an int16_t value from the packet.
         * @return The deserialized int16_t value.
         */
        int16_t DeserializeInt16();

        /**
         * @brief Deserializes a uint16_t value from the packet.
         * @return The deserialized uint16_t value.
         */
        uint16_t DeserializeUInt16();

        /**
         * @brief Deserializes an int32_t value from the packet.
         * @return The deserialized int32_t value.
         */
        int32_t DeserializeInt32();

        /**
         * @brief Deserializes a uint32_t value from the packet.
         * @return The deserialized uint32_t value.
         */
        uint32_t DeserializeUInt32();

        /**
         * @brief Deserializes an int64_t value from the packet.
         * @return The deserialized int64_t value.
         */
        int64_t DeserializeInt64();    

        /**
         * @brief Deserializes a uint64_t value from the packet.
         * @return The deserialized uint64_t value.
         */
        uint64_t DeserializeUInt64();

        /**
         * @brief Deserializes a float value from the packet.
         * @return The deserialized float value.
         */
        float DeserializeFloat();

        /**
         * @brief Deserializes a double value from the packet.
         * @return The deserialized double value.
         */
        double DeserializeDouble();

        /**
         * @brief Deserializes a boolean value from the packet.
         * @return The deserialized boolean value.
         */
        bool DeserializeBool();

        /**
         * @brief Deserializes a string value from the packet.
         * @return The deserialized string value.
         */
        std::string DeserializeString();
    };

    /**
     * @struct IPacketSerializable
     * @brief Interface for classes that can be serialized into a Packet.
     *
     * Provides methods for serializing a class into a Packet and deserializing a Packet into an instance of the class.
     * @tparam T The type that implements this interface.
     */
    template<typename T>
    struct IPacketSerializable {
        /**
         * @brief Serializes an instance of the class into a packet.
         * @param packet The packet to serialize data into.
         */
        virtual void Serialize(Packet& packet) = 0;

        /**
         * @brief Deserializes a packet into an instance of the class.
         * @param packet The packet to deserialize data from.
         * @return An instance of the class.
         */
        virtual T Deserialize(const Packet& packet) = 0;
    };
}

#endif

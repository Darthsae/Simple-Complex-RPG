#include "simple_complex_rpg/server/packet.h"
#include <algorithm>
#include <iostream>

using namespace SimpleComplexRPG::Server;

Packet::Packet(uint16_t version, uint8_t id) {
    packetVersion = version;
    packetID = id;
    packetSender = 0;
    data = {};
}

Packet::Packet(uint16_t version, uint8_t* data) {
    if (data == nullptr || sizeof(data) < 4) {
        std::cout << "Invalid packet of size " << sizeof(data) << std::endl;
        return;
    }
    else if ((uint16_t)((((uint16_t)data[0]) << 8) | data[1]) != version) {
        std::cout << "Version mismatch (Expected, Received), (" << (int)version << " != " << (int)((uint16_t)((((uint16_t)data[0]) << 8) | data[1])) << ")" << std::endl;
        return;
    }

    packetVersion = version;

    packetID = data[2];

    packetSender = data[3];

    for (int i = 0; i < sizeof(data) - 4; i++) {
        this->data.emplace_back(data[4 + i]);
    }
}

Packet::Packet(uint16_t version, std::vector<uint8_t> data) {
    if (data.size() < 4) {
        std::cout << "Invalid packet of size " << data.size() << std::endl;
        return;
    }
    else if ((uint16_t)((((uint16_t)data[0]) << 8) | data[1]) != version) {
        std::cout << "Version mismatch (Expected, Received), (" << (int)version << " != " << (int)((uint16_t)((((uint16_t)data[0]) << 8) | data[1])) << ")" << std::endl;
        return;
    }

    packetVersion = version;

    packetID = data[2];

    packetSender = data[3];

    for (int i = 0; i < data.size() - 4; i++) {
        this->data.emplace_back(data[4 + i]);
    }
}

uint8_t* Packet::ToBytes()
{
    uint8_t* bytes = new uint8_t[4 + data.size()];
    bytes[0] = (uint8_t)(packetVersion >> 8);
    bytes[1] = (uint8_t)packetVersion;

    bytes[2] = packetID;

    bytes[3] = packetSender;

    for (int i = 0; i < data.size(); i++) {
        bytes[4 + i] = data[i];
    }
    
    return bytes;
}

std::vector<uint8_t> Packet::ToVec() {
    std::vector<uint8_t> vec;
    vec.push_back((uint8_t)(packetVersion >> 8));
    vec.push_back((uint8_t)packetVersion);
    vec.push_back(packetID);
    vec.push_back(packetSender);
    for (int i = 0; i < data.size(); i++) {
        vec.push_back(data[i]);
    }
    return vec;
}

uint64_t Packet::GetIndice(){
    return (int)(placeHolder / 8);
}


// Serialization

void Packet::Serialize(int8_t value) {
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(uint8_t value) {
    data.emplace_back(value);
}

void Packet::Serialize(int16_t value) {
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(uint16_t value) {
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(int32_t value) {
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(uint32_t value) {
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(int64_t value) {
    data.emplace_back((uint8_t)(value >> 56));
    data.emplace_back((uint8_t)(value >> 48));
    data.emplace_back((uint8_t)(value >> 40));
    data.emplace_back((uint8_t)(value >> 32));
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}   

void Packet::Serialize(uint64_t value) {
    data.emplace_back((uint8_t)(value >> 56));
    data.emplace_back((uint8_t)(value >> 48));
    data.emplace_back((uint8_t)(value >> 40));
    data.emplace_back((uint8_t)(value >> 32));
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(float value) {
    Serialize(*(uint32_t*)&value);
}

void Packet::Serialize(double value) {
    Serialize(*(uint64_t*)&value);
}

void Packet::Serialize(bool value) {    
    data.emplace_back((uint8_t)value);
}

void Packet::Serialize(std::string value) {
    data.push_back((uint8_t)value.size());
    for (int i = 0; i < value.size(); i++) {
        data.push_back((uint8_t)value[i]);
    }
}


// Deserialization

int8_t Packet::DeserializeInt8() {
    uint8_t value = data[0];
    data.erase(data.begin());
    return value;
}

uint8_t Packet::DeserializeUInt8() {
    uint8_t value = data[0];
    data.erase(data.begin());
    return value;
}

int16_t Packet::DeserializeInt16() {
    int16_t value = ((int16_t)data[0] << 8) | data[1];
    data.erase(data.begin(), data.begin() + 2);
    return value;
}

uint16_t Packet::DeserializeUInt16() {
    uint16_t value = ((uint16_t)data[0] << 8) | data[1];
    data.erase(data.begin(), data.begin() + 2);
    return value;
}

int32_t Packet::DeserializeInt32() {    
    int32_t value = ((int32_t)data[0] << 24) | ((int32_t)data[1] << 16) | ((int32_t)data[2] << 8) | data[3];
    data.erase(data.begin(), data.begin() + 4);
    return value;
}

uint32_t Packet::DeserializeUInt32() {
    uint32_t value = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
    data.erase(data.begin(), data.begin() + 4);
    return value;
}

int64_t Packet::DeserializeInt64() {
    int64_t value = ((uint64_t)data[0] << 56) | ((uint64_t)data[1] << 48) | ((uint64_t)data[2] << 40) | ((uint64_t)data[3] << 32) | ((uint64_t)data[4] << 24) | ((uint64_t)data[5]) << 16 | ((uint64_t)data[6] << 8) | data[7];
    data.erase(data.begin(), data.begin() + 8);
    return value;
}

uint64_t Packet::DeserializeUInt64() {
    uint64_t value = ((uint64_t)data[0] << 56) | ((uint64_t)data[1] << 48) | ((uint64_t)data[2] << 40) | ((uint64_t)data[3] << 32) | ((uint64_t)data[4] << 24) | ((uint64_t)data[5]) << 16 | ((uint64_t)data[6] << 8) | data[7];
    data.erase(data.begin(), data.begin() + 8);
    return value;
}

float Packet::DeserializeFloat() {
    uint32_t value = DeserializeUInt32();
    return *(float*)&value;
}

double Packet::DeserializeDouble() {
    uint64_t value = DeserializeUInt64();
    return *(double*)&value;
}

bool Packet::DeserializeBool() {
    bool value = data[0];
    data.erase(data.begin());
    return value;
}

std::string Packet::DeserializeString() {
    uint8_t size = data[0];
    std::cout << "Size of string: " << size << "/" << (data.size() - 1) << std::endl;
    data.erase(data.begin());
    std::string value;
    for (int i = 0; i < size; i++) {
        std::cout << "Charracter at " << i << " is " << (int)data[0] << std::endl;
        value += (char)data[0];
        data.erase(data.begin());
    }
    return value;
}
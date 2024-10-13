#include "simple_complex_rpg/server/packet.h"
#include <algorithm>
#include <iostream>

using namespace SimpleComplexRPG::Server;

Packet::Packet(uint16_t version, uint8_t id) {
    packet_version = version;
    packet_id = id;
    packet_sender = 0;
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

    packet_version = version;

    packet_id = data[2];

    packet_sender = data[3];

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

    packet_version = version;

    packet_id = data[2];

    packet_sender = data[3];

    for (int i = 0; i < data.size() - 4; i++) {
        this->data.emplace_back(data[4 + i]);
    }
}

uint8_t* Packet::to_bytes()
{
    uint8_t* bytes = new uint8_t[4 + data.size()];
    bytes[0] = (uint8_t)(packet_version >> 8);
    bytes[1] = (uint8_t)packet_version;

    bytes[2] = packet_id;

    bytes[3] = packet_sender;

    for (int i = 0; i < data.size(); i++) {
        bytes[4 + i] = data[i];
    }
    
    return bytes;
}

std::vector<uint8_t> Packet::to_vec() {
    std::vector<uint8_t> vec;
    vec.push_back((uint8_t)(packet_version >> 8));
    vec.push_back((uint8_t)packet_version);
    vec.push_back(packet_id);
    vec.push_back(packet_sender);
    for (int i = 0; i < data.size(); i++) {
        vec.push_back(data[i]);
    }
    return vec;
}

uint64_t Packet::get_indice(){
    return (int)(place_holder / 8);
}


// Serialization

void Packet::serialize(int8_t value) {
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(uint8_t value) {
    data.emplace_back(value);
}

void Packet::serialize(int16_t value) {
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(uint16_t value) {
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(int32_t value) {
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(uint32_t value) {
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(int64_t value) {
    data.emplace_back((uint8_t)(value >> 56));
    data.emplace_back((uint8_t)(value >> 48));
    data.emplace_back((uint8_t)(value >> 40));
    data.emplace_back((uint8_t)(value >> 32));
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}   

void Packet::serialize(uint64_t value) {
    data.emplace_back((uint8_t)(value >> 56));
    data.emplace_back((uint8_t)(value >> 48));
    data.emplace_back((uint8_t)(value >> 40));
    data.emplace_back((uint8_t)(value >> 32));
    data.emplace_back((uint8_t)(value >> 24));
    data.emplace_back((uint8_t)(value >> 16));
    data.emplace_back((uint8_t)(value >> 8));
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(float value) {
    serialize(*(uint32_t*)&value);
}

void Packet::serialize(double value) {
    serialize(*(uint64_t*)&value);
}

void Packet::serialize(bool value) {    
    data.emplace_back((uint8_t)value);
}

void Packet::serialize(std::string value) {
    data.push_back((uint8_t)value.size());
    for (int i = 0; i < value.size(); i++) {
        data.push_back((uint8_t)value[i]);
    }
}


// Deserialization

int8_t Packet::deserialize_int8() {
    uint8_t value = data[0];
    data.erase(data.begin());
    return value;
}

uint8_t Packet::deserialize_uint8() {
    uint8_t value = data[0];
    data.erase(data.begin());
    return value;
}

int16_t Packet::deserialize_int16() {
    int16_t value = ((int16_t)data[0] << 8) | data[1];
    data.erase(data.begin(), data.begin() + 2);
    return value;
}

uint16_t Packet::deserialize_uint16() {
    uint16_t value = ((uint16_t)data[0] << 8) | data[1];
    data.erase(data.begin(), data.begin() + 2);
    return value;
}

int32_t Packet::deserialize_int32() {    
    int32_t value = ((int32_t)data[0] << 24) | ((int32_t)data[1] << 16) | ((int32_t)data[2] << 8) | data[3];
    data.erase(data.begin(), data.begin() + 4);
    return value;
}

uint32_t Packet::deserialize_uint32() {
    uint32_t value = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
    data.erase(data.begin(), data.begin() + 4);
    return value;
}

int64_t Packet::deserialize_int64() {
    int64_t value = ((uint64_t)data[0] << 56) | ((uint64_t)data[1] << 48) | ((uint64_t)data[2] << 40) | ((uint64_t)data[3] << 32) | ((uint64_t)data[4] << 24) | ((uint64_t)data[5]) << 16 | ((uint64_t)data[6] << 8) | data[7];
    data.erase(data.begin(), data.begin() + 8);
    return value;
}

uint64_t Packet::deserialize_uint64() {
    uint64_t value = ((uint64_t)data[0] << 56) | ((uint64_t)data[1] << 48) | ((uint64_t)data[2] << 40) | ((uint64_t)data[3] << 32) | ((uint64_t)data[4] << 24) | ((uint64_t)data[5]) << 16 | ((uint64_t)data[6] << 8) | data[7];
    data.erase(data.begin(), data.begin() + 8);
    return value;
}

float Packet::deserialize_float() {
    uint32_t value = deserialize_uint32();
    return *(float*)&value;
}

double Packet::deserialize_double() {
    uint64_t value = deserialize_uint64();
    return *(double*)&value;
}

bool Packet::deserialize_bool() {
    bool value = data[0];
    data.erase(data.begin());
    return value;
}

std::string Packet::deserialize_string() {
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
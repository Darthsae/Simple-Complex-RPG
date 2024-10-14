#include "dei_voluntas/data/vec.h"
#include <cmath>

using namespace DeiVoluntas::Data;

#pragma region Vec2f
Vec2f::Vec2f(float x, float y) : x(x), y(y) {}

const Vec2f Vec2f::ZERO = Vec2f(0.0f, 0.0f);
const Vec2f Vec2f::UNIT_X = Vec2f(1.0f, 0.0f);
const Vec2f Vec2f::UNIT_Y = Vec2f(0.0f, 1.0f);

Vec2f Vec2f::operator+(const Vec2f &other) const {
    return Vec2f(x + other.x, y + other.y);
}

Vec2f Vec2f::operator-(const Vec2f &other) const {
    return Vec2f(x - other.x, y - other.y);
}

Vec2f Vec2f::operator*(const Vec2f &other) const {
    return Vec2f(x * other.x, y * other.y);
}

float Vec2f::Dot(const Vec2f &other) const {
    return x * other.x + y * other.y;
}

Vec2f Vec2f::operator*(const float &other) const {
    return Vec2f(x * other, y * other);
}

Vec2f Vec2f::operator/(const float &other) const {
    return Vec2f(x / other, y / other);
}

Vec2f &Vec2f::operator+=(const Vec2f &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2f &Vec2f::operator-=(const Vec2f &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2f &Vec2f::operator*=(const Vec2f &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2f &Vec2f::operator*=(const float &other) {
    x *= other;
    y *= other;
    return *this;
}

Vec2f &Vec2f::operator/=(const float &other) {
    x /= other;
    y /= other;
    return *this;
}

bool Vec2f::operator==(const Vec2f &other) const {
    return x == other.x && y == other.y;
}

float Vec2f::Magnitude() const {
    return sqrtf(x * x + y * y);
}

Vec2f Vec2f::Normalize() const {
    float magnitude = Magnitude();
    if (magnitude == 0.0f) {
        return Vec2f(0.0f, 0.0f);
    }
    return Vec2f(x, y) / magnitude;
}
#pragma endregion

#pragma region Vec2i
Vec2i::Vec2i(int x, int y) : x(x), y(y) {}

const Vec2i Vec2i::ZERO = Vec2i(0, 0);
const Vec2i Vec2i::UNIT_X = Vec2i(1, 0);
const Vec2i Vec2i::UNIT_Y = Vec2i(0, 1);

Vec2i Vec2i::operator+(const Vec2i &other) const {
    return Vec2i(x + other.x, y + other.y);
}

Vec2i Vec2i::operator-(const Vec2i &other) const {
    return Vec2i(x - other.x, y - other.y);
}

Vec2i Vec2i::operator*(const Vec2i &other) const {
    return Vec2i(x * other.x, y * other.y);
}

int Vec2i::Dot(const Vec2i &other) const {
    return x * other.x + y * other.y;
}

Vec2i Vec2i::operator*(const int &other) const {
    return Vec2i(x * other, y * other);
}

Vec2i Vec2i::operator/(const int &other) const {
    return Vec2i(x / other, y / other);
}

Vec2i &Vec2i::operator+=(const Vec2i &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2i &Vec2i::operator-=(const Vec2i &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2i &Vec2i::operator*=(const Vec2i &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2i &Vec2i::operator*=(const int &other) {
    x *= other;
    y *= other;

    return *this;
}

Vec2i &Vec2i::operator/=(const int &other) {
    x /= other;
    y /= other;
    return *this;
}

bool Vec2i::operator==(const Vec2i &other) const {
    return x == other.x && y == other.y;
}

int Vec2i::Magnitude() const {
    return (int)(sqrt(x * x + y * y) + 0.5f);
}

Vec2i Vec2i::Normalize() const {
    int magnitude = Magnitude();
    if (magnitude == 0) {
        return Vec2i(0, 0);
    }
    return Vec2i(x, y) / magnitude;
}
#pragma endregion

#pragma region Vec2d
Vec2d::Vec2d(double x, double y) : x(x), y(y) {}

const Vec2d Vec2d::ZERO = Vec2d(0.0, 0.0);
const Vec2d Vec2d::UNIT_X = Vec2d(1.0, 0.0);
const Vec2d Vec2d::UNIT_Y = Vec2d(0.0, 1.0);

Vec2d Vec2d::operator+(const Vec2d &other) const {
    return Vec2d(x + other.x, y + other.y);
}

Vec2d Vec2d::operator-(const Vec2d &other) const {
    return Vec2d(x - other.x, y - other.y);
}

Vec2d Vec2d::operator*(const Vec2d &other) const {
    return Vec2d(x * other.x, y * other.y);
}

double Vec2d::Dot(const Vec2d &other) const {
    return x * other.x + y * other.y;
}

Vec2d Vec2d::operator*(const double &other) const {
    return Vec2d(x * other, y * other);
}

Vec2d Vec2d::operator/(const double &other) const {
    return Vec2d(x / other, y / other);
}

Vec2d &Vec2d::operator+=(const Vec2d &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2d &Vec2d::operator-=(const Vec2d &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2d &Vec2d::operator*=(const Vec2d &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2d &Vec2d::operator*=(const double &other) {
    x *= other;
    y *= other;
    return *this;
}

Vec2d &Vec2d::operator/=(const double &other) {
    x /= other;
    y /= other;
    return *this;
}

bool Vec2d::operator==(const Vec2d &other) const {
    return x == other.x && y == other.y;
}

double Vec2d::Magnitude() const {
    return sqrt(x * x + y * y);
}

Vec2d Vec2d::Normalize() const {
    double magnitude = Magnitude();
    if (magnitude == 0) {
        return Vec2d(0, 0);
    }
    return Vec2d(x, y) / magnitude;
}
#pragma endregion

#pragma region Vec3f
Vec3f::Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}

const Vec3f Vec3f::ZERO = Vec3f(0.0f, 0.0f, 0.0f);
const Vec3f Vec3f::UNIT_X = Vec3f(1.0f, 0.0f, 0.0f);
const Vec3f Vec3f::UNIT_Y = Vec3f(0.0f, 1.0f, 0.0f);
const Vec3f Vec3f::UNIT_Z = Vec3f(0.0f, 0.0f, 1.0f);
#pragma endregion

#pragma region Vec3i
Vec3i::Vec3i(int x, int y, int z) : x(x), y(y), z(z) {}

const Vec3i Vec3i::ZERO = Vec3i(0, 0, 0);
const Vec3i Vec3i::UNIT_X = Vec3i(1, 0, 0);
const Vec3i Vec3i::UNIT_Y = Vec3i(0, 1, 0);
const Vec3i Vec3i::UNIT_Z = Vec3i(0, 0, 1);
#pragma endregion

#pragma region Vec3d
Vec3d::Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}

const Vec3d Vec3d::ZERO = Vec3d(0.0, 0.0, 0.0);
const Vec3d Vec3d::UNIT_X = Vec3d(1.0, 0.0, 0.0);
const Vec3d Vec3d::UNIT_Y = Vec3d(0.0, 1.0, 0.0);
const Vec3d Vec3d::UNIT_Z = Vec3d(0.0, 0.0, 1.0);
#pragma endregion
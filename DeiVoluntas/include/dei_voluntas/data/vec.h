#ifndef VEC_H
#define VEC_H

namespace DeiVoluntas::Data {
    struct Vec2f {
        Vec2f() = default;
        Vec2f(float x, float y);

        float x;
        float y;

        const static Vec2f ZERO;
        const static Vec2f UNIT_X;
        const static Vec2f UNIT_Y;

        Vec2f operator+(const Vec2f& other) const;
        Vec2f operator-(const Vec2f& other) const;
        Vec2f operator*(const Vec2f& other) const;
        float Dot(const Vec2f& other) const;

        Vec2f operator*(const float& other) const;
        Vec2f operator/(const float& other) const;

        Vec2f& operator+=(const Vec2f& other);
        Vec2f& operator-=(const Vec2f& other);
        Vec2f& operator*=(const Vec2f& other);

        Vec2f& operator*=(const float& other);
        Vec2f& operator/=(const float& other);

        bool operator==(const Vec2f& other) const;

        float Magnitude() const;
        Vec2f Normalize() const;

        Vec2f VectorTo(const Vec2f& other) const;
    };

    struct Vec2i {
        Vec2i() = default;
        Vec2i(int x, int y);

        int x;
        int y;

        const static Vec2i ZERO;
        const static Vec2i UNIT_X;
        const static Vec2i UNIT_Y;

        Vec2i operator+(const Vec2i& other) const;
        Vec2i operator-(const Vec2i& other) const;
        Vec2i operator*(const Vec2i& other) const;
        int Dot(const Vec2i& other) const;

        Vec2i operator*(const int& other) const;
        Vec2i operator/(const int& other) const;
        
        Vec2i& operator+=(const Vec2i& other);
        Vec2i& operator-=(const Vec2i& other);
        Vec2i& operator*=(const Vec2i& other);

        Vec2i& operator*=(const int& other);
        Vec2i& operator/=(const int& other);

        bool operator==(const Vec2i& other) const;

        int Magnitude() const;
        Vec2i Normalize() const;
    };

    struct Vec2d {
        Vec2d() = default;
        Vec2d(double x, double y);

        double x;
        double y;

        const static Vec2d ZERO;
        const static Vec2d UNIT_X;
        const static Vec2d UNIT_Y;

        Vec2d operator+(const Vec2d& other) const;
        Vec2d operator-(const Vec2d& other) const;
        Vec2d operator*(const Vec2d& other) const;
        double Dot(const Vec2d& other) const;

        Vec2d operator*(const double& other) const;
        Vec2d operator/(const double& other) const;
        
        Vec2d& operator+=(const Vec2d& other);
        Vec2d& operator-=(const Vec2d& other);
        Vec2d& operator*=(const Vec2d& other);

        Vec2d& operator*=(const double& other);
        Vec2d& operator/=(const double& other);

        bool operator==(const Vec2d& other) const;

        double Magnitude() const;
        Vec2d Normalize() const;
    };

    struct Vec3f {
        Vec3f() = default;
        Vec3f(float x, float y, float z);

        float x;
        float y;
        float z;

        const static Vec3f ZERO;
        const static Vec3f UNIT_X;
        const static Vec3f UNIT_Y;
        const static Vec3f UNIT_Z;
    };

    struct Vec3i {
        Vec3i() = default;
        Vec3i(int x, int y, int z);

        int x;
        int y;
        int z;

        const static Vec3i ZERO;
        const static Vec3i UNIT_X;
        const static Vec3i UNIT_Y;
        const static Vec3i UNIT_Z;
    };

    struct Vec3d {
        Vec3d() = default;
        Vec3d(double x, double y, double z);

        double x;
        double y;
        double z;

        const static Vec3d ZERO;
        const static Vec3d UNIT_X;
        const static Vec3d UNIT_Y;
        const static Vec3d UNIT_Z;
    };
}

#endif
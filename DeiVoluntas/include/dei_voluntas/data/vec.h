/**
 * @file vec.h
 * @brief Defines vector structures for 2D and 3D coordinates with various data types (float, int, double).
 *
 * Contains Vec2f, Vec2i, Vec2d, Vec3f, Vec3i, and Vec3d structures to represent vectors in 2D and 3D space,
 * along with common vector operations.
 */

#ifndef VEC_H
#define VEC_H

/**
 * @namespace DeiVoluntas::Data
 * @brief Contains data structures and utilities for the DeiVoluntas game engine.
 */
namespace DeiVoluntas::Data {

    /**
     * @struct Vec2f
     * @brief Represents a 2D vector with float components.
     */
    struct Vec2f {
        Vec2f() = default;
        
        /**
         * @brief Constructs a Vec2f with given x and y values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Vec2f(float x, float y);

        float x; ///< X-coordinate.
        float y; ///< Y-coordinate.

        static const Vec2f ZERO;   ///< Zero vector (0, 0).
        static const Vec2f UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2f UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2f UNIT_XY;///< Unit vector in the X and Y directions (1, 1).

        Vec2f operator+(const Vec2f& other) const; ///< Adds two Vec2f vectors.
        Vec2f operator-(const Vec2f& other) const; ///< Subtracts two Vec2f vectors.
        Vec2f operator*(const Vec2f& other) const; ///< Multiplies two Vec2f vectors.
        float Dot(const Vec2f& other) const;       ///< Computes the dot product with another Vec2f.

        Vec2f operator*(const float& other) const; ///< Multiplies vector by a scalar.
        Vec2f operator/(const float& other) const; ///< Divides vector by a scalar.

        Vec2f& operator+=(const Vec2f& other); ///< Adds another Vec2f to this vector.
        Vec2f& operator-=(const Vec2f& other); ///< Subtracts another Vec2f from this vector.
        Vec2f& operator*=(const Vec2f& other); ///< Multiplies this vector by another Vec2f.

        Vec2f& operator*=(const float& other); ///< Multiplies this vector by a scalar.
        Vec2f& operator/=(const float& other); ///< Divides this vector by a scalar.

        bool operator==(const Vec2f& other) const; ///< Checks if two Vec2f vectors are equal.

        float Magnitude() const;       ///< Computes the magnitude (length) of the vector.
        Vec2f Normalize() const;       ///< Returns a normalized version of the vector.
        Vec2f VectorTo(const Vec2f& other) const; ///< Returns a vector from this to another Vec2f.
    };

    /**
     * @struct Vec2i
     * @brief Represents a 2D vector with integer components.
     */
    struct Vec2i {
        Vec2i() = default;

        /**
         * @brief Constructs a Vec2i with given x and y values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Vec2i(int x, int y);

        int x; ///< X-coordinate.
        int y; ///< Y-coordinate.

        static const Vec2i ZERO;   ///< Zero vector (0, 0).
        static const Vec2i UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2i UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2i UNIT_XY;///< Unit vector in the X and Y directions (1, 1).

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

        int Magnitude() const;   ///< Computes the magnitude (length) of the vector.
        Vec2i Normalize() const; ///< Returns a normalized version of the vector.
        Vec2i VectorTo(const Vec2i& other) const; ///< Returns a vector from this to another Vec2i.
    };

    /**
     * @struct Vec2d
     * @brief Represents a 2D vector with double components.
     */
    struct Vec2d {
        Vec2d() = default;

        /**
         * @brief Constructs a Vec2d with given x and y values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Vec2d(double x, double y);

        double x; ///< X-coordinate.
        double y; ///< Y-coordinate.

        static const Vec2d ZERO;   ///< Zero vector (0, 0).
        static const Vec2d UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2d UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2d UNIT_XY;///< Unit vector in the X and Y directions (1, 1).

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

        double Magnitude() const; ///< Computes the magnitude (length) of the vector.
        Vec2d Normalize() const;  ///< Returns a normalized version of the vector.
        Vec2d VectorTo(const Vec2d& other) const; ///< Returns a vector from this to another Vec2d.
    };

    /**
     * @struct Vec3f
     * @brief Represents a 3D vector with float components.
     */
    struct Vec3f {
        Vec3f() = default;

        /**
         * @brief Constructs a Vec3f with given x, y, and z values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         * @param z The z-coordinate.
         */
        Vec3f(float x, float y, float z);

        float x; ///< X-coordinate.
        float y; ///< Y-coordinate.
        float z; ///< Z-coordinate.

        static const Vec3f ZERO;   ///< Zero vector (0, 0, 0).
        static const Vec3f UNIT_X; ///< Unit vector in the X direction (1, 0, 0).
        static const Vec3f UNIT_Y; ///< Unit vector in the Y direction (0, 1, 0).
        static const Vec3f UNIT_Z; ///< Unit vector in the Z direction (0, 0, 1).
        static const Vec3f UNIT_XY; ///< Unit vector in the X and Y directions (1, 1, 0).
        static const Vec3f UNIT_XZ; ///< Unit vector in the X and Z directions (1, 0, 1).
        static const Vec3f UNIT_YZ; ///< Unit vector in the Y and Z directions (0, 1, 1).
        static const Vec3f UNIT_XYZ; ///< Unit vector in the X, Y, and Z directions (1, 1, 1).
    };

    /**
     * @struct Vec3i
     * @brief Represents a 3D vector with integer components.
     */
    struct Vec3i {
        Vec3i() = default;

        /**
         * @brief Constructs a Vec3i with given x, y, and z values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         * @param z The z-coordinate.
         */
        Vec3i(int x, int y, int z);

        int x; ///< X-coordinate.
        int y; ///< Y-coordinate.
        int z; ///< Z-coordinate.

        static const Vec3i ZERO;   ///< Zero vector (0, 0, 0).
        static const Vec3i UNIT_X; ///< Unit vector in the X direction (1, 0, 0).
        static const Vec3i UNIT_Y; ///< Unit vector in the Y direction (0, 1, 0).
        static const Vec3i UNIT_Z; ///< Unit vector in the Z direction (0, 0, 1).
        static const Vec3i UNIT_XY; ///< Unit vector in the X and Y directions (1, 1, 0).
        static const Vec3i UNIT_XZ; ///< Unit vector in the X and Z directions (1, 0, 1).
        static const Vec3i UNIT_YZ; ///< Unit vector in the Y and Z directions (0, 1, 1).
        static const Vec3i UNIT_XYZ; ///< Unit vector in the X, Y, and Z directions (1, 1, 1).
    };

    /**
     * @struct Vec3d
     * @brief Represents a 3D vector with double components.
     */
    struct Vec3d {
        Vec3d() = default;

        /**
         * @brief Constructs a Vec3d with given x, y, and z values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         * @param z The z-coordinate.
         */
        Vec3d(double x, double y, double z);

        double x; ///< X-coordinate.
        double y; ///< Y-coordinate.
        double z; ///< Z-coordinate.

        static const Vec3d ZERO;   ///< Zero vector (0, 0, 0).
        static const Vec3d UNIT_X; ///< Unit vector in the X direction (1, 0, 0).
        static const Vec3d UNIT_Y; ///< Unit vector in the Y direction (0, 1, 0).
        static const Vec3d UNIT_Z; ///< Unit vector in the Z direction (0, 0, 1).
        static const Vec3d UNIT_XY; ///< Unit vector in the X and Y directions (1, 1, 0).
        static const Vec3d UNIT_XZ; ///< Unit vector in the X and Z directions (1, 0, 1).
        static const Vec3d UNIT_YZ; ///< Unit vector in the Y and Z directions (0, 1, 1).
        static const Vec3d UNIT_XYZ; ///< Unit vector in the X, Y, and Z directions (1, 1, 1).
    };
}

#endif
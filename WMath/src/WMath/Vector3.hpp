#pragma once

#include <string>
#include "WMath/Utils.hpp"

namespace WMath
{
    class Vector2;
    
    class Vector3
    {
    public:
        static Vector3 Zero();
        static Vector3 One();

        static Vector3 Up();
        static Vector3 Down();
        static Vector3 Left();
        static Vector3 Right();
        static Vector3 Forward();
        static Vector3 Back();

        float x;
        float y;
        float z;

        Vector3();
        Vector3(float value);
        Vector3(float x, float y, float z);
        Vector3(const Vector2& vec2, float z = 0);
        Vector3(const Vector3& other);
        Vector3(Vector3&& other) noexcept;

        ~Vector3();

        Vector3& operator=(const Vector2& other);
        Vector3& operator=(const Vector3& other);
        Vector3& operator=(Vector3&& other) noexcept;

        float operator[](int i) const;

        int operator<=>(const Vector3& other) const;

        bool operator==(const Vector3& other) const;

        bool operator!=(const Vector3& other) const;

        Vector3 operator+(const Vector3& other) const;

        Vector3& operator+=(const Vector3& other);

        Vector3 operator-(const Vector3& other) const;

        Vector3& operator-=(const Vector3& other);

        Vector3 operator*(const float scalar) const;

        Vector3& operator*=(const float scalar);

        Vector3 operator*(const Vector3& other) const;

        Vector3& operator*=(const Vector3& other);

        Vector3 operator/(const float scalar) const;

        Vector3& operator/=(const float scalar);

        Vector3 operator/(const Vector3& other) const;

        Vector3& operator/=(const Vector3& other);

        bool Equals(const Vector3& other, float epsilon = Epsilon) const;

        float Magnitude() const;

        float Length() const;

        float MagnitudeSquared() const;

        float LengthSquared() const;

        Vector3 Normalized() const;

        void Normalize();

        std::string ToString() const;

        static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

        static float Distance(const Vector3& lhs, const Vector3& rhs);

        static float Dot(const Vector3& lhs, const Vector3& rhs);

        static Vector3 Lerp(const Vector3& start, const Vector3& end, float t);

        static Vector3 Slerp(const Vector3& start, const Vector3& end, float t);
    };

    inline bool Equals(const Vector3& lhs, const Vector3& rhs, float epsilon = Epsilon);

    inline Vector3 operator*(const float scalar, const Vector3& vector);

    inline Vector3 operator/(const float scalar, const Vector3& vector);
}

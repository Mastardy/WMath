#pragma once

#include <string>
#include "WMath/Utils.hpp"

namespace WMath
{
    class Vector2
    {
    public:
        static Vector2 Zero() { return {0, 0}; }
        static Vector2 One() { return {1, 1}; }

        static Vector2 Up() { return {0, 1}; }
        static Vector2 Down() { return {0, -1}; }
        static Vector2 Left() { return {-1, 0}; }
        static Vector2 Right() { return {1, 0}; }
        
        float x;
        float y;

        Vector2() : x(0), y(0) {}
        Vector2(float value) : x(value), y(value) {}
        Vector2(float x, float y) : x(x), y(y) {}
        Vector2(const Vector2& other) = default;
        Vector2(Vector2&& other) noexcept : x(other.x), y(other.y)
        {
            other.x = 0;
            other.y = 0;
        }
        
        ~Vector2() = default;

        Vector2& operator=(const Vector2& other)
        {
            if(this == &other) return *this;
            
            x = other.x;
            y = other.y;

            return *this;
        }
        Vector2& operator=(Vector2&& other) noexcept
        {
            if(this == &other) return *this;
            
            x = other.x;
            y = other.y;
            other.x = 0;
            other.y = 0;

            return *this;
        }

        float operator[](int i) const
        {
            if(i == 0) return x;
            if(i == 1) return y;
            return 0;
        }

        int operator<=>(const Vector2& other) const
        {
            if(WMath::Equals(MagnitudeSquared(), other.MagnitudeSquared())) return 0;
            return MagnitudeSquared() < other.MagnitudeSquared() ? -1 : 1;
        }
        bool operator==(const Vector2& other) const
        {
            return Equals(other);
        }
        bool operator!=(const Vector2& other) const
        {
            return !Equals(other);
        }

        Vector2 operator+(const Vector2& other) const
        {
            return {x + other.x, y + other.y};
        }
        Vector2& operator+=(const Vector2& other)
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        Vector2 operator-(const Vector2& other) const
        {
            return {x - other.x, y - other.y};
        }
        Vector2& operator-=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }

        Vector2 operator*(const float other) const
        {
            return {x * other, y * other};
        }
        Vector2& operator*=(const float other)
        {
            x *= other;
            y *= other;

            return *this;
        }
        Vector2 operator*(const Vector2& other) const
        {
            return {x * other.x, y * other.y};
        }
        Vector2& operator*=(const Vector2& other)
        {
            x *= other.x;
            y *= other.y;

            return *this;
        }

        Vector2 operator/(const float scalar) const
        {
            return {x / scalar, y / scalar};
        }
        Vector2& operator/=(const float scalar)
        {
            x /= scalar;
            y /= scalar;

            return *this;
        }
        Vector2 operator/(const Vector2& other) const
        {
            return {x / other.x, y / other.y};
        }
        Vector2& operator/=(const Vector2& other)
        {
            x /= other.x;
            y /= other.y;

            return *this;
        }

        bool Equals(const Vector2& other, float epsilon = Epsilon) const
        {
            return WMath::Equals(x, other.x, epsilon) && WMath::Equals(y, other.y, epsilon);
        }
        
        float Magnitude() const
        {
            return Sqrt(x * x + y * y);
        }
        float Length() const
        {
            return Magnitude();
        }

        float MagnitudeSquared() const
        {
            return x * x + y * y;
        }
        float LengthSquared() const
        {
            return MagnitudeSquared();
        }

        Vector2 Normalized() const
        {
            const float magnitude = Magnitude();
            return {x / magnitude, y / magnitude};
        }
        void Normalize()
        {
            const float magnitude = Magnitude();
            x /= magnitude;
            y /= magnitude;
        }
        
        std::string ToString() const
        {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }

        static float Angle(const Vector2& lhs, const Vector2& rhs)
        {
            const float dot = Clamp(Dot(lhs.Normalized(), rhs.Normalized()), -1, 1);
            const float angle = Acos(dot) * Rad2Deg;
            if(Cross(lhs, rhs) < 0) return -angle;
            return angle;
        }
        static float AbsAngle(const Vector2& lhs, const Vector2& rhs)
        {
            const float dot = Clamp(Dot(lhs.Normalized(), rhs.Normalized()), -1, 1);
            return Acos(dot) * Rad2Deg;
        }
        static float Cross(const Vector2& lhs, const Vector2& rhs)
        {
            return lhs.x * rhs.y - lhs.y * rhs.x;
        }
        static float Distance(const Vector2& lhs, const Vector2& rhs)
        {
            return (lhs - rhs).Magnitude();
        }
        static float Dot(const Vector2& lhs, const Vector2& rhs)
        {
            return lhs.x * rhs.x + lhs.y * rhs.y;
        }
        static Vector2 Lerp(const Vector2& start, const Vector2& end, float time)
        {
            return start + (end - start) * time;
        }
        static Vector2 Scale(const Vector2& inVector, const Vector2& scalarVector)
        {
            return { inVector.x * scalarVector.x, inVector.y * scalarVector.y };
        }
        static Vector2 Slerp(const Vector2& start, const Vector2& end, float time)
        {
            const float dot = Clamp(Dot(start, end), -1, 1);
            const float theta = Acos(dot) * time;
            const Vector2 relativeVec = end - start * dot;
            
            return start * Cos(theta) + relativeVec * Sin(theta);
        }
    };
    
    inline bool Equals(const Vector2& lhs, const Vector2& rhs, float epsilon = Epsilon)
    {
        return Equals(lhs.x, rhs.x, epsilon) && Equals(lhs.y, rhs.y, epsilon);
    }

    inline Vector2 operator*(const float scalar, const Vector2& vector)
    {
        return vector * scalar;
    }
    inline Vector2 operator/(const float scalar, const Vector2& vector)
    {
        return { scalar / vector.x, scalar / vector.y };
    }
}
#include "WMath/Vector3.hpp"
#include "WMath/Vector2.hpp"

namespace WMath
{
    Vector3 Vector3::Zero()
    {
        return {0, 0, 0};
    }

    Vector3 Vector3::One()
    {
        return {1, 1, 1};
    }

    Vector3 Vector3::Up()
    {
        return {0, 1, 0};
    }

    Vector3 Vector3::Down()
    {
        return {0, -1, 0};
    }

    Vector3 Vector3::Left()
    {
        return {-1, 0, 0};
    }

    Vector3 Vector3::Right()
    {
        return {1, 0, 0};
    }

    Vector3 Vector3::Forward()
    {
        return {0, 0, 1};
    }

    Vector3 Vector3::Back()
    {
        return {0, 0, -1};
    }

    Vector3::Vector3(): x(0), y(0), z(0) {}

    Vector3::Vector3(float value): x(value), y(value), z(value) {}

    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

    Vector3::Vector3(const Vector2& vec2, float z): x(vec2.x), y(vec2.y), z(z) {}

    Vector3::Vector3(const Vector3& other) = default;

    Vector3::Vector3(Vector3&& other) noexcept: x(other.x), y(other.y), z(other.z)
    {
        other.x = 0;
        other.y = 0;
        other.z = 0;
    }

    Vector3::~Vector3() = default;

    Vector3& Vector3::operator=(const Vector2& other)
    {
        x = other.x;
        y = other.y;
        z = 0;

        return *this;
    }

    Vector3& Vector3::operator=(const Vector3& other) = default;

    Vector3& Vector3::operator=(Vector3&& other) noexcept
    {
        if(this == &other) return *this;
            
        x = other.x;
        y = other.y;
        z = other.z;
        other.x = 0;
        other.y = 0;
        other.z = 0;

        return *this;
    }

    float Vector3::operator[](int i) const
    {
        if(i == 0) return x;
        if(i == 1) return y;
        if(i == 2) return z;
        return 0;
    }

    int Vector3::operator<=>(const Vector3& other) const
    {
        if(WMath::Equals(MagnitudeSquared(), other.MagnitudeSquared())) return 0;
        return MagnitudeSquared() < other.MagnitudeSquared() ? -1 : 1;
    }

    bool Vector3::operator==(const Vector3& other) const
    {
        return Equals(other);
    }

    bool Vector3::operator!=(const Vector3& other) const
    {
        return !Equals(other);
    }

    Vector3 Vector3::operator+(const Vector3& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3& Vector3::operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    Vector3 Vector3::operator-(const Vector3& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3& Vector3::operator-=(const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    Vector3 Vector3::operator*(const float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3& Vector3::operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    Vector3 Vector3::operator*(const Vector3& other) const
    {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector3& Vector3::operator*=(const Vector3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;

        return *this;
    }

    Vector3 Vector3::operator/(const float scalar) const
    {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3& Vector3::operator/=(const float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

    Vector3 Vector3::operator/(const Vector3& other) const
    {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vector3& Vector3::operator/=(const Vector3& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;

        return *this;
    }

    bool Vector3::Equals(const Vector3& other, float epsilon) const
    {
        return WMath::Equals(x, other.x) && WMath::Equals(y, other.y) && WMath::Equals(z, other.z);
    }

    float Vector3::Magnitude() const
    {
        return Sqrt(x * x + y * y + z * z);
    }

    float Vector3::Length() const
    {
        return Magnitude();
    }

    float Vector3::MagnitudeSquared() const
    {
        return x * x + y * y + z * z;
    }

    float Vector3::LengthSquared() const
    {
        return MagnitudeSquared();
    }

    Vector3 Vector3::Normalized() const
    {
        float mag = Magnitude();
        return {x / mag, y / mag, z / mag};
    }

    void Vector3::Normalize()
    {
        float mag = Magnitude();
        x /= mag;
        y /= mag;
        z /= mag;
    }

    std::string Vector3::ToString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
    {
        return {lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x};
    }

    float Vector3::Distance(const Vector3& lhs, const Vector3& rhs)
    {
        return (lhs - rhs).Magnitude();
    }

    float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    Vector3 Vector3::Lerp(const Vector3& start, const Vector3& end, float t)
    {
        return start + (end - start) * t;
    }

    Vector3 Vector3::Slerp(const Vector3& start, const Vector3& end, float t)
    {
        auto dot = Clamp(Dot(start.Normalized(), end.Normalized()), -1, 1);
        auto theta = Acos(dot) * t;
        auto relativeVec = (end - start * dot).Normalized();
        return ((start * Cos(theta)) + (relativeVec * Sin(theta)));
    }

    bool Equals(const Vector3& lhs, const Vector3& rhs, float epsilon)
    {
        return (lhs.x - rhs.x) < epsilon && (lhs.y - rhs.y) < epsilon && (lhs.z - rhs.z) < epsilon;
    }

    Vector3 operator*(const float scalar, const Vector3& vector)
    {
        return vector * scalar;
    }

    Vector3 operator/(const float scalar, const Vector3& vector)
    {
        return { scalar / vector.x, scalar / vector.y, scalar / vector.z};
    }
}

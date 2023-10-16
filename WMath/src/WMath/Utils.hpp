#pragma once

#include <cmath>

namespace WMath
{
    constexpr float PI = static_cast<float>(3.14159265358979323846);
    constexpr float HalfPI = static_cast<float>(1.57079632679489661923);
    constexpr float QuarterPI = static_cast<float>(0.785398163397448309616);
    constexpr float InvPI = static_cast<float>(0.318309886183790671538);
    constexpr float Deg2Rad = static_cast<float>(3.14159265358979323846 / 180.0);
    constexpr float Rad2Deg = static_cast<float>(180.0 / 3.14159265358979323846);
    constexpr float Epsilon = FLT_EPSILON;

    float Abs(float number);

    int Abs(int number);

    float Acos(float number);

    float Asin(float number);

    float Atan(float number);

    float Atan2(float y, float x);

    float Ceil(float number);

    int CeilToInt(float number);

    float Clamp(float value, float min, float max);

    float Clamp01(float value);

    float Cos(float number);

    bool Equals(float a, float b, float epsilon = Epsilon);

    float Exp(float number);

    float Floor(float number);

    int FloorToInt(float number);

    float InvLerp(float start, float end, float value);

    float Lerp(float start, float end, float value);

    float Ln(float number);

    float Log(float number, float base);

    float Log10(float number);

    template <typename T>
    T Max(const T& a, const T& b);

    template <typename T>
    T Max(std::initializer_list<T> numbers);

    template <typename T>
    T Min(const T& a, const T& b);

    template <typename T>
    T Min(std::initializer_list<T> numbers);

    float Sign(float number);

    int Sign(int number);

    float MoveTowards(float current, float target, float maxDelta);

    float Pow(float number, float power);

    float Round(float number);

    int RoundToInt(float number);

    float Sin(float number);
    
    float SmoothStep(float start, float end, float value);
    
    float Sqrt(float number);
    
    float Tan(float number);

    float ToDegrees(float radians);
    
    float ToRadians(float degrees);
}

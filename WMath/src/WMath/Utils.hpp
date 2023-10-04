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

    inline float Abs(float number)
    {
        return fabs(number);
    }

    inline int Abs(int number)
    {
        return abs(number);
    }

    inline float Acos(float number)
    {
        return acosf(number);
    }

    inline float Asin(float number)
    {
        return asinf(number);
    }

    inline float Atan(float number)
    {
        return atanf(number);
    }

    inline float Atan2(float y, float x)
    {
        return atan2f(y, x);
    }

    inline float Ceil(float number)
    {
        return ceilf(number);
    }

    inline int CeilToInt(float number)
    {
        return static_cast<int>(ceilf(number));
    }

    inline float Clamp(float value, float min, float max)
    {
        return value < min ? min : value > max ? max : value;
    }

    inline float Clamp01(float value)
    {
        return Clamp(value, 0, 1);
    }

    inline float Cos(float number)
    {
        return cosf(number);
    }

    inline bool Equals(float a, float b, float epsilon = Epsilon)
    {
        return Abs(a - b) <= epsilon;
    }
    
    inline float Exp(float number)
    {
        return expf(number);
    }

    inline float Floor(float number)
    {
        return floorf(number);
    }

    inline int FloorToInt(float number)
    {
        return static_cast<int>(floorf(number));
    }

    inline float InvLerp(float start, float end, float value)
    {
        return (value - start) / (end - start);
    }

    inline float Lerp(float start, float end, float value)
    {
        return start + (end - start) * value;
    }

    inline float Ln(float number)
    {
        return logf(number);
    }

    inline float Log(float number, float base)
    {
        return logf(number) / logf(base);
    }

    inline float Log10(float number)
    {
        return log10f(number);
    }

    template<typename T>
    inline T Max(const T& a, const T& b)
    {
        return a > b ? a : b;
    }

    template<typename T>
    inline T Max(std::initializer_list<T> numbers)
    {
        return std::max(numbers);
    }
    
    template<typename T>
    inline T Min(const T& a, const T& b)
    {
        return a < b ? a : b;
    }

    template<typename T>
    inline T Min(std::initializer_list<T> numbers)
    {
        return std::min(numbers);
    }

    inline float Sign(float number)
    {
        return number > 0.0f ? 1.0f : number < 0.0f ? -1.0f : 0;
    }

    inline int Sign(int number)
    {
        return number > 0 ? 1 : number < 0 ? -1 : 0;
    }

    inline float MoveTowards(float current, float target, float maxDelta)
    {
        if (Abs(target - current) <= maxDelta) return target;
        
        return current + Sign(target - current) * maxDelta;
    }

    inline float Pow(float number, float power)
    {
        return powf(number, power);
    }

    inline float Round(float number)
    {
        return roundf(number);
    }

    inline int RoundToInt(float number)
    {
        return static_cast<int>(roundf(number));
    }

    inline float Sin(float number)
    {
        return sinf(number);
    }

    inline float SmoothStep(float start, float end, float value)
    {
        const float x = Clamp01((value - start) / (end - start));
        return x * x * (3 - 2 * x);
    }
    
    inline float Sqrt(float number)
    {
        return sqrtf(number);
    }

    inline float Tan(float number)
    {
        return tanf(number);
    }

    inline float ToDegrees(float radians)
    {
        return radians * Rad2Deg;
    }

    inline float ToRadians(float degrees)
    {
        return degrees * Deg2Rad;
    }
}
#include "Utils.hpp"

namespace WMath
{
    float Abs(float number)
    {
        return fabs(number);
    }

    int Abs(int number)
    {
        return abs(number);
    }

    float Acos(float number)
    {
        return acosf(number);
    }

    float Asin(float number)
    {
        return asinf(number);
    }

    float Atan(float number)
    {
        return atanf(number);
    }

    float Atan2(float y, float x)
    {
        return atan2f(y, x);
    }

    float Ceil(float number)
    {
        return ceilf(number);
    }

    int CeilToInt(float number)
    {
        return static_cast<int>(ceilf(number));
    }

    float Clamp(float value, float min, float max)
    {
        return value < min ? min : value > max ? max : value;
    }

    float Clamp01(float value)
    {
        return Clamp(value, 0, 1);
    }

    float Cos(float number)
    {
        return cosf(number);
    }

    bool Equals(float a, float b, float epsilon)
    {
        return Abs(a - b) <= epsilon;
    }

    float Exp(float number)
    {
        return expf(number);
    }

    float Floor(float number)
    {
        return floorf(number);
    }

    int FloorToInt(float number)
    {
        return static_cast<int>(floorf(number));
    }

    float InvLerp(float start, float end, float value)
    {
        return (value - start) / (end - start);
    }

    float Lerp(float start, float end, float value)
    {
        return start + (end - start) * value;
    }

    float Ln(float number)
    {
        return logf(number);
    }

    float Log(float number, float base)
    {
        return logf(number) / logf(base);
    }

    float Log10(float number)
    {
        return log10f(number);
    }

    template <typename T>
    T Max(const T& a, const T& b)
    {
        return a > b ? a : b;
    }

    template <typename T>
    T Max(std::initializer_list<T> numbers)
    {
        return std::max(numbers);
    }

    template <typename T>
    T Min(const T& a, const T& b)
    {
        return a < b ? a : b;
    }

    template <typename T>
    T Min(std::initializer_list<T> numbers)
    {
        return std::min(numbers);
    }

    float Sign(float number)
    {
        return number > 0.0f ? 1.0f : number < 0.0f ? -1.0f : 0;
    }

    int Sign(int number)
    {
        return number > 0 ? 1 : number < 0 ? -1 : 0;
    }

    float MoveTowards(float current, float target, float maxDelta)
    {
        if (Abs(target - current) <= maxDelta) return target;

        return current + Sign(target - current) * maxDelta;
    }

    float Pow(float number, float power)
    {
        return powf(number, power);
    }

    float Round(float number)
    {
        return roundf(number);
    }

    int RoundToInt(float number)
    {
        return static_cast<int>(roundf(number));
    }

    float Sin(float number)
    {
        return sinf(number);
    }

    float SmoothStep(float start, float end, float value)
    {
        const float x = Clamp01((value - start) / (end - start));
        return x * x * (3 - 2 * x);
    }

    float Sqrt(float number)
    {
        return sqrtf(number);
    }

    float Tan(float number)
    {
        return tanf(number);
    }

    float ToDegrees(float radians)
    {
        return radians * Rad2Deg;
    }

    float ToRadians(float degrees)
    {
        return degrees * Deg2Rad;
    }
}

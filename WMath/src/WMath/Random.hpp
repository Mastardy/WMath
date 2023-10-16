#pragma once

#include "FastNoiseLite.h"

#include "WMath/Vector2.hpp"
#include "WMath/Vector3.hpp"
#include "WSTL/containers/Map.hpp"

#include <random>

namespace WMath
{
    class Random
    {
    private:
        typedef std::mt19937_64 Generator;
        typedef unsigned long long SeedType;
        
    public:
        static void Seed(SeedType seed);

        static SeedType GetSeed();

        static void SetNoiseSeed(int seed);

        static int GetNoiseSeed();

        static int GetValue(int min, int max);

        static float GetValue(float min, float max);

        template<typename T>
        static T GetValue(T min, T max);

        static Vector2 GetVector2(float min, float max);

        static Vector3 GetVector3(float min, float max);

        static float GetNoise(float x, float y);

        static float GetNoise(float x, float y, float z);

    private:
        static inline WSTL::Map<SeedType, Generator> generators = WSTL::Map<SeedType, Generator>();
        static inline SeedType currentSeed = 0;
        static inline int noiseSeed = 0;
        static inline FastNoiseLite noise;
    };
}

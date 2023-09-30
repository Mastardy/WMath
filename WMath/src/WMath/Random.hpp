#pragma once

#include "FastNoiseLite.h"

#include "WSTL/Types.hpp"
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
        static void Seed(SeedType seed)
        {
            currentSeed = seed;
            if(generators.ContainsKey(seed)) return;

            generators[seed] = Generator(seed);
        }

        static SeedType GetSeed()
        {
            return currentSeed;
        }

        static void SetNoiseSeed(int seed)
        {
            noiseSeed = seed;
            noise.SetSeed(seed);
        }

        static int GetNoiseSeed()
        {
            return noiseSeed;
        }

        static int GetValue(int min, int max)
        {
            std::uniform_int_distribution distribution(min, max);
            return distribution(generators[currentSeed]);
        }

        template<typename T>
        static T GetValue(T min, T max)
        {
            std::uniform_real_distribution<T> distribution(min, max);
            return distribution(generators[currentSeed]);
        }

        static float GetNoise(float x, float y)
        {
            noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
            return noise.GetNoise(x, y);
        }

        static float GetNoise(float x, float y, float z)
        {
            noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
            return noise.GetNoise(x, y, z);
        }
        
    private:
        static inline WSTL::Map<SeedType, Generator> generators = WSTL::Map<SeedType, Generator>();
        static inline SeedType currentSeed = 0;
        static inline int noiseSeed = 0;
        static inline FastNoiseLite noise;
    };
}

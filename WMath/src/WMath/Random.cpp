#include "Random.hpp"

void WMath::Random::Seed(SeedType seed)
{
    currentSeed = seed;
    if(generators.ContainsKey(seed)) return;

    generators[seed] = Generator(seed);
}

WMath::Random::SeedType WMath::Random::GetSeed()
{
    return currentSeed;
}

void WMath::Random::SetNoiseSeed(int seed)
{
    noiseSeed = seed;
    noise.SetSeed(seed);
}

int WMath::Random::GetNoiseSeed()
{
    return noiseSeed;
}

int WMath::Random::GetValue(int min, int max)
{
    std::uniform_int_distribution distribution(min, max);
    return distribution(generators[currentSeed]);
}

float WMath::Random::GetValue(float min, float max)
{
    std::uniform_real_distribution distribution(min, max);
    return distribution(generators[currentSeed]);
}

template <typename T>
T WMath::Random::GetValue(T min, T max)
{
    std::uniform_real_distribution<T> distribution(min, max);
    return distribution(generators[currentSeed]);
}

WMath::Vector2 WMath::Random::GetVector2(float min, float max)
{
    return {GetValue(min, max), GetValue(min, max)};
}

WMath::Vector3 WMath::Random::GetVector3(float min, float max)
{
    return {GetValue(min, max), GetValue(min, max), GetValue(min, max)};
}

float WMath::Random::GetNoise(float x, float y)
{
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
    return noise.GetNoise(x, y);
}

float WMath::Random::GetNoise(float x, float y, float z)
{
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
    return noise.GetNoise(x, y, z);
}

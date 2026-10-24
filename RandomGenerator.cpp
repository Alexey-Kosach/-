#include "RandomGenerator.h"
#include <utility>

RandomGenerator::RandomGenerator(const int min, const int max)
    : minVal(min),
    maxVal(max),
    randomEngine(std::random_device{}()),
    intDistribution(0, 0)
{
    if (minVal > maxVal)
    {
        std::swap(minVal, maxVal);
    }
    intDistribution = std::uniform_int_distribution<int>(minVal, maxVal);
}

int RandomGenerator::generate()
{
    return intDistribution(randomEngine);
}

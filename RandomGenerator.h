#pragma once
#include <random>
#include "Generator.h"

/**
 * @brief Генератор случайных чисел в заданном диапазоне
 */
class RandomGenerator : public Generator
{
private:
    /**
     * @brief Минимальное значение диапазона
     */
    int minVal;

    /**
     * @brief Максимальное значение диапазона
     */
    int maxVal;

    /**
     * @brief Механизм генерации псевдослучайных чисел
     */
    std::mt19937 randomEngine;

    /**
     * @brief Распределение случайных чисел
     */
    std::uniform_int_distribution<int> intDistribution;

public:
    /**
     * @brief Конструктор
     * @param min Минимальное значение
     * @param max Максимальное значение
     */
    RandomGenerator(const int min, const int max);

    /**
     * @brief Деструктор
     */
    ~RandomGenerator() override = default;

    /**
     * @brief Генерация случайного числа
     * @return Случайное число в заданном диапазоне
     */
    int generate() override;
};

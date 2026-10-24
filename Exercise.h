#pragma once
#include "Matrix.h"
#include "Generator.h"

/**
 * @brief Базовый виртуальный класс для заданий (упражнений)
 */
class Exercise
{
protected:
    /**
     * @brief Ссылка на исходную матрицу
     */
    Matrix& source;

    /**
     * @brief Ссылка на генератор значений (константная)
     */
    const Generator& generator;

public:
    /**
     * @brief Конструктор
     * @param src Ссылка на исходную матрицу
     * @param gen Ссылка на генератор
     */
    Exercise(Matrix& src, const Generator& gen);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Exercise() = default;

    /**
     * @brief Виртуальный метод решения задания
     * @return Новая матрица - результат решения
     */
    virtual Matrix solve() = 0;
};

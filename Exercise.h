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
    Matrix &source;

    // Убрано поле Generator &generator;

public:
    /**
     * @brief Конструктор
     * @param src Ссылка на исходную матрицу
     */
    // Убран параметр Generator из конструктора
    Exercise(Matrix &src);

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

#pragma once
#include "Exercise.h"

/**
 * @brief Класс Task2Exercise (Вариант 14).
 * Задание: Вставить после всех столбцов, содержащих нулевой элемент, первый столбец.
 */
class Task2Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     * @param gen Ссылка на генератор
     */
    Task2Exercise(Matrix& src, Generator& gen);

    /**
     * @brief Деструктор
     */
    ~Task2Exercise() override = default;

    /**
     * @brief Выполнить задание
     * @return Матрица с вставленными столбцами
     */
    Matrix solve() override;
};
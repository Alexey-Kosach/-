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
     */
    // Убран параметр Generator
    Task2Exercise(Matrix &src);

    /**
     * @brief Деструктор (переопределен)
     */
    ~Task2Exercise() override = default;

    /**
     * @brief Выполнить задание (переопределен)
     * @return Матрица с вставленными столбцами
     */
    Matrix solve() override;
};

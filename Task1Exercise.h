#pragma once
#include "Exercise.h"

/**
 * @brief Класс Task1Exercise (Вариант 14).
 * Задание: Заменить нечетный элемент каждой строки нулем.
 */
class Task1Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     */
    // Убран параметр Generator
    Task1Exercise(Matrix &src);

    /**
     * @brief Деструктор (переопределен)
     */
    ~Task1Exercise() override = default;

    /**
     * @brief Выполнить задание (переопределен)
     * @return Матрица с замененными нечетными элементами
     */
    Matrix solve() override;
};

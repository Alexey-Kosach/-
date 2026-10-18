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
     * @param gen Ссылка на генератор
     */
    Task1Exercise(Matrix& src, Generator& gen);

    /**
     * @brief Деструктор
     */
    ~Task1Exercise() override = default;

    /**
     * @brief Выполнить задание
     * @return Матрица с замененными нечетными элементами
     */
    Matrix solve() override;
};
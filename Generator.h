#pragma once

/**
 * @brief Абстрактный базовый класс для всех генераторов значений
 */
class Generator
{
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Generator() = default;

    /**
     * @brief Виртуальный метод генерации значения
     * @return Сгенерированное целочисленное значение
     */
    virtual int generate() const = 0;
};

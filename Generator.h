#pragma once

/**
 * @brief Абстрактный класс Generator для генерации значений
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
    virtual int generate() = 0;
};

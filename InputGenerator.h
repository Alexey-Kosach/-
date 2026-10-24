#pragma once
#include <iosfwd>
#include "Generator.h"

/**
 * @brief Класс InputGenerator абстрактного класса Generator.
 * Читает значения из потока ввода.
 */
class InputGenerator : public Generator
{
private:
    /**
     * @brief Ссылка на поток ввода
     */
    std::istream& inputStream;

public:
    /**
     * @brief Конструктор
     * @param input Ссылка на используемый поток ввода
     */
    explicit InputGenerator(std::istream& input);

    /**
     * @brief Деструктор
     */
    ~InputGenerator() override = default;

    /**
     * @brief Считывание числа из потока
     * @return Считанное число
     */
    int generate() override;
};

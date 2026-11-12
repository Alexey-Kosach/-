#pragma once
#include <iosfwd>
#include <string>
#include <vector>
#include "Generator.h"

/**
 * @brief Класс двумерного массива (матрицы) на основе std::vector
 */
class Matrix
{
private:
    /**
     * @brief Двумерный вектор для хранения данных
     */
    std::vector<std::vector<int>> matrixData;

    /**
     * @brief Количество строк
     */
    size_t rowCount;

    /**
     * @brief Количество столбцов
     */
    size_t colCount;

public:
    Matrix();
    Matrix(const size_t rows, const size_t cols);
    Matrix(const Matrix &other) = default;
    Matrix(Matrix &&other) noexcept = default;
    ~Matrix() = default;

    Matrix &operator=(const Matrix &other) = default;
    Matrix &operator=(Matrix &&other) noexcept = default;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);

    bool operator==(const Matrix &other) const;
    bool operator!=(const Matrix &other) const;

    std::string toString() const;

    const std::vector<int> &operator[](const size_t index) const;
    std::vector<int> &operator[](const size_t index);

    size_t getRows() const noexcept;
    size_t getColumns() const noexcept;

    void insertRowAfter(const size_t index, const std::vector<int> &newRow);
    void insertColumnAfter(const size_t index, const std::vector<int> &newColumn);

    /**
     * @brief Заполнение матрицы с помощью генератора
     * @param generator Ссылка на генератор значений
     */
    // Метод заполнения остался в классе Matrix, 
    void fillArray(Generator &generator); 
};

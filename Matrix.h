#pragma once
#include <iosfwd>
#include <string>
#include <vector>
#include "Generator.h"
#include "RandomGenerator.h"
#include "ConstGenerator.h"
#include "InputGenerator.h"

class Matrix
{
private:
    std::vector<std::vector<int>> matrixData;
    size_t rowCount;
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

   
    void fillArray(RandomGenerator &generator);
    void fillArray(ConstGenerator &generator);
    void fillArray(InputGenerator &generator);
};

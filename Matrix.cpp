#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <stdexcept>

Matrix::Matrix() : rowCount(0), colCount(0) {}

Matrix::Matrix(const size_t rows, const size_t cols) : rowCount(rows), colCount(cols)
{
    if (rowCount > 0 && colCount > 0)
    {
        matrixData.assign(rowCount, std::vector<int>(colCount, 0));
    }
    else
    {
        rowCount = 0;
        colCount = 0;
    }
}

size_t Matrix::getRows() const noexcept { return rowCount; }
size_t Matrix::getColumns() const noexcept { return colCount; }

std::vector<int>& Matrix::operator[](const size_t index)
{
    if (index >= rowCount)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return matrixData[index];
}

const std::vector<int>& Matrix::operator[](const size_t index) const
{
    if (index >= rowCount)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return matrixData[index];
}

std::string Matrix::toString() const
{
    if (rowCount == 0 || colCount == 0)
    {
        return "";
    }

    std::ostringstream oss;
    for (size_t i = 0; i < rowCount; ++i)
    {
        for (size_t j = 0; j < colCount; ++j)
        {
            oss << matrixData[i][j];
            if (j < colCount - 1)
            {
                oss << " ";
            }
        }
        if (i < rowCount - 1)
        {
            oss << "\n";
        }
    }
    return oss.str();
}

bool Matrix::operator==(const Matrix& other) const
{
    return rowCount == other.rowCount &&
        colCount == other.colCount &&
        matrixData == other.matrixData;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    os << matrix.getRows() << ' ' << matrix.getColumns() << '\n';
    os << matrix.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix)
{
    size_t r = 0;
    size_t c = 0;
    if (!(is >> r >> c))
        return is;

    if (r == 0 && c == 0)
    {
        matrix = Matrix();
        return is;
    }

    if (r == 0 || c == 0)
    {
        is.setstate(std::ios::failbit);
        return is;
    }

    Matrix temp(r, c);
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            if (!(is >> temp[i][j]))
                return is;
        }
    }

    matrix = std::move(temp);
    return is;
}

void Matrix::insertRowAfter(const size_t index, const std::vector<int>& newRow)
{
    if (index >= rowCount)
    {
        throw std::out_of_range("Index out of bounds");
    }
    matrixData.insert(matrixData.begin() + index + 1, newRow);
    rowCount++;
}

void Matrix::insertColumnAfter(const size_t index, const std::vector<int>& newColumn)
{
    if (index >= colCount)
    {
        throw std::out_of_range("Index out of bounds");
    }

    for (size_t i = 0; i < rowCount; ++i)
    {
        matrixData[i].insert(matrixData[i].begin() + index + 1, newColumn[i]);
    }
    colCount++;
}

void Matrix::fillArray(Generator& generator)
{
    for (size_t i = 0; i < rowCount; ++i)
    {
        for (size_t j = 0; j < colCount; ++j)
        {
            matrixData[i][j] = generator.generate();
        }
    }
}

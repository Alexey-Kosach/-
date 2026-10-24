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
    /**
     * @brief Конструктор по умолчанию (создает пустую матрицу)
     */
    Matrix();

    /**
     * @brief Конструктор матрицы rows * columns, заполненной нулями
     * @param rows Количество строк
     * @param cols Количество столбцов
     */
    Matrix(const size_t rows, const size_t cols);

    /**
     * @brief Конструктор копирования (глубокое копирование)
     * @param other Ссылка на другую матрицу
     */
    Matrix(const Matrix& other) = default;

    /**
     * @brief Конструктор перемещения
     * @param other Перемещаемый объект
     */
    Matrix(Matrix&& other) noexcept = default;

    /**
     * @brief Деструктор
     */
    ~Matrix() = default;

    /**
     * @brief Оператор присваивания копированием
     * @param other Ссылка на другую матрицу
     * @return Ссылка на скопированную матрицу
     */
    Matrix& operator=(const Matrix& other) = default;

    /**
     * @brief Оператор присваивания перемещением
     * @param other Перемещаемый объект
     * @return Ссылка на перемещенную матрицу
     */
    Matrix& operator=(Matrix&& other) noexcept = default;

    /**
     * @brief Перегрузка оператора вывода
     * @param os Поток вывода
     * @param matrix Матрица для вывода
     * @return Перегруженный поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    /**
     * @brief Перегрузка оператора ввода
     * @param is Поток ввода
     * @param matrix Матрица для ввода
     * @return Перегруженный поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    /**
     * @brief Оператор проверки на равенство
     * @param other Ссылка на другую матрицу
     * @return true - если матрицы равны, иначе false
     */
    bool operator==(const Matrix& other) const;

    /**
     * @brief Оператор проверки на неравенство
     * @param other Ссылка на другую матрицу
     * @return true - если матрицы не равны, иначе false
     */
    bool operator!=(const Matrix& other) const;

    /**
     * @brief Преобразование матрицы в строку
     * @return Строковое представление матрицы
     */
    std::string toString() const;

    /**
     * @brief Доступ к строке матрицы (только чтение)
     * @param index Номер строки
     * @return Константная ссылка на вектор строки
     */
    const std::vector<int>& operator[](const size_t index) const;

    /**
     * @brief Доступ к строке матрицы (чтение и запись)
     * @param index Номер строки
     * @return Ссылка на вектор строки
     */
    std::vector<int>& operator[](const size_t index);

    /**
     * @brief Получить количество строк
     * @return Количество строк
     */
    size_t getRows() const noexcept;

    /**
     * @brief Получить количество столбцов
     * @return Количество столбцов
     */
    size_t getColumns() const noexcept;

    /**
     * @brief Вставка новой строки после заданного индекса
     * @param index Индекс, после которого вставляется строка
     * @param newRow Вектор значений новой строки
     */
    void insertRowAfter(const size_t index, const std::vector<int>& newRow);

    /**
     * @brief Вставка нового столбца после заданного индекса
     * @param index Индекс, после которого вставляется столбец
     * @param newColumn Вектор значений нового столбца
     */
    void insertColumnAfter(const size_t index, const std::vector<int>& newColumn);

    /**
     * @brief Заполнение матрицы с помощью генератора
     * @param generator Ссылка на генератор значений
     */
    void fillArray(Generator& generator);
};

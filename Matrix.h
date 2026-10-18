#pragma once
#include <iosfwd>
#include <string>
#include "Generator.h"

/**
 * @brief Класс двумерного массива (матрицы)
 */
class Matrix
{
private:
    /**
     * @brief Количество строк
     */
    size_t row_count;

    /**
     * @brief Количество столбцов
     */
    size_t col_count;

    /**
     * @brief Указатель на массив указателей (сами данные)
     */
    int** matrix_data;

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
    Matrix(const Matrix& other);

    /**
     * @brief Конструктор перемещения
     * @param other Перемещаемый объект
     */
    Matrix(Matrix&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~Matrix();

    /**
     * @brief Оператор присваивания копированием
     * @param other Ссылка на другую матрицу
     * @return Ссылка на скопированную матрицу
     */
    Matrix& operator=(const Matrix& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Перемещаемый объект
     * @return Ссылка на перемещенную матрицу
     */
    Matrix& operator=(Matrix&& other) noexcept;

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
     * @return Указатель на начало строки
     */
    const int* operator[](const size_t index) const;

    /**
     * @brief Доступ к строке матрицы (чтение и запись)
     * @param index Номер строки
     * @return Указатель на начало строки
     */
    int* operator[](const size_t index);

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
     * @param new_row Указатель на массив значений новой строки
     */
    void insertRowAfter(const size_t index, const int* new_row);

    /**
     * @brief Вставка нового столбца после заданного индекса
     * @param index Индекс, после которого вставляется столбец
     * @param new_column Указатель на массив значений нового столбца
     */
    void insertColumnAfter(const size_t index, const int* new_column);

    /**
     * @brief Заполнение матрицы с помощью генератора
     * @param generator Ссылка на генератор значений
     */
    void fillArray(Generator& generator);
};
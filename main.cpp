#include <iostream>
#include <cstdlib>
#include <memory>

#include "../Project/Matrix.h"
#include "../Project/RandomGenerator.h"
#include "../Project/ConstGenerator.h"
#include "../Project/InputGenerator.h"
#include "../Project/Task1Exercise.h"
#include "../Project/Task2Exercise.h"


/**
 * @brief Перечисление для выбора генератора
 */
enum class GenType
{
    Random = 1,
    Const,
    Input
};

/**
 * @brief Перечисление для выбора задания
 */
enum class TaskType
{
    Task1 = 1,
    Task2
};

/**
 * @brief Получение положительного числа из консоли
 * @param message Сообщение для вывода
 * @return Введенное число
 */
size_t getPos(const char* message);

/**
 * @brief Получение целого числа из консоли
 * @param message Сообщение для вывода
 * @return Введенное число
 */
int getInt(const char* message);

/**
 * @brief Выбор генератора
 * @param message Сообщение для вывода
 * @return Умный указатель на созданный генератор
 */
std::unique_ptr<Generator> chooseGenerator(const char* message);

/**
 * @brief Запуск выбранного задания
 * @param matrix Ссылка на матрицу
 * @param generator Ссылка на генератор
 */
void runTask(Matrix& matrix, Generator& generator);

int main()
{
    setlocale(LC_ALL, "Russian");

    const size_t rows = getPos("Введите количество строк:");
    const size_t columns = getPos("Введите количество столбцов:");

    Matrix matrix(rows, columns);

    std::unique_ptr<Generator> generator = chooseGenerator("Выберите тип заполнения массива:");
    matrix.fillArray(*generator);

    std::cout << "Полученная матрица:\n"
        << matrix.toString() << std::endl;

    runTask(matrix, *generator);

    return 0;
}

size_t getPos(const char* message)
{
    size_t value = 0;
    std::cout << message << std::endl;
    if (std::cin >> value && value > 0)
    {
        return value;
    }
    std::cerr << "Некорректный ввод (введено не целое положительное число)" << std::endl;
    std::exit(1);
}

int getInt(const char* message)
{
    int value = 0;
    std::cout << message << std::endl;
    if (std::cin >> value)
        return value;
    std::cerr << "Некорректный ввод (введено не целое число)" << std::endl;
    std::exit(1);
}

std::unique_ptr<Generator> chooseGenerator(const char* message)
{
    std::cout << message << std::endl;
    std::cout << static_cast<int>(GenType::Random) << " - случайными числами\n"
        << static_cast<int>(GenType::Const) << " - одинаковым числом (константой)\n"
        << static_cast<int>(GenType::Input) << " - ввод с клавиатуры\n"
        << std::endl;

    int var = getInt("");
    switch (static_cast<GenType>(var))
    {
    case GenType::Random:
    {
        int minVal = getInt("Введите минимум диапазона:");
        int maxVal = getInt("Введите максимум диапазона:");
        return std::make_unique<RandomGenerator>(minVal, maxVal);
    }
    case GenType::Const:
    {
        int value = getInt("Введите значение константы:");
        return std::make_unique<ConstGenerator>(value);
    }
    case GenType::Input:
    {
        std::cout << "Введите значения массива:\n";
        return std::make_unique<InputGenerator>(std::cin);
    }
    default:
        std::cerr << "Некорректный выбор" << std::endl;
        std::exit(1);
    }
}

void runTask(Matrix& matrix, Generator& generator)
{
    std::cout << "Выберите задание:\n"
        << static_cast<int>(TaskType::Task1) << " - Задание 1. Заменить нечётный элемент каждой строки нулем\n"
        << static_cast<int>(TaskType::Task2) << " - Задание 2. Вставить первый столбец после всех столбцов, содержащих нулевой элемент" << std::endl;

    const int var = getInt("");

    switch (static_cast<TaskType>(var))
    {
    case TaskType::Task1:
    {
        Task1Exercise task(matrix, generator);
        Matrix result = task.solve();
        std::cout << "Результат:\n"
            << result.toString() << std::endl;
        break;
    }
    case TaskType::Task2:
    {
        Task2Exercise task(matrix, generator);
        Matrix result = task.solve();
        std::cout << "Результат:\n"
            << result.toString() << std::endl;
        break;
    }
    default:
        std::cerr << "Некорректный выбор" << std::endl;
        std::exit(1);
    }
}

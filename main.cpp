#include <iostream>
#include <cstdlib>
#include <windows.h>

#include "Matrix.h"
#include "RandomGenerator.h"
#include "ConstGenerator.h"
#include "InputGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

enum class GenType { Random = 1, Const, Input };
enum class TaskType { Task1 = 1, Task2 };

size_t getPos(const char *message);
int getInt(const char *message);
GenType chooseGeneratorType(const char *message);
void runTask(Matrix &matrix);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const size_t rows = getPos("Введите количество строк:");
    const size_t columns = getPos("Введите количество столбцов:");

    Matrix matrix(rows, columns);

    GenType genType = chooseGeneratorType("Выберите тип заполнения массива:");

    // Матрица заполняется здесь, а не в Exercise
    if (genType == GenType::Random)
    {
        int minVal = getInt("Введите минимум диапазона:");
        int maxVal = getInt("Введите максимум диапазона:");
        RandomGenerator generator(minVal, maxVal);
        matrix.fillArray(generator);
    }
    else if (genType == GenType::Const)
    {
        int value = getInt("Введите значение константы:");
        ConstGenerator generator(value);
        matrix.fillArray(generator);
    }
    else if (genType == GenType::Input)
    {
        std::cout << "Введите значения массива:\n";
        InputGenerator generator(std::cin);
        matrix.fillArray(generator);
    }
    else
    {
        std::cerr << "Ошибка: некорректный тип генератора!" << std::endl;
        return 1;
    }

    std::cout << "Полученная матрица:\n" << matrix.toString() << std::endl;

    // Передаем заполненную матрицу в задание
    runTask(matrix);

    return 0; 
}

size_t getPos(const char *message)
{
    if (message == nullptr) { std::cerr << "Ошибка: пустое сообщение!" << std::endl; std::exit(1); }
    size_t value = 0;
    std::cout << message << std::endl;
    if (!(std::cin >> value) || value == 0) { std::cerr << "Некорректный ввод" << std::endl; std::exit(1); }
    return value; 
}

int getInt(const char *message)
{
    if (message == nullptr) { std::cerr << "Ошибка: пустое сообщение!" << std::endl; std::exit(1); }
    int value = 0;
    std::cout << message << std::endl;
    if (!(std::cin >> value)) { std::cerr << "Некорректный ввод" << std::endl; std::exit(1); }
    return value;
}

GenType chooseGeneratorType(const char *message)
{
    if (message == nullptr) { std::cerr << "Ошибка: пустое сообщение!" << std::endl; std::exit(1); }
    std::cout << message << std::endl;
    std::cout << static_cast<int>(GenType::Random) << " - случайными числами\n"
              << static_cast<int>(GenType::Const) << " - константой\n"
              << static_cast<int>(GenType::Input) << " - ввод с клавиатуры\n" << std::endl;
    int var = getInt("");
    if (var < 1 || var > 3) { std::cerr << "Ошибка: выбран недопустимый вариант!" << std::endl; std::exit(1); }
    return static_cast<GenType>(var);
}

// функция runTask больше не принимает Generator
void runTask(Matrix &matrix)
{
    std::cout << "Выберите задание:\n"
              << static_cast<int>(TaskType::Task1) << " - Задание 1. Заменить нечётный элемент каждой строки нулем\n"
              << static_cast<int>(TaskType::Task2) << " - Задание 2. Вставить первый столбец после всех столбцов, содержащих нулевой элемент" << std::endl;
              
    const int var = getInt("");

    switch (static_cast<TaskType>(var))
    {
    case TaskType::Task1:
    {
        // передаем только матрицу
        Task1Exercise task(matrix);
        Matrix result = task.solve();
        std::cout << "Результат:\n" << result.toString() << std::endl;
        break;
    }
    case TaskType::Task2:
    {
        // передаем только матрицу
        Task2Exercise task(matrix);
        Matrix result = task.solve();
        std::cout << "Результат:\n" << result.toString() << std::endl;
        break;
    }
    default:
        std::cerr << "Некорректный выбор" << std::endl;
        std::exit(1);
    }
}

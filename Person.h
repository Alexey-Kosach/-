#pragma once
#include <string>

/**
 * @brief Базовый класс Person - представляет человека (пациента или медработника).
 *
 * Содержит уникальный идентификатор и ФИО. Является базовым классом для
 * MedicalWorker и Patient, обеспечивая полиморфизм через виртуальный метод getInfo().
 */
class Person
{
protected:
    /**
     * @brief Статический счетчик для автогенерации ID.
     */
    static int nextId;

    /**
     * @brief Уникальный идентификатор человека.
     */
    int id;

    /**
     * @brief ФИО человека.
     */
    std::string name;

public:
    /**
     * @brief Конструктор по умолчанию.
     * Автоматически генерирует новый уникальный ID.
     */
    Person();

    /**
     * @brief Конструктор с параметрами.
     * @param name - ФИО человека.
     * @param id - ID человека (если 0 или меньше, генерируется автоматически).
     */
    Person(const std::string &name, const int id = 0);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Person() = default;

    /**
     * @brief Получить уникальный идентификатор.
     * @return ID человека.
     */
    int getId() const noexcept;

    /**
     * @brief Получить ФИО.
     * @return Ссылка на строку с ФИО.
     */
    const std::string &getName() const noexcept;

    /**
     * @brief Получить информацию о человеке в виде строки.
     * @return Строка с ID и ФИО.
     */
    virtual std::string getInfo() const;
};

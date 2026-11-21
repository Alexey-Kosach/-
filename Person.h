#pragma once

#include <string>

/**
 * @brief Ѕазовый класс Person - человек (пациент или медработник)
 */
class Person
{
protected:
    static int nextId;

    int id;
    std::string name;

public:
    Person();
    Person(const std::string& name, const int id = 0);
    virtual ~Person() = default;

    int getId() const noexcept;
    const std::string& getName() const noexcept;
    virtual std::string getInfo() const;
};

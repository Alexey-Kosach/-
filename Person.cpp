#include "Person.h"

int Person::nextId = 1;

Person::Person() : id(nextId++), name("") {}

Person::Person(const std::string& name, const int id)
    : id(id > 0 ? id : nextId++), name(name)
{
    if (this->id >= nextId)
        nextId = this->id + 1;
}

int Person::getId() const noexcept { return id; }

const std::string& Person::getName() const noexcept { return name; }

std::string Person::getInfo() const
{
    return "ID: " + std::to_string(id) + "\n   ФИО: " + name;
}

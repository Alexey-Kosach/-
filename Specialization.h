#pragma once

#include <string>

/**
 * @brief Класс Specialization - специализация медработника
 */
class Specialization
{
private:
    std::string title;

public:
    Specialization() = default;
    explicit Specialization(const std::string& title);

    const std::string& getTitle() const noexcept;
};

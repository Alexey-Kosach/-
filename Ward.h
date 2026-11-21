#pragma once

#include <string>

/**
 * @brief Класс Ward - палата
 */
class Ward
{
private:
    std::string number;

public:
    Ward() = default;
    explicit Ward(const std::string& number);

    const std::string& getNumber() const noexcept;
};

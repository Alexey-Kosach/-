#pragma once
#include <string>

/**
 * @brief Класс Specialization - представляет специализацию медработника.
 *
 * Хранит название специализации (например, "Терапевт", "Хирург").
 */
class Specialization
{
private:
    /**
     * @brief Название специализации.
     */
    std::string title;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Specialization() = default;

    /**
     * @brief Конструктор с параметрами.
     * @param title - название специализации.
     */
    explicit Specialization(const std::string &title);

    /**
     * @brief Получить название специализации.
     * @return Ссылка на строку с названием.
     */
    const std::string &getTitle() const noexcept;
};

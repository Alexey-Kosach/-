#pragma once
#include <string>

/**
 * @brief Класс Ward - представляет палату в больнице.
 *
 * Хранит номер палаты. Используется для группировки пациентов
 * и вывода списка пациентов по палатам.
 */
class Ward
{
private:
    /**
     * @brief Номер палаты.
     */
    std::string number;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Ward() = default;

    /**
     * @brief Конструктор с параметрами.
     * @param number - номер палаты.
     */
    explicit Ward(const std::string &number);

    /**
     * @brief Получить номер палаты.
     * @return Ссылка на строку с номером.
     */
    const std::string &getNumber() const noexcept;
};

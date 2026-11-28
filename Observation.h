#pragma once
#include <string>

/**
 * @brief Класс Observation - представляет запись наблюдения пациента медработником.
 *
 * Хранит ФИО пациента, дату наблюдения и количество дней.
 */
class Observation
{
private:
    /**
     * @brief ФИО пациента.
     */
    std::string patientName;

    /**
     * @brief Дата наблюдения.
     */
    std::string date;

    /**
     * @brief Количество дней наблюдения.
     */
    int days;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Observation() = default;

    /**
     * @brief Конструктор с параметрами.
     * @param patientName - ФИО пациента.
     * @param date - дата наблюдения.
     * @param days - количество дней.
     */
    Observation(const std::string &patientName, const std::string &date, const int days);

    /**
     * @brief Получить ФИО пациента.
     * @return Ссылка на строку с ФИО.
     */
    const std::string &getPatientName() const noexcept;

    /**
     * @brief Получить дату наблюдения.
     * @return Ссылка на строку с датой.
     */
    const std::string &getDate() const noexcept;

    /**
     * @brief Получить количество дней.
     * @return Количество дней.
     */
    int getDays() const noexcept;

    /**
     * @brief Получить строковое представление записи.
     * @return Строка с информацией о наблюдении.
     */
    std::string toString() const;
};

#pragma once

#include <string>

/**
 * @brief Класс Observation - запись наблюдения пациента медработником
 */
class Observation
{
private:
    std::string patientName;
    std::string date;
    int days;

public:
    Observation() = default;
    Observation(const std::string& patientName, const std::string& date, const int days);

    const std::string& getPatientName() const noexcept;
    const std::string& getDate() const noexcept;
    int getDays() const noexcept;

    std::string toString() const;
};

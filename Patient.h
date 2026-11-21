#pragma once

#include "Person.h"
#include "Ward.h"
#include <vector>
#include <string>

/**
 * @brief Класс Patient - пациент
 */
class Patient : public Person
{
private:
    Ward ward;
    std::string doctorName;
    std::vector<std::string> diagnoses;

public:
    Patient();

    Patient(const std::string& name,
        const Ward& ward,
        const std::string& doctorName,
        const int id = 0);

    const Ward& getWard() const noexcept;
    const std::string& getDoctorName() const noexcept;
    const std::vector<std::string>& getDiagnoses() const noexcept;

    void addDiagnosis(const std::string& diagnosis);
    bool hasDiagnosis(const std::string& diagnosis) const noexcept;

    std::string getInfo() const override;
};

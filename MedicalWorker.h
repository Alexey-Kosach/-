#pragma once

#include "Person.h"
#include "Specialization.h"
#include "Observation.h"
#include <vector>

/**
 * @brief Класс MedicalWorker - медицинский работник
 */
class MedicalWorker : public Person
{
private:
    Specialization specialization;
    std::string position;
    std::vector<Observation> observations;
    std::vector<std::string> observedPatients;

public:
    MedicalWorker();

    MedicalWorker(const std::string& name,
        const Specialization& specialization,
        const std::string& position,
        const int id = 0);

    const Specialization& getSpecialization() const noexcept;
    const std::string& getPosition() const noexcept;
    const std::vector<Observation>& getObservations() const noexcept;
    const std::vector<std::string>& getObservedPatients() const noexcept;

    void addObservation(const Observation& observation);
    void addObservedPatient(const std::string& patientName);
    bool observesPatient(const std::string& patientName) const noexcept;

    std::string getInfo() const override;
};

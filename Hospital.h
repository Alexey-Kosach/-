#pragma once

#include "Person.h"
#include "MedicalWorker.h"
#include "Patient.h"
#include "Ward.h"
#include "Specialization.h"
#include <vector>
#include <string>

/**
 * @brief Класс Hospital - больница
 */
class Hospital
{
private:
    std::vector<Person> persons;
    std::vector<MedicalWorker> workers;
    std::vector<Patient> patients;
    std::vector<Ward> wards;
    std::vector<Specialization> specializations;

    bool containsId(const int id) const;

public:
    Hospital() = default;
    ~Hospital() = default;

    void addPerson(const Person &person);
    void addWorker(const MedicalWorker &worker);
    void addPatient(const Patient &patient);
    void addWard(const Ward &ward);
    void addSpecialization(const Specialization &specialization);

    const std::vector<Person> &getPersons() const noexcept;
    const std::vector<MedicalWorker> &getWorkers() const noexcept;
    const std::vector<Patient> &getPatients() const noexcept;
    const std::vector<Ward> &getWards() const noexcept;
    const std::vector<Specialization> &getSpecializations() const noexcept;

    /** Сведения о медицинских работниках */
    void printWorkers() const;

    /** Сведения о медработниках, наблюдающих за пациентом */
    void printWorkersForPatient(const std::string &patientName) const;

    /** Сведения о пациентах */
    void printPatients() const;

    /** Сведения о пациентах у определённого медработника */
    void printPatientsForWorker(const std::string &workerName) const;

    /** Нахождение пациентов по палатам */
    void printPatientsByWard(const std::string &wardNumber) const;
};
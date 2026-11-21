#include "Hospital.h"
#include <iostream>
#include <algorithm>

bool Hospital::containsId(const int id) const
{
    bool inWorkers = std::any_of(workers.begin(), workers.end(),
        [id](const MedicalWorker& w) { return w.getId() == id; });
    if (inWorkers) return true;

    bool inPatients = std::any_of(patients.begin(), patients.end(),
        [id](const Patient& p) { return p.getId() == id; });
    if (inPatients) return true;

    return std::any_of(persons.begin(), persons.end(),
        [id](const Person& p) { return p.getId() == id; });
}

void Hospital::addPerson(const Person& person)
{
    if (containsId(person.getId())) return;
    persons.push_back(person);
}

void Hospital::addWorker(const MedicalWorker& worker)
{
    if (containsId(worker.getId())) return;
    workers.push_back(worker);
}

void Hospital::addPatient(const Patient& patient)
{
    if (containsId(patient.getId())) return;
    patients.push_back(patient);
}

void Hospital::addWard(const Ward& ward)
{
    auto it = std::find_if(wards.begin(), wards.end(),
        [&ward](const Ward& w) { return w.getNumber() == ward.getNumber(); });
    if (it != wards.end()) return;
    wards.push_back(ward);
}

void Hospital::addSpecialization(const Specialization& spec)
{
    auto it = std::find_if(specializations.begin(), specializations.end(),
        [&spec](const Specialization& s) { return s.getTitle() == spec.getTitle(); });
    if (it != specializations.end()) return;
    specializations.push_back(spec);
}

const std::vector<Person>& Hospital::getPersons() const noexcept { return persons; }
const std::vector<MedicalWorker>& Hospital::getWorkers() const noexcept { return workers; }
const std::vector<Patient>& Hospital::getPatients() const noexcept { return patients; }
const std::vector<Ward>& Hospital::getWards() const noexcept { return wards; }
const std::vector<Specialization>& Hospital::getSpecializations() const noexcept { return specializations; }

void Hospital::printWorkers() const
{
    std::cout << "=== Медицинские работники ===" << std::endl;
    for (const MedicalWorker& w : workers)
        std::cout << w.getInfo() << "\n" << std::endl;
}

void Hospital::printWorkersForPatient(const std::string& patientName) const
{
    std::cout << "Медработники, наблюдающие за пациентом '" << patientName << "':" << std::endl;
    bool found = false;
    for (const MedicalWorker& w : workers)
    {
        if (w.observesPatient(patientName))
        {
            std::cout << "- " << w.getName() << " (" << w.getSpecialization().getTitle() << ")" << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "Медработников не найдено." << std::endl;
    std::cout << std::endl;
}

void Hospital::printPatients() const
{
    std::cout << "=== Пациенты ===" << std::endl;
    for (const Patient& p : patients)
        std::cout << p.getInfo() << "\n" << std::endl;
}

void Hospital::printPatientsForWorker(const std::string& workerName) const
{
    std::cout << "Пациенты у медработника '" << workerName << "':" << std::endl;
    bool found = false;
    for (const Patient& p : patients)
    {
        if (p.getDoctorName() == workerName)
        {
            std::cout << "- " << p.getName() << " (палата " << p.getWard().getNumber() << ")" << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "Пациентов не найдено." << std::endl;
    std::cout << std::endl;
}

void Hospital::printPatientsByWard(const std::string& wardNumber) const
{
    std::cout << "Пациенты в палате '" << wardNumber << "':" << std::endl;
    bool found = false;
    for (const Patient& p : patients)
    {
        if (p.getWard().getNumber() == wardNumber)
        {
            std::cout << "- " << p.getName() << " (врач: " << p.getDoctorName() << ")" << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "Пациентов в этой палате нет." << std::endl;
    std::cout << std::endl;
}
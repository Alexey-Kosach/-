#include "MedicalWorker.h"

MedicalWorker::MedicalWorker() : Person() {}

MedicalWorker::MedicalWorker(const std::string& name,
    const Specialization& specialization,
    const std::string& position,
    const int id)
    : Person(name, id), specialization(specialization), position(position) {
}

const Specialization& MedicalWorker::getSpecialization() const noexcept { return specialization; }
const std::string& MedicalWorker::getPosition() const noexcept { return position; }
const std::vector<Observation>& MedicalWorker::getObservations() const noexcept { return observations; }
const std::vector<std::string>& MedicalWorker::getObservedPatients() const noexcept { return observedPatients; }

void MedicalWorker::addObservation(const Observation& observation)
{
    observations.push_back(observation);
}

void MedicalWorker::addObservedPatient(const std::string& patientName)
{
    observedPatients.push_back(patientName);
}

bool MedicalWorker::observesPatient(const std::string& patientName) const noexcept
{
    for (const std::string& p : observedPatients)
        if (p == patientName)
            return true;
    return false;
}

std::string MedicalWorker::getInfo() const
{
    std::string result = Person::getInfo();
    result += "\n   Специализация: " + specialization.getTitle();
    result += "\n   Должность: " + position;
    return result;
}

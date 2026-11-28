#include "Patient.h"

Patient::Patient() : Person() {}

Patient::Patient(const std::string& name, const Ward& ward, const std::string& doctorName, const int id)
    : Person(name, id), ward(ward), doctorName(doctorName) {
}

const Ward& Patient::getWard() const noexcept { return ward; }
const std::string& Patient::getDoctorName() const noexcept { return doctorName; }
const std::vector<std::string>& Patient::getDiagnoses() const noexcept { return diagnoses; }

void Patient::addDiagnosis(const std::string& diagnosis)
{
    diagnoses.push_back(diagnosis);
}

bool Patient::hasDiagnosis(const std::string& diagnosis) const noexcept
{
    for (const std::string& d : diagnoses)
        if (d == diagnosis)
            return true;
    return false;
}

std::string Patient::getInfo() const
{
    std::string result = Person::getInfo();
    result += "\n   Палата: " + ward.getNumber();
    result += "\n   Лечащий врач: " + doctorName;
    return result;
}

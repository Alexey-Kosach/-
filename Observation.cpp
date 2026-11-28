#include "Observation.h"

Observation::Observation(const std::string& patientName, const std::string& date, const int days)
    : patientName(patientName), date(date), days(days) {
}

const std::string& Observation::getPatientName() const noexcept { return patientName; }
const std::string& Observation::getDate() const noexcept { return date; }
int Observation::getDays() const noexcept { return days; }

std::string Observation::toString() const
{
    return "Пациент: " + patientName + "/ Дата: " + date + "/ Дней: " + std::to_string(days);
}

#include "Specialization.h"

Specialization::Specialization(const std::string& title) : title(title) {}

const std::string& Specialization::getTitle() const noexcept { return title; }

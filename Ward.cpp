#include "Ward.h"

Ward::Ward(const std::string& number) : number(number) {}

const std::string& Ward::getNumber() const noexcept { return number; }

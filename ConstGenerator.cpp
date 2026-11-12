#include "ConstGenerator.h"

ConstGenerator::ConstGenerator(const int value) : constantValue(value) {}

int ConstGenerator::generate()
{
    return this->constantValue;
}

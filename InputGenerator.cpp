#include "InputGenerator.h"
#include <iostream>

InputGenerator::InputGenerator(std::istream& input) : inputStream(input) {}

int InputGenerator::generate()
{
    int value = 0;
    this->inputStream >> value;
    return value;
}

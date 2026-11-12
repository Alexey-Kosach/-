#pragma once
#include "Matrix.h"
#include "Generator.h"

class Exercise
{
protected:
    Matrix &source;
    // убран const у Generator, так как generate() меняет состояние
    Generator &generator; 

public:
    // убран const у Generator
    Exercise(Matrix &src, Generator &gen);
    virtual ~Exercise() = default;
    virtual Matrix solve() = 0;
};

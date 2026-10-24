#include "Task2Exercise.h"
#include <vector>

Task2Exercise::Task2Exercise(Matrix& src, const Generator& gen) : Exercise(src, gen) {}

Matrix Task2Exercise::solve()
{
    const size_t rows = source.getRows();
    const size_t columns = source.getColumns();

    if (rows == 0 || columns == 0)
    {
        return Matrix();
    }

    
    std::vector<int> firstColumn(rows);
    for (size_t i = 0; i < rows; i++)
    {
        firstColumn[i] = source[i][0];
    }

    Matrix result(source);

    
    for (size_t j = columns; j > 0; --j)
    {
        size_t actualIndex = j - 1;

        bool hasZero = false;
        for (size_t i = 0; i < rows; i++)
        {
            if (result[i][actualIndex] == 0)
            {
                hasZero = true;
                break;
            }
        }

        if (hasZero)
        {
            result.insertColumnAfter(actualIndex, firstColumn);
        }
    }

    return result;
}

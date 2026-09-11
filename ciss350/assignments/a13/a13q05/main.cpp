#include <iostream>
#include "HashTable.h"
#include "SparseMatrix.h"

int main()
{
    SparseMatrix m(1000, 2000); // 1000-by-2000
    m.set(10, 20, 3.1415); // set value at row 10, column 20 to 3.1415
    std::cout << m.get(10, 20) << '\n'; // prints 3.1415
    std::cout << m.get(0, 0) << '\n'; // prints 0 -- the default value

    // Index Error test
    try
    {
        std::cout << m.get(10000, 10000);
    }
    catch(IndexError&)
    {
        std::cout << "IndexError caught" << '\n';
    }

    try
    {
        m.set(10000, 10000, 5);
    }
    catch(IndexError&)
    {
        std::cout << "IndexError caught" << '\n';
    }

    // multiple values test
    m.set(0, 0, 1.1);
    m.set(2, 3, 2.2);
    m.set(4, 4, 3.3);

    std::cout << "m(0,0): " << m.get(0,0) << '\n'; // prints 1.1
    std::cout << "m(2,3): " << m.get(2,3) << '\n'; // prints 2.2
    std::cout << "m(4,4): " << m.get(4,4) << '\n'; // prints 3.3

    // Removal test
    std::cout << "Removing (2, 3)" << '\n';
    m.set(2, 3, 0);
    std::cout << "m(2, 3): " << m.get(2, 3) << '\n'; // prints 0

    // Stress test
    const int size = 100;
    SparseMatrix m2(size, size);

    std::cout << "Stress test..." << '\n';

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            m2.set(i, j, i * j);
        }
    }

    bool correct = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(m2.get(i, j) != i * j)
            {
                correct == false;
                break;
            }
        }
    }

    if(correct)
        std::cout << "passed" << '\n';
    else
        std::cout << "failed" << '\n';

    return 0;
}

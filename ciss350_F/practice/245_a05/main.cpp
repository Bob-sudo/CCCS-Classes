#include <iostream>
#include <cstdlib>
#include "robot.h"

void test_print()
{
}

int main()
{
    int seed;
    std::cin >> seed;
    srand(seed);

    int option = 0;
    std::cin >> option;
    switch(option)
    {
        case 1:
            test_print();
            break;
    }
    
    return 0;
}

//File: a08q01.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int row, num = 1;
    std::cin >> row;

    std::cout << "         i"
              << "       i^2"
              << "       i^3"
              << "       i^4"
              << '\n';
    std::cout << " ---------"
              << " ---------"
              << " ---------"
              << " ---------" <<'\n';
    for(int i = 0; i < row; i++)
    {
        std::cout << std::right << std::setfill (' ') << std::setw(10) << num
                  << std::right << std::setfill (' ') << std::setw(10) << pow(num, 2)
                  << std::right << std::setfill (' ') << std::setw(10) << pow(num, 3)
                  << std::right << std::setfill (' ') << std::setw(10) << pow(num, 4)
                  << '\n';
        num++;
    }
    
    return 0;
}

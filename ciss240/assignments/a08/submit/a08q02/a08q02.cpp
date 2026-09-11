//File: a08q02.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int min, max;
    std::cin >> min >> max;

    std::cout << "         i"
              << "       i^2"
              << "       i^3"
              << "       i^4"
              << '\n';
    std::cout << " ---------"
              << " ---------"
              << " ---------"
              << " ---------" <<'\n';
    for(int i = max; i >= min;)
    {
        std::cout << std::right << std::setfill (' ') << std::setw(10) << min
                  << std::right << std::setfill (' ') << std::setw(10) << pow(min, 2)
                  << std::right << std::setfill (' ') << std::setw(10) << pow(min, 3)
                  << std::right << std::setfill (' ') << std::setw(10) << pow(min, 4)
                  << '\n';
        min++;
    }
    
    return 0;
}

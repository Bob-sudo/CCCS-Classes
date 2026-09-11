//File: a09q01.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;


    std::cout << "      ";
    for(int i = c; i <= d ; i++)
    {
        std::cout << std::right << std::setw(15) << std::setfill(' ')
                  << i;
    }
    
    std::cout << '\n';
    std::cout << "      ";
    
    for(int i = c; i <= d ; i++)
    {
        std::cout << std::setw(15) << std::setfill('-') << '-';
    }
    std::cout << '\n';

    for(int i = a; i <= b; i++)
    {
        std::cout << std::right << std::setw(5) << std::setfill(' ') << i << '|';
        for(int j = c; j <= d; j++)
        {
            std::cout << std::right << std::setw(15) << std::setfill(' ')
                      << std::fixed << std::setprecision(0) << pow(i, j);
        }
        std::cout << '\n';
    }

    return 0;
}

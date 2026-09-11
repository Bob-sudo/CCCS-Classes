//File: a09q04.cpp
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    int z;

    std::cin >> z;

    for(int x = 1; x <= cbrt(z); ++x)
    {
        for(int y = x; y <= cbrt(z); ++y)
        {
            if(pow(x, 3) + pow(y, 3) == z)
            {
                std::cout << x << ',' << y << ' ';
            }
        }
    }
    
    std::cout << '\n';
}

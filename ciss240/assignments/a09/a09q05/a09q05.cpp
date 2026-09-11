//File: a09q05.cpp
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    int z;

    std::cin >> z;

    for(int i = 2; i <= z; ++i)
    {
        int found_sol = false;
        
        for(int x = 1; x <= cbrt(i); ++x)
        {
            for(int y = x; y <= cbrt(i); ++y)
            {
                if(pow(x, 3) + pow(y, 3) == i)
                {
                    found_sol = true;
                }
            }
        }

        if(found_sol == true)
        {
            std::cout << i << ": ";
            for(int x = 1; x <= cbrt(i); ++x)
            {
                for(int y = x; y <= cbrt(i); ++y)
                {
                    if(pow(x, 3) + pow(y, 3) == i)
                    {
                        std::cout << x << ',' << y << ' ';
                    }
                }
            }
            std::cout << '\n';
        }
    }
}

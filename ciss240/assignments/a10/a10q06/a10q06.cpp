//File: a10q06.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < i * n; i++)
    {
        int layer = i / 3;

        //print spaces
        for(int j = 0; j < (n - layer - 1) * 3 + (3 - (i % 3) - 1); j++)
        {
            std::cout << ' ';
        }
        
    }
}

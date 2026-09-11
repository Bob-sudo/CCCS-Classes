// File: a01q01.cpp
// Name: Ethan Graham

#include <iostream>

void draw_spiral(int n)
{
    for(int i = 0; i < n * 4 + 1; i++)
    {
        if(i % 2 > 0)
        {
            std::cout << '+';
            for(int j = 0; j < i; j++)
            {
                
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    draw_spiral(n);
    return 0;
}

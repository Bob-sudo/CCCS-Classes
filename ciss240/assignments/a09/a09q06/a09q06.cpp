//File: a09q06.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    int n;

    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {

        //front spaces
        for(int j = 0; j < i; j++)
        {
            std::cout << ' ';
        }

        //in between spaces
        if(i != n - 1)
        {
            std::cout << '*';

            for(int j = 0; j < (n - i - 1) * 2 - 1; j++)
            {
                std::cout << ' ';
            }
            std::cout << '*' << '\n';
        }
        else
        {
            std::cout << '*' << '\n';
        }
    }

    return 0;
}

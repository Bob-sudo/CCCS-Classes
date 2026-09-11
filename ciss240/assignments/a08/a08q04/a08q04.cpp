//File: a08q04.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    srand((unsigned int) 0);

    int n, point = 0;

    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int a = rand() % 9, b = rand() % 9, sum;
        
        std::cout << a << " * " << b << " = ";
        std::cin >> sum;

        if(sum == a * b)
        {
            point++;
        }
    }

    std::cout << point << '\n';
    
    return 0;      
}

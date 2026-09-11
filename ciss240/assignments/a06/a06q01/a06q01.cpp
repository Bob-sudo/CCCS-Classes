//File: a06q01.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int year;
    std::cin >> year;

    if(year % 4 == 0)
    {
        if(year % 400 == 0 || year % 100 > 0 && year % 4 == 0)
        {
            std::cout << "leap year" << '\n';
        }
    }

    else
    {
        std::cout << "not leap year" << '\n';
    }

    return 0;
}

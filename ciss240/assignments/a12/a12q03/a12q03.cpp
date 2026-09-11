//File: a12q03.cpp
//Name: Ethan Graham

#include <iostream>

bool is_leap_year(int year)
{
    if((year % 4 == 0) && (year % 100 != 0 ||
       (year % 100 == 0 && year % 400 == 0)))
    {
        return true;
    }
    
    return false;
}

int main()
{
    int y = 0;
    std::cin >> y;

    std::cout << is_leap_year(y) << '\n';

    return 0;
}

//File: a06q02.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int date;
    std::cin >> date;

    int month = (date % 10000) / 100, day = date % 100, year = date / 10000;
    bool is_leap_year = false;

    if(year % 4 == 0)
    {
        if(year % 400 == 0 || year % 100 > 0 && year % 4 == 0)
        {
            is_leap_year = true;
        }
    }
    
    if(month < 13)
    {
        if(month == 1 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 2 && day <= 28 && day > 0 || day == 29 && is_leap_year)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 3 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 4 && day <= 30 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 5 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 6 && day <= 30 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 7 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 8 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 9 && day <= 30 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 10 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 11 && day <= 30 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else if(month == 12 && day <= 31 && day > 0)
        {
            std::cout << "correct" << '\n';
        }
        else
        {
            std::cout << "incorrect" << '\n';
        }
    }
    
    else
    {
        std::cout << "incorrect" << '\n';
    }

    return 0;
}

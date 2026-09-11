//File: a12q04.cpp
//Name: Ethan Graham

#include <iostream>

bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int days_in_month(int month, int year)
{
    if (month == 2)
    {
        return is_leap_year(year) ? 29 : 28;
    }
    else if ((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8))
    {
        return 31;
    }
    else
    {
        return 30;
    }
}

int main()
{
    int m, y;
    std::cin >> m >> y;
    std::cout << days_in_month(m, y) << std::endl;
    return 0;
}

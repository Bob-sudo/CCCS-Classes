//File: a12q05.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

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

void print_calendar_month(int month, int year, int day_of_first)
{
    //Take Month
    switch (month)
    {
    case 1:
        std::cout << "January ";
        break;
    case 2:
        std::cout << "February ";
        break;
    case 3:
        std::cout << "March ";
        break;
    case 4:
        std::cout << "April ";
        break;
    case 5:
        std::cout << "May ";
        break;
    case 6:
        std::cout << "June ";
        break;
    case 7:
        std::cout << "July ";
        break;
    case 8:
        std::cout << "August ";
        break;
    case 9:
        std::cout << "September ";
        break;
    case 10:
        std::cout << "October ";
        break;
    case 11:
        std::cout << "November ";
        break;
    case 12:
        std::cout << "December ";
        break;
    }
    std::cout << year << '\n';
    std::cout << "--------------------\n";
    std::cout << "Su Mo Tu We Th Fr Sa\n";

    int days = days_in_month(month, year);

    //Print Spaces
    for (int i = 0; i < day_of_first; i++)
    {
        std::cout << "   ";
    }

    //Print the days of the month
    int day_of_week = day_of_first;
    for (int day = 1; day <= days; ++day)
    {
        std::cout << std::setw(2) << day << ' ';
        day_of_week++;
        if (day_of_week == 7)
        {
            std::cout << '\n';
            day_of_week = 0;
        }
    }
    if (day_of_week != 0)
    {
        std::cout << '\n';
    }
}

int main()
{
    int month, year, day_of_first;
    std::cin >> month >> year >> day_of_first;
    print_calendar_month(month, year, day_of_first);
    return 0;
}

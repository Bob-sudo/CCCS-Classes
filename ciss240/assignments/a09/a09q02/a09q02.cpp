//File: a09q02.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    int month, year, day;
    bool leap_year = false;
    std::cin >> month >> year >> day;

    //determines leap year
    if(year % 4 == 0 && year % 100 > 0 || year % 400 == 0)
    {
        leap_year = true;
    }

    //Takes month
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
    std::cout << std::setw(20) << std::setfill('-') << '-' << '\n';
    std::cout << "Su Mo Tu We Th Fr Sa" << '\n';

    //Places first day on the calender
    for(int i = 0; i <= day; i++)
    {
        if(i < day)
        {
            std::cout << "   ";
        }
        if(i == day)
        {
            std::cout << std::right << std::setw(2) << std::setfill(' ') << '1' << ' ';
        }
    }

    //Months with 31 days
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        for(int i = 2; i <= 31; i++)
        {
            day += 1;
            if(day > 6)
            {
                day = 0;
                std::cout << '\n';
            }
            
            std::cout << std::right << std::setw(2) << std::setfill(' ') << i << ' ';
        }
        std::cout << '\n';
    }

    //Months with 30 days
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        for(int i = 2; i <= 30; i++)
        {
            day += 1;
            if(day > 6)
            {
                day = 0;
                std::cout << '\n';
            }
            std::cout << std::right << std::setw(2) << std::setfill(' ') << i << ' ';
        }
        std::cout << '\n';
    }

    //February
    if(month == 2)
    {
        //checks if leap year
        switch(leap_year)
        {
            case true:
                for(int i = 2; i <= 29; i++)
                {
                    day += 1;
                    if(day > 6)
                    {
                        day = 0;
                        std::cout << '\n';
                    }
                    std::cout << std::right << std::setw(2) << std::setfill(' ') << i << ' ';
                }
                std::cout << '\n';
                break;
            case false:                
                for(int i = 2; i <= 28; i++)
                {
                    day += 1;
                    if(day > 6)
                    {
                        day = 0;
                        std::cout << '\n';
                    }
                    std::cout << std::right << std::setw(2) << std::setfill(' ') << i << ' ';
                }
                std::cout << '\n';
                break;
        }
    }

    return 0;
}

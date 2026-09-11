//File: a05q04.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int format, hour, minute, second;
    std::cin >> format >> hour >> minute >> second;
    bool time;

    if(format == 0 && hour <= 12 && hour > 0)
    {
        if(minute <= 60 && second <= 60 && minute >= 0 && second >= 0)
        {
            time = true;
        }
        else
        {
            time = false;
        }
    }
    if(format == 1 && hour <= 23 && hour >= 0)
    {
        if(minute <= 60 && second <= 60 && minute >= 0 && second >= 0)
        {
            time = true;
        }
        else
        {
            time = false;
        }
    }
    else
    {
        time = false;
    }

    std::cout << time << '\n';

    return 0;
}

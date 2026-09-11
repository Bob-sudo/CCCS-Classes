//File: a10q02.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    double num, sum = 0, min = 0, max = 0, temp;
    int terms = 1;

    while(num > 0 || num < 0)
    {
        std::cin >> num;

        
        sum += num;

        if(min == 0 && max == 0)
        {
            min = num;
            max = num;
        }
        if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }
        if(min > max)
        {
            temp = min;
            min = max;
            max = temp;
        }
        
        
        if(num == 0)
        {
            if(terms == 1)
            {
                std::cout << "no data has been entered" << '\n';
            }
            break;
        }

        std::cout << terms << ' ' << std::fixed << std::setprecision(5) << sum << ' ' <<  (sum / terms) << ' ' << min << ' ' << max << '\n';

        terms++;
    }
}

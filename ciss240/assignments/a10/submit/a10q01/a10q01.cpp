//File: a10q01
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    int type;
    double salary, hourly, overtimePay, hours, overtime;

    while(type != -1 || hours != -1)
    {
        std::cout << "Employee type: ";
        std::cin >> type;
        if(type == -1)
        {
            break;
        }
        std::cout << "Hours of work: ";
        std::cin >> hours;
        if(hours == -1)
        {
            break;
        }
        
        if(hours > 40)
        {
            overtime = hours - 40;
            hours -= overtime;
        }

        switch(type)
        {
            case 0:
                salary = 1000;
                hourly = 10.5;
                overtimePay = 12.0;
                std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << '\n';
                std::cout << "Total: $" << std::fixed << std::setprecision(2) << salary + (hourly * hours) + (overtimePay * overtime) << '\n';
                break;
            case 1:
                salary = 960.5;
                hourly = 8.5;
                overtimePay = 11.5;
                std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << '\n';
                std::cout << "Total: $" << std::fixed << std::setprecision(2) << salary + (hourly * hours) + (overtimePay * overtime) << '\n';
                break;
            case 2:
                salary = 0;
                hourly = 6.1;
                overtimePay = 7.0;
                std::cout << "Salary: $" << std::fixed << std::setprecision(2) << (hourly * hours) + (overtimePay * overtime) << '\n';
                std::cout << "Total: $" << std::fixed << std::setprecision(2) << salary + (hourly * hours) + (overtimePay * overtime) << '\n';
                break;
        }
        std::cout << '\n';
    }
    
    
}

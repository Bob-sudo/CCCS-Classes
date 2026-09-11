//File: a06q03.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    if(pow(b, 2) - 4 * (a * c) < 0)
    {
        std::cout << std::fixed << std::setprecision(5) << -b / (2 * a) << " - " << (sqrt(4 * a * c - pow(b, 2))) / (2 * a) << 'i' << ", ";
        std::cout << std::fixed << std::setprecision(5) << -b / (2 * a) << " + " << (sqrt(4 * a * c - pow(b, 2))) / (2 * a) << 'i' << '\n';
    }

    else if(pow(b, 2) - 4 * (a * c) >= 0)
    {
        std::cout << std::fixed << std::setprecision(5) << ((-b - sqrt(pow(b, 2) - 4 * a * c))) / (2 * a) << ", ";
        std::cout << std::fixed << std::setprecision(5) << ((-b + sqrt(pow(b, 2) - 4 * a * c))) / (2 * a) << '\n';
    }
}

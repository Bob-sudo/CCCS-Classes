//File: a05q01.cpp
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    bool is_rt_angle_traingle = pow(a, 2) + pow(b, 2) == pow(c, 2);

    std::cout << is_rt_angle_traingle << '\n';

    return 0;
}

//File: a06q04.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    bool overlap = false;

    if(c >= a && c <= b || d >= a && d <= b)
    {
        overlap = true;
    }

    std::cout << overlap << '\n';

    return 0;
}

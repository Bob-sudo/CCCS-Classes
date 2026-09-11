//File: a08q03.cpp
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    do
    {
        if(a * pow(e, 3) + b * pow(e, 2) + c * (e) + d == 0)
        {
            std::cout << e << ' ';
        }

        e++;
    }while (e <= f);

    std::cout << '\n';

    return 0;
}

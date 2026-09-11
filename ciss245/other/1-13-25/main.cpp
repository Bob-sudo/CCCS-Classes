#include <iostream>

int gcd(int a, int b)
{
    for(int d = (a >= b ? a : b); d >= 1; d--)
    {
        if (a % d == 0 && b % d == 0)
        {
            return d;
        }
    }
    return 0;
}

void addfraction(int a0, int b0,
                 int a1, int b1,
                 int & a2, int & b2)
{
    a2 = a0 * b1 + b0 * a1;
    b2 = b0 * b1;
    int g = gcd(a2,b2);
    a2 = a2 / g;
    b2 = b2 / g;
    return;
}

int main()
{
    int a0, b0,
        a1, b1,
        a2, b2; // result of sum of a0/b0 and a1/b1

    std::cin >> a0 >> b0 >> a1 >> b1;
    addfraction(a0, b0,
                a1, b1,
                a2, b2);
    
    std::cout << a0 << '/' <<b0
              << " + "
              << a1 << '/' << b1
              << " = "
              << a2 << '/' << b2
              << '\n';

    return 0;
}

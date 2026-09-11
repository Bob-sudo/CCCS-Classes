// Name: Ethan Graham
// File: a03q01.cpp

#include <iostream>

double pow_rec(double a, int n)
{
    if (n == 0) // modify base condition
    {
        double ret = 1; // set ret to correct value
        std::cout << "pow_rec(" << a << ", " << n << ") base case ... return "
                  << ret << '\n';
        return ret;
    }
    else
    {
        std::cout << "pow_rec(" << a << ", " << n << ") recursive case ...\n";
        double ret = pow_rec(a, n - 1) * a; // set ret to correct value
        std::cout << "pow_rec(" << a << ", " << n << ") recursive case ... "
                  << "return " << ret << '\n';
        return ret;
    }
}

int main()
{
    double a;
    int n;
    std::cin >> a >> n;
    double p = pow_rec(a, n);
    std::cout << p << '\n';
    return 0;
}

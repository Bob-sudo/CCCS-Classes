// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include "Rational.h"

void test_input()
{
    Rational r;
    std::cin >> r;
    std::cout << r.get_n() << ' ' << r.get_d() << std::endl;
}

void test_output()
{
    int n = 0, d = 0;
    std::cin >> n >> d;
    std::cout << Rational(n, d) << std::endl;
}

void test_reduce_method()
{
    Rational r;
    std::cin >> r;
    r.reduce();
    std::cout << r << std::endl;
}

void test_reduce_function()
{
    Rational r;
    std::cin >> r;
    reduce(r);
    std::cout << r << std::endl;
}

void test_eq()
{
    Rational r, s;
    std::cin >> r >> s;
    std::cout << (r == s) << std::endl;
}

int main()
{
    int option = 0;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_input();
            break;
        case 2:
            test_output();
            break;
        case 3:
            test_reduce_method();
            break;
        case 4:
            test_reduce_function();
            break;
    }
    return 0;
}

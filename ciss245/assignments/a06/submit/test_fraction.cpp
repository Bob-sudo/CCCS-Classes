// Author: Ethan Graham
// File : test_fraction.cpp

#include <iostream>
#include "Fraction.h"

void test_print()
{
    int n = 0, d = 0;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n, d);
    std::cout << f << std::endl;
}

void test_add()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = get_Fraction(n0, d0);
    Fraction r1 = get_Fraction(n1, d1);
    std::cout << (r0 + r1) << std::endl;
}

void test_subtract()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = get_Fraction(n0, d0);
    Fraction r1 = get_Fraction(n1, d1);
    std::cout << (r0 - r1) << std::endl;
}

void test_mult()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = get_Fraction(n0, d0);
    Fraction r1 = get_Fraction(n1, d1);
    std::cout << (r0 * r1) << std::endl;
}

void test_divide()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = get_Fraction(n0, d0);
    Fraction r1 = get_Fraction(n1, d1);
    std::cout << (r0 / r1) << std::endl;
}

void test_eq()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    std::cout << (f == g) << std::endl;
}

void test_neq()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    std::cout << (f != g) << std::endl;
}

void test_reduce()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n, d);
    reduce(f);
    std::cout << f << std::endl;
}

void test_get_fraction()
{
    int n, d;
    std::cin >> n >> d;
    std::cout << get_Fraction(n, d) << std::endl;
}

void test_get_n()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n, d);
    std::cout << get_n(f) << std::endl;
}

void test_get_d()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n, d);
    std::cout << get_d(f) << std::endl;
}

void test_set_n()
{
    Fraction f = get_Fraction(1, 2);
    int n;
    std::cin >> n;
    set_n(f, n);
    std::cout << get_n(f) << std::endl;
}

void test_set_d()
{
    Fraction f = get_Fraction(1, 2);
    int d;
    std::cin >> d;
    set_d(f, d);
    std::cout << get_d(f) << std::endl;
}

void test_set()
{
    Fraction f;
    int n, d;
    std::cin >> n >> d;
    set(f, n, d);
    std::cout << f << std::endl;
}

void test_get_int()
{
    int n, d;
    std::cin >> n >> d;
    std::cout << get_int(get_Fraction(n, d)) << std::endl;
    return;
}

void test_get_double()
{
    double n, d;
    std::cin >> n >> d;
    std::cout << get_double(get_Fraction(n, d)) << std::endl;
    return;
}

void test_addeq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0;
    std::cin >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    f += g;
    std::cout << f << std::endl;
}

void test_subeq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0;
    std::cin >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    f -= g;
    std::cout << f << std::endl;
}

void test_multeq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0;
    std::cin >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    f *= g;
    std::cout << f << std::endl;
}

void test_diveq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0;
    std::cin >> n1 >> d1;
    Fraction f = get_Fraction(n0, d0);
    Fraction g = get_Fraction(n1, d1);
    f /= g;
    std::cout << f << std::endl;
}

int main()
{
    int option;
    std::cin >> option;
    
    switch (option)
    {
        case 1:
            test_print();
            break;
        case 2:
            test_add();
            break;
        case 3:
            test_subtract();
            break;
        case 4:
            test_mult();
            break;
        case 5:
            test_divide();
            break;
        case 6:
            test_eq();
            break;
        case 7:
            test_neq();
            break;
        case 8:
            test_reduce();
            break;
        case 9:
            test_get_fraction();
            break;
        case 10:
            test_get_n();
            break;
        case 11:
            test_get_d();
            break;
        case 12:
            test_set_n();
            break;
        case 13:
            test_set_d();
            break;
        case 14:
            test_set();
            break;
        case 15:
            test_get_int();
            break;
        case 16:
            test_get_double();
            break;
        case 17:
            test_addeq();
            break;
        case 18:
            test_subeq();
            break;
        case 19:
            test_multeq();
            break;
        case 20:
            test_diveq();
            break;
    }
    
    return 0;
}

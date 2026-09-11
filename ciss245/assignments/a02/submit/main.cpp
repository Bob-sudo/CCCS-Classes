// File: a02q01.cpp
// Name: Ethan Graham

#include <iostream>
#include "Fraction.h"

void test_Fraction_print()
{
    int xn = 0, xd = 0; // numerator and denominator of a fraction
    std::cin >> xn >> xd;
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_add()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd
    std::cin >> yn >> yd >> zn >> zd;
    Fraction_add(xn, xd, yn, yd, zn, zd);
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_sub()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd
    std::cin >> yn >> yd >> zn >> zd;
    Fraction_sub(xn, xd, yn, yd, zn, zd);
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_mult()
{
    int xn, xd, yn, yd, zn, zd;
    std::cin >> yn >> yd >> zn >> zd;
    Fraction_mult(xn, xd, yn, yd, zn, zd);
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_div()
{
    int xn, xd, yn, yd, zn, zd;
    std::cin >> yn >> yd >> zn >> zd;
    Fraction_div(xn, xd, yn, yd, zn, zd);
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_eq()
{
    int yn, yd, zn, zd;
    std::cin >> yn >> yd >> zn >> zd;
    std::cout << Fraction_eq(yn, yd, zn, zd) << std::endl;
}

void test_Fraction_neq()
{
    int yn, yd, zn, zd;
    std::cin >> yn >> yd >> zn >> zd;
    std::cout << Fraction_neq(yn, yd, zn, zd) << std::endl;
}

void test_Fraction_lt()
{
    int yn, yd, zn, zd;
    std::cin >> yn >> yd >> zn >> zd;
    std::cout << Fraction_lt(yn, yd, zn, zd) << std::endl;
}

void test_Factorize_Polynomial()
{
    int an, ad, bn, bd, cn, cd;
    std::cin >> an >> ad >> bn >> bd >> cn >> cd;
    Factorize_Polynomial(an, ad, bn, bd, cn, cd);
}

int main()
{
    int option;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_Fraction_print();
            break;
        case 2:
            test_Fraction_add();
            break;
        case 3:
            test_Fraction_sub();
            break;
        case 4:
            test_Fraction_mult();
            break;
        case 5:
            test_Fraction_div();
            break;
        case 6:
            test_Fraction_eq();
            break;
        case 7:
            test_Fraction_neq();
            break;
        case 8:
            test_Fraction_lt();
            break;
        case 9:
            test_Factorize_Polynomial();
            break;
    }
    return 0;
}

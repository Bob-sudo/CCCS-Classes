/*********************************************************************

File : main.cpp
Author: Ethan Graham
Date : 3/4/2025
Description
This is the test program for the vec2d class.

**********************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "vec2d.h"

void test_vec2d_double_double()
{
    double x, y;
    std::cin >> x >> y;
    std::cout << vec2d(x, y) << std::endl;
}

void test_eq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u == v) << std::endl;
}

void test_neq() // Tests != operator
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u != v) << std::endl;
}

void test_bracket_const()
{
    vec2d u;
    std::cin >> u;
    std::cout << u[0] << ' ' << u[1] << std::endl;
}

void test_bracket()
{
    vec2d u;
    double x = 0, y = 0;
    std::cin >> x >> y;
    u[0] = x;
    u[1] = y;
    std::cout << u << std::endl;
}

void test_plus()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u + v) << std::endl;
}

void test_pluseq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u += v) << ' ';
    std::cout << u << ' ';
    std::cout << ((u += v) += v) << ' ';
    std::cout << u << std::endl;
}

void test_minus()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u - v) << std::endl;
}

void test_minuseq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u -= v) << ' ';
    std::cout << u << ' ';
    std::cout << ((u -= v) -= v) << ' ';
    std::cout << u << std::endl;
}

void test_multeq()
{
    vec2d u;
    double c = 0;
    std::cin >> u >> c;
    std::cout << (u *= c) << std::endl;
} 

void test_mult()
{
    vec2d u;
    double c = 0;
    std::cin >> u >> c;
    std::cout << u * c << std::endl;
}

void test_diveq()
{
    vec2d u;
    double c = 0;
    std::cin >> u >> c;
    std::cout << (u /= c) << std::endl;
} 

void test_div()
{
    vec2d u;
    double c = 0;
    std::cin >> u >> c;
    std::cout << u / c << std::endl;
}

void test_length()
{
    vec2d v(3, 4);
    std::cout << v.len() << std::endl;
}

void test_norm()
{
    vec2d v(3, 4);
    std::cout << norm(v) << std::endl;
}

void test_dot_prod()
{
    vec2d u(1, 3), v(2, 4);
    std::cout << dotprod(u, v) << std::endl;
}

void test_double_mult()
{
    vec2d u;
    double c = 0;
    std::cin >> u >> c;
    std::cout << c * u << std::endl;
}

int main()
{
    int option;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_vec2d_double_double();
            break;
        case 5:
            test_eq();
            break;
        case 6:
            test_neq();
            break;
        case 11:
            test_bracket_const();
            break;
        case 12:
            test_bracket();
            break;
        case 13:
            test_plus();
            break;
        case 14:
            test_pluseq();
            break;
        case 16:
            test_minus();
            break;
        case 17:
            test_minuseq();
            break;
        case 19:
            test_multeq();
            break;
        case 20:
            test_mult();
            break;
        case 21:
            test_multeq();
            break;
        case 22:
            test_mult();
            break;
        case 23:
            test_length();
            break;
        case 24:
            test_double_mult();
            break;
        case 25:
            test_length();
            break;
        case 26:
            test_dot_prod();
            break;
        case 27:
            test_norm();
            break;
            
    }
    return 0;
}

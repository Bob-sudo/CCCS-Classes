// File: main.cpp
// Name: Ethan Graham

// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include <cmath>
#include "vec2.h"

void test_vec2()
{
    vec2<int> v1(1, 2);
    std::cout << "vec2<int>: " << v1 << std::endl;

    vec2<float> v2(1.5f, 2.5f);
    std::cout << "vec2<float>: " << v2 << std::endl;

    vec2<double> v3(3.14, 2.71);
    std::cout << "vec2<double>: " << v3 << std::endl;

    vec2<char> v4('A', 'B');
    std::cout << "vec2<char>: " << v4 << std::endl;
}

void test_eq()
{
    vec2<int> a(1, 2), b(1, 2);
    std::cout << "int: " << (a == b) << std::endl;

    vec2<float> c(1.1f, 2.2f), d(3.3f, 4.4f);
    std::cout << "float: " << (c == d) << std::endl;

    vec2<double> e(1.11, 2.22), f(1.11, 2.22);
    std::cout << "double: " << (e == f) << std::endl;

    vec2<char> g('A', 'B'), h('A', 'D');
    std::cout << "char: " << (g == h) << std::endl;
}

void test_neq()
{
    vec2<int> a(1, 2), b(1, 2);
    std::cout << "int: " << (a != b) << std::endl;

    vec2<float> c(1.1f, 2.2f), d(3.3f, 4.4f);
    std::cout << "float: " << (c != d) << std::endl;

    vec2<double> e(1.11, 2.22), f(1.11, 2.22);
    std::cout << "double: " << (e != f) << std::endl;

    vec2<char> g('A', 'B'), h('A', 'D');
    std::cout << "char: " << (g != h) << std::endl;
}

void test_bracket_const()
{
    vec2<int> v;
    std::cin >> v;

    std::cout << "v[0] = " << v[0] << ", v[1] = " << v[1] << std::endl;

    try
    {
        std::cout << v[42] << '\n';
    }
    catch (ValueError & e)
    {
        std::cout << "caught ValueError object\n";
    }
}

void test_bracket()
{
    vec2<int> v;
    int x, y;
    std::cin >> x >> y;
    v[0] = x;
    v[1] = y;
    std::cout << "Updated: " << v << std::endl;

    try
    {
        std::cout << v[42] << '\n';
    }
    catch (ValueError & e)
    {
        std::cout << "caught ValueError object\n";
    }
}

void test_plus()
{
    vec2<int> a(1, 2), b(3, 4);
    std::cout << "int: " << (a + b) << std::endl;

    vec2<float> c(1.1f, 2.2f), d(3.3f, 4.4f);
    std::cout << "float: " << (c + d) << std::endl;

    vec2<double> e(1.11, 2.22), f(1.11, 2.22);
    std::cout << "double: " << (e + f) << std::endl;

    vec2<char> g('A', 'B'), h(1, 2);
    std::cout << "char: " << (g + h) << std::endl;
}

void test_pluseq()
{
    vec2<int> a(1, 2), b(3, 4);
    std::cout << "int: " << (a += b) << std::endl;

    vec2<float> c(1.1f, 2.2f), d(3.3f, 4.4f);
    std::cout << "float: " << (c += d) << std::endl;

    vec2<double> e(1.11, 2.22), f(1.11, 2.22);
    std::cout << "double: " << (e += f) << std::endl;

    vec2<char> g('A', 'B'), h(1, 2);
    std::cout << "char: " << (g += h) << std::endl;
}

void test_minus()
{
    vec2<int> a(4, 3), b(1, 1);
    std::cout << "int: " << (a - b) << std::endl;

    vec2<float> c(4.4f, 2.2f), d(1.1f, 1.1f);
    std::cout << "float: " << (c - d) << std::endl;

    vec2<double> e(5.5, 5.5), f(2.2, 2.2);
    std::cout << "double: " << (e - f) << std::endl;

    vec2<char> g('C', 'D'), h(1, 1);
    std::cout << "char: " << (g - h) << std::endl;
}

void test_minuseq()
{
    vec2<int> a(4, 3), b(1, 1);
    std::cout << "int: " << (a -= b) << std::endl;

    vec2<float> c(4.4f, 2.2f), d(1.1f, 1.1f);
    std::cout << "float: " << (c -= d) << std::endl;

    vec2<double> e(5.5, 5.5), f(2.2, 2.2);
    std::cout << "double: " << (e -= f) << std::endl;

    vec2<char> g('C', 'D'), h(1, 1);
    std::cout << "char: " << (g -= h) << std::endl;
}

void test_multeq()
{
    vec2<int> a(2, 3);
    std::cout << "int: " << (a *= 2) << std::endl;

    vec2<float> b(1.5f, 2.0f);
    std::cout << "float: " << (b *= 2.0f) << std::endl;

    vec2<double> c(1.5, 2.0);
    std::cout << "double: " << (c *= 2.0) << std::endl;

    vec2<char> d(2, 3);
    std::cout << "char: " << (d *= 2) << std::endl;
}

void test_mult()
{
    vec2<int> a(2, 3);
    std::cout << "int: " << (a * 2) << std::endl;

    vec2<float> b(1.5f, 2.0f);
    std::cout << "float: " << (b * 2.0f) << std::endl;

    vec2<double> c(1.5, 2.0);
    std::cout << "double: " << (c * 2.0) << std::endl;

    vec2<char> d(2, 3);
    std::cout << "char: " << (d * 2) << std::endl;
}

void test_diveq()
{
    vec2<int> a(4, 8);
    std::cout << "int: " << (a /= 2) << std::endl;

    vec2<float> b(4.4f, 8.8f);
    std::cout << "float: " << (b /= 2.0f) << std::endl;

    vec2<double> c(4.4, 8.8);
    std::cout << "double: " << (c /= 2.0) << std::endl;

    vec2<char> d(4, 8);
    std::cout << "char: " << (d /= 2) << std::endl;
}

void test_div()
{
    vec2<int> a(4, 8);
    std::cout << "int: " << (a / 2) << std::endl;

    vec2<float> b(4.4f, 8.8f);
    std::cout << "float: " << (b / 2.0f) << std::endl;

    vec2<double> c(4.4, 8.8);
    std::cout << "double: " << (c / 2.0) << std::endl;

    vec2<char> d(4, 8);
    std::cout << "char: " << (d / 2) << std::endl;
}

void test_length()
{
    std::cout << vec2<int>(3, 4).len() << std::endl;
    std::cout << vec2<float>(3.0f, 4.0f).len() << std::endl;
    std::cout << vec2<double>(3.0, 4.0).len() << std::endl;
    std::cout << vec2<char>(3, 4).len() << std::endl;
}

void test_norm()
{
    std::cout << norm(vec2<int>(3, 4)) << std::endl;
    std::cout << norm(vec2<float>(3.0f, 4.0f)) << std::endl;
    std::cout << norm(vec2<double>(3.0, 4.0)) << std::endl;
}

void test_dot_prod()
{
    std::cout << dotprod(vec2<double>(1, 3), vec2<double>(2, 4)) << std::endl;
}

void test_double_mult()
{
    vec2<double> u;
    double c;
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
            test_vec2();
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
            test_diveq();
            break;
        case 22:
            test_div();
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

/************************************************************************************
 * File : testIntDynArr.cpp
 * Author: Ethan Graham
 *
 * Description: This is the test program for the IntDynArr class.
 ***********************************************************************************/
#include <iostream>
#include "IntDynArr.h"
#define SIZE(x) (sizeof(x)/sizeof(int))

void test_IntDynArr()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a << std::endl;
}

void test_IntDynArr_size()
{
    int size;
    std::cin >> size;
    IntDynArr a(size);
    std::cout << a << std::endl;
}

void test_IntDynArr_array()
{
    int x[] = {1, 2, -4, 0};
    IntDynArr a(SIZE(x), x);
    std::cout << a << std::endl;
}

void test_print()
{
    int x[] = {1, 2, -4, 0};
    IntDynArr a(SIZE(x), x);
    std::cout << a << std::endl;
}

void test_size()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a.get_size() << std::endl;
}

void test_get_capacity()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a.get_capacity() << std::endl;
}

void test_eq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a == b) << std::endl;
}

void test_neq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a != b) << std::endl;
}

void test_copy()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    a = b;
    std::cout << a << std::endl;
}

void test_resize()
{
    IntDynArr a;
    int r;
    std::cin >> a;
    std::cin >> r;
    a.resize(r);
    std::cout << a.get_size() << std::endl;
}

void test_bracket()
{
    IntDynArr a;
    std::cin >> a;
    a[0] = 3;
    std::cout << a << std::endl;
}

void test_plus_eq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a += b) << ' ';
    std::cout << a << ' ';
    std::cout << ((a += b) += b) << std::endl;
}

void test_plus()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << a + b << std::endl;
}

void test_insert()
{
    IntDynArr a;
    std::cin >> a;
    int val, i;
    std::cin >> i >> val;
    a.insert(i, val);
    std::cout << a << std::endl;
}

void test_remove()
{
    IntDynArr a;
    int i;
    std::cin >> a >> i;
    std::cout << a << ' ' << a.remove(i) << std::endl;
}

void test_subarray()
{
    IntDynArr a;
    std::cin >> a;
    int i, len;
    std::cin >> i >> len;
    std::cout << a.subarray(i, len) << std::endl;
}

int main()
{
    int option;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_IntDynArr();
            break;
        case 2:
            test_IntDynArr_size();
            break;
        case 3:
            test_IntDynArr_array();
            break;
        case 7:
            test_eq();
            break;
        case 8:
            test_neq();
            break;
        case 9:
            test_copy();
            break;
        case 12:
            test_resize();
            break;
        case 13:
            test_bracket();
            break;
        case 14:
            test_plus_eq();
            break;
        case 15:
            test_plus();
            break;
        case 16:
            test_insert();
            break;
        case 17:
            test_remove();
            break;
        case 18:
            test_subarray();
            break;
        case 19:
            test_print();
            break;
    }
    return 0;
}

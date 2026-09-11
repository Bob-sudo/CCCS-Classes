//File: a07q01.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int num1, num2;
    std::cin >> num1 >> num2;

    int a = num1 / 100, b = (num1 / 10) % 10, c =  num1 % 10, d = num2 / 100, e = (num2 / 10) % 10, f = num2 % 10;

    //test 1
    if(a + d < 10 && b + e < 10 && c + f < 10 && d > 0 && a > 0)
    {
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "  " << a + d << ' ' << b + e << ' ' << c + f << '\n';
        std::cout << "-------" << '\n';
    }
    //test 2
    else if(d == 0 && e > 0 && a > 0 &&  b + e < 10 && c + f < 10)
    {
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+   " << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "  " << a << ' ' << b + e << ' ' << c + f << '\n';
        std::cout << "-------" << '\n';
    }
    //test 3
    else if(d == 0 && e == 0 && c + f < 10)
    {
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+     " << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "  " << a << ' ' << b << ' ' << c + f << '\n';
        std::cout << "-------" << '\n';
    }
    //test 4 and 5
    else if(a == 0 && d == 0 && b > 0 && e > 0 && b + e < 10 && c + f < 10)
    {
        std::cout << "    " << b << ' ' << c << '\n';
        std::cout << "+   " << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "    " << b + e << ' ' << c + f << '\n';
        std::cout << "-------" << '\n';
    }
    //test 6
    else if(a == 0 && b == 0 && d == 0 && e > 0 && f + c < 10)
    {
        std::cout << "      " << c << '\n';
        std::cout << "+   " << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "    " << e << ' ' << c + f << '\n';
        std::cout << "-------" << '\n';
    }
    //test 7
    else if(a == 0 && d == 0 && b + e < 10 && c + f >= 10)
    {
        std::cout << "    1  " << '\n';
        std::cout << "    " << b << ' ' << c << '\n';
        std::cout << "+   " << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "    " << b + e + 1 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 8
    else if(a == 0 && d == 0 && b + e >= 10 && c + f >= 10)
    {
        std::cout << "  1 1  " << '\n';
        std::cout << "    " << b << ' ' << c << '\n';
        std::cout << "+   " << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "  " << 1 << ' ' << (b + e + 1) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 9
    else if(a == 0 && d > 0 && d + 1 < 10 &&  b + e >= 10 && c + f >= 10)
    {
        std::cout << "  1 1  " << '\n';
        std::cout << "    " << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << "  " << d + 1 << ' ' << (b + e + 1) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 10
    else if(a == 0 && d > 0 && d + 1 >= 10 &&  b + e >= 10 && c + f >= 10)
    {
        std::cout << "  1 1  " << '\n';
        std::cout << "    " << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << 1 << ' ' << (d + 1) % 10 << ' ' << (b + e + 1) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 11
    else if(a > 0 && d > 0 && a + d >= 10 &&  b + e >= 10 && c + f >= 10)
    {
        std::cout << "  1 1  " << '\n';
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << 1 << ' ' << (d + a + 1) % 10 << ' ' << (b + e + 1) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 12
    else if(a > 0 && d > 0 && a + d >= 10 &&  b + e >= 10 && c + f < 10)
    {
        std::cout << "  1    " << '\n';
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << 1 << ' ' << (d + a + 1) % 10 << ' ' << (b + e) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    //test 13
    else if(a > 0 && d > 0 && a + d >= 10 &&  b + e < 10 && c + f < 10)
    {
        std::cout << "  " << a << ' ' << b << ' ' << c << '\n';
        std::cout << "+ " << d << ' ' << e << ' ' << f << '\n';
        std::cout << "-------" << '\n';
        std::cout << 1 << ' ' << (d + a) % 10 << ' ' << (b + e) % 10 << ' ' << (c + f) % 10 << '\n';
        std::cout << "-------" << '\n';
    }
    
    return 0;
}

//File: a06q06.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int num1, num2;
    std::cin >> num1 >> num2;

    int a = num1 / 10, b = num1 % 10, c = num2 / 10, d = num2 % 10;
    
    if(a + c < 10 && b + d < 10)
    {
        std::cout << "  " << a << ' ' << b << '\n';
        std::cout << "+ " << c << ' ' << d << '\n';
        std::cout << "-----" << '\n';
        std::cout << "  " << a + c << ' ' << b + d << '\n';
        std::cout << "-----" << '\n';
    }
    else if(a + c < 10 && b + d >= 10)
    {
        std::cout << "  1  " << '\n';
        std::cout << "  " << a << ' ' << b << '\n';
        std::cout << "+ " << c << ' ' << d << '\n';
        std::cout << "-----" << '\n';
        std::cout << "  " << a + c + 1<< ' ' << (b + d) % 10 << '\n';
        std::cout << "-----" << '\n';
    }
    else if(a + c >= 10 && b + d < 10)
    {
        std::cout << "  " << a << ' ' << b << '\n';
        std::cout << "+ " << c << ' ' << d << '\n';
        std::cout << "-----" << '\n';
        std::cout << (a + c) / 10 << ' ' << (a + c) % 10 << ' ' << (b + d) % 10 << '\n';
        std::cout << "-----" << '\n';
    }
    else if(a + c >= 10 && b + d >= 10)
    {
        std::cout << "  1  " << '\n';
        std::cout << "  " << a << ' ' << b << '\n';
        std::cout << "+ " << c << ' ' << d << '\n';
        std::cout << "-----" << '\n';
        std::cout << (a + c) / 10 << ' ' << (a + c + 1) % 10 << ' ' << (b + d) % 10 << '\n';
        std::cout << "-----" << '\n';
    }

    return 0;
}

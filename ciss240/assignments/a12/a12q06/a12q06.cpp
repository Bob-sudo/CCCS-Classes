//File: a12q06.cpp
//Name: Ethan Graham

#include <iostream>

int T(int n)
{
    return (n % 2 == 0) ? (n / 2) : (3 * n + 1);
}

void print_3x_plus_1(int n)
{
    while (n != 1)
    {
        std::cout << n << " ";
        n = T(n);
    }
    
    std::cout << 1 << std::endl;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    
    for (int n = a; n <= b; ++n)
    {
        print_3x_plus_1(n);
    }
    
    return 0;
}

// File: a02q01.cpp
// Name: Ethan Graham

#include <iostream>

int f(int n)
{
    int count = 0;
    std::cout << n << ' ';
    if(n > 1)
    {
        count++;
        count += (n % 2 == 0 ? f(n / 2) : f((3*n) + 1));
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << f(n) << '\n';
    return 0;
}

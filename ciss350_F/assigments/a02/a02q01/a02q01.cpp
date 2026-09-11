// Name: Ethan Graham
// File: a02q01.cpp

#include <iostream>

int f(int n)
{
    if (n % 2 == 0)
    {
        n /= 2;
        return n;
    }
    else if(n % 2 != 0 && n > 1)
    {
        n *= 3;
        n++;
        return n;
    }
    
    return 1;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << n << ' ';

    int count = 1;

    while(1)
    {
        if (n == 1)
        {
            count--;
            break;
        }
        n = f(n);
        std::cout << n << ' ';
        count++;
        
    }

    std::cout << count << '\n';
}

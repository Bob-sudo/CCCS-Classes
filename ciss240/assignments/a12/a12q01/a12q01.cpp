//File: a12q01.cpp
//Name: Ethan Graham

#include <iostream>

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int i;
    std::cin >> i;
    std::cout << i << (isprime(i) ? " is prime" : " is not prime") << '\n';

    return 0;
}

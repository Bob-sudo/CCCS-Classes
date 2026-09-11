// Name: Ethan Graham
// File: a01q03.cpp

#include <iostream>

bool is_prime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int next_prime(int p)
{
    int q = p + 1;
    while (!is_prime(q))
    {
        q++;
    }
    return q;
}

int main()
{
    int n;
    std::cin >> n;

    if(n == 1)
    {
        std::cout << 1 << '\n';
        return 0;
    }

    int temp = n;
    int p = 2;
    int first = true;
    
    while (temp > 1)
    {
        if (temp % p == 0)
        {
            int count = 0;
            
            while (temp % p == 0)
            {
                temp /= p;
                count++;
            }

            if (!first) std::cout << " * ";
            std::cout << p;
            if (count > 1) std::cout << "^" << count;

            first = false;
        }
        p = next_prime(p);
    }

    std::cout << '\n';
    return 0;
}

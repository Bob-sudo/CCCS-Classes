// File: a04q05.cpp
// Name: Ethan Graham

#include <iostream>

int pi(double x)
{
    int n = x;
    int * p;
    
    // Allocate an array of size n for p to point to.
    p = new int[n + 1];

    for (int i = 0; i <= n; ++i)
    {
        p[i] = 0;
    }
    p[0] = p[1] = 1; 
    
    // Perform the sieve of Eratosthenes on the array that p points to.
    for (int i = 2; i * i <= n; ++i)
    {
        if (p[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = 1;
            }
        }
    }
    // Count the number of primes in the array that p points to and store
    // in ret.
    int ret = 0;

    for (int i = 2; i <= n; ++i)
    {
        if (p[i] == 0)
        {
            ++ret;
        }
    }
    
    // Deallocate the memory used by p.
    delete[] p;
    
    return ret;
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << pi(x) << '\n';
    return 0;
}

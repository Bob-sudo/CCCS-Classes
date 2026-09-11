//File: a12q02.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

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
    int A, B, C, N;
    std::cin >> A >> B >> C >> N;

    int max_primes = 0;
    int largest_a, largest_b, largest_c;

    for(int a = 1; a <= A; a++)
    {
        for(int b = 1; b <= B; b++)
        {
            for(int c = 1; c <= C; c++)
            {
                int prime_count = 0;

                for(int x = 0; x <= N; x++)
                {
                    int p = (a * x * x) + (b * x) + c;
                    if(isprime(p))
                    {
                        prime_count++;
                    }
                }

                std::cout << std::setw(5) << a << "x^2 + "
                          << std::setw(5) << b << "x + "
                          << std::setw(5) << c << ": "
                          << std::setw(5) << prime_count << '\n';

                //check if polynomial generates the most primes
                if(prime_count > max_primes || (prime_count == max_primes &&
                   (a < largest_a || (a == largest_a && b < largest_b) ||
                    (a == largest_a && b == largest_b && c < largest_c))))
                {
                    max_primes = prime_count;
                    largest_a = a;
                    largest_b = b;
                    largest_c = c;
                }
            }
        }
    }
    
    std::cout << "largest" << '\n'
              << std::setw(5) << largest_a << "x^2 + "
              << std::setw(5) << largest_b << "x + "
              << std::setw(5) << largest_c << ": "
              << std::setw(5) << max_primes << '\n';
    
    return 0;
}

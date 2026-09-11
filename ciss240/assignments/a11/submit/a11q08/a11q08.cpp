//File: a11q08.cpp
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    const int SIZE = 100000;
    const int num = 1299709;   // Maximum number to check for prime generation
    int primes[SIZE];         
    int primeCount = 0;
    bool isPrime[num + 1] = {false};
    
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= std::sqrt(num); i++)
    {
        if(isPrime[i] == false)
        { 
            for(int j = i * i; j <= num; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    // Store the first 100,000 primes
    std::cout << "building prime table of 100,000 primes ...\n";
    for(int i = 2; i <= num && primeCount < SIZE; i++)
    {
        if(isPrime[i] == false)
        {
            primes[primeCount++] = i; 
        }
    }

    // Print the first 5 and last 5 primes
    std::cout << "primes: ";
    for(int i = 0; i < 5; i++)
    {
        std::cout << primes[i] << ", ";
    }
    std::cout << "... ";
    for(int i = primeCount - 5; i < primeCount; i++)
    {
        if(i != primeCount - 5) std::cout << ", ";
        std::cout << primes[i];
    }
    std::cout << "\n";

    
    int x, i;
    while (true)
    {        
        std::cin >> x;
        if (x == -1)
        {
            break;
        }

        std::cin >> i;

        // Option 0
        if(i == 0)
        {  
            int left = 0, right = primeCount - 1;
            bool found = false;
            int pos = -1;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(primes[mid] == x)
                {
                    found = true;
                    pos = mid;
                    break;
                }
                else if (primes[mid] < x)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            if(found)
            {
                std::cout << x << " is prime # " << pos + 1 << "\n";
            }
            else
            {
                std::cout << x << " is not a prime\n";
            }
        }

        //Option 1
        if (i == 1)
        {  
            std::cout << x << " = ";

            bool first = true;
            int original_x = x;

            // Factorization using the primes array
            bool isPrime = true;

            for (int j = 0; j < primeCount && primes[j] <= x; j++)
            {
                int count = 0;
                while (x % primes[j] == 0)
                {
                    x /= primes[j];
                    count++;
                }

                if (count > 0)
                {
                    if (!first)
                    {
                        std::cout << " * ";
                    }
                    std::cout << primes[j];
                    if (count > 1)
                    {
                        std::cout << "^" << count;
                    }
                    first = false;
                    isPrime = false; 
                }

                if (x == 1)
                {
                    break; 
                }
            }

            // If x is still greater than 1, it is a prime number
            if (x > 1) {
                if (first == false)
                {
                    std::cout << " * ";
                }
                std::cout << x;
                isPrime = false;
            }

            // If the number is prime and not divisible by any factors
            if (isPrime && original_x != 1)
            {
                std::cout << original_x;
            }

            std::cout << "\n";
            
        }
    }

    return 0;
}







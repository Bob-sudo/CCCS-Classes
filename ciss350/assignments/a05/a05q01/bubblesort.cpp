// File: bubblesort.cpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <chrono>

// Your implementation of the sorting algorithm

template < typename T >

void print(const T * p, const T * q)
{
    std::string delim = "";
    std::cout << '{';
    while(p < q)
    {
        std::cout << delim << *p;
        delim = ", ";
        ++p;
    }
    std::cout << '}' << '\n';
}

template < typename T >

void bubblesort(T * start, T * end, bool verbose)
{
    for(T * i = end; i > start; --i)
    {
        if(verbose)
            print(start, end);
        for(T * j = start; j < i - 1; ++j)
        {
            if((*j) > *(j + 1))
            {
                T temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}

int stringtoint(char s[])
{
    int num = 0;
    int n = strlen(s);

    for(int i = 0; i < n; ++i)
    {
        num = num * 10 + (s[i] - 48);
    }

    return num;
}

int main(int argc, char * argv[])
{
    int seed = stringtoint(argv[1]);;
    srand(seed);

    int n = stringtoint(argv[2]);
    std::vector< int > x(n, 0); // int vector of size n, all zeros
    int m = stringtoint(argv[3]);
    int k = stringtoint(argv[4]);
    
    double total_time = 0.0;
    for (int i = 0; i < k; ++i)
    {
        // Randomize vector x
        for (int i = 0; i < n; ++i)
        {
            x[i] = rand() % m;
        }

        // start timer
        auto start = std::chrono::high_resolution_clock::now();
        bubblesort(&x[0], &x[n], true);
        auto end = std::chrono::high_resolution_clock::now();
        // end timer
        double time = std::chrono::duration<double, std::milli>(end - start).count();
        // total_time += time for this sort
        total_time += time;
    }
    
    //-------------------------------------------------------------------------
    // Print the average runtime.
    // p is the integer from the numeric string argv[5]
    // If p is 1, print the average runtime.
    // If p is 0, the average runtime is not printed.
    //-------------------------------------------------------------------------
    int p = stringtoint(argv[5]);
    // Assign to p the integer value from the numeric string argv[5]
    // If p is 1, print the average runtime.
    if(p == 1)
    {
        std::cout << "Avg. Time: " << total_time / k << " milliseconds" << '\n';
    }
    
    return 0;
}

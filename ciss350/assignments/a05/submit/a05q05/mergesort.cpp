// File: mergesort.cpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <chrono>
#include <iomanip>

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
    std::cout << '}';
}

template < typename T >

void merge(T * start0, T * end0, T * start1, T * end1, std::vector< T > & t)
{
    t.clear();
    
    T * left = start0;
    T * right = start1;

    while(left < end0 && right < end1)
    {
        if(*left <= *right)
        {
            t.push_back(*left);
            ++left;
        }
        else
        {
            t.push_back(*right);
            ++right;
        }
    }

    while(left < end0)
    {
        t.push_back(*left);
        ++left;
    }
    while(right < end1)
    {
        t.push_back(*right);
        ++right;
    }

    for (int i = 0; i < end1 - start0; i++)
    {
        start0[i] = t[i];
    }
}

template < typename T >

void mergesort(T * start, T * end, std::vector< T > & t, bool verbose)
{
    static int spaces = -4;
    spaces += 4;

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "mergesort(";
        print(start, end);
        std::cout << ")\n";
    }
    
    int n = end - start;

    // base case
    if(n <= 1)
    {
        if(verbose)
        {
            std::cout << std::setw(spaces) << "";
            std::cout << "return ";
            print(start, end);
            std::cout << '\n';
            spaces -= 4;
        }
        return;
    }
    
    T * mid = start + n / 2;

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "split(";
        print(start, end);
        std::cout << ") = ";
        print(start, mid);
        std::cout << ", ";
        print(mid, end);
        std::cout << '\n';
    }
    
    
    mergesort(start, mid, t, verbose);
    mergesort(mid, end, t, verbose);

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "merge(";
        print(start, mid);
        std::cout << ", ";
        print(mid, end);
        std::cout << ") = ";
        print(start, end);
        std::cout << '\n';
    }
    
    merge(start, mid, mid, end, t);

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "return ";
        print(start, end);
        std::cout << '\n';
        spaces -= 4;
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

        std::vector < int > t;

        // start timer
        auto start = std::chrono::high_resolution_clock::now();
        mergesort(&x[0], &x[n], t, true);
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

// File: quicksort.cpp

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

T * medianof3(T * start, T * end)
{
    T * mid = (start + (end - start) / 2) - 1;
    T * last = end - 1;

    if(*mid < *start)
        std::swap(*mid, *start);
    if(*last < *mid)
        std::swap(*last, *mid);
    if(*last < *start)
        std::swap(*last, *start);

    return mid;
}

template < typename T >

T * partition(T * start, T * end, T * pivot_index)
{
    std::swap(*start, *pivot_index);
    T pivot_value = *start;
    
    T * j = start + 1;
    for(T * i = start + 1; i < end; ++i)
    {
        if(*i <= pivot_value)
        {
            std::swap(*i, *j);
            ++j;
        }
    }
    std::swap(*start, *(j - 1));
    return (j - 1); 
}

template < typename T >

void quicksort(T * start, T * end, bool verbose)
{
    static int spaces = -4;
    spaces += 4;
    
    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "quicksort(";
        print(start, end);
        std::cout << ")\n";
    }
    
    if(end - start <= 1)
    {
        if(verbose)
        {
            std::cout << std::setw(spaces) << "";
            std::cout << "return "; print(start, end); std::cout << '\n';
            spaces -= 4;
        }
        return;
    }
    
    T * pivot_index = medianof3(start, end);

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "pivot = " << (*pivot_index) << '\n';
        
        std::cout << std::setw(spaces) << "";
        std::cout << "left = "; print(start, pivot_index); std::cout << '\n';
        
        std::cout << std::setw(spaces) << "";
        std::cout << "right = "; print(pivot_index + 1, end); std::cout << '\n';
    }
    
    T * pivot_final = partition(start, end, pivot_index);

    quicksort(start, pivot_final, verbose);
    quicksort(pivot_final + 1, end, verbose);

    if(verbose)
    {
        std::cout << std::setw(spaces) << "";
        std::cout << "combine("; print(start, pivot_final);
        std::cout << ", " << (*pivot_final) << ", ";
        print(pivot_final + 1, end); 
        std::cout << ") = "; print(start, end); std::cout << '\n';

        
        std::cout << std::setw(spaces) << "";
        std::cout << "return "; print(start, end); std::cout << '\n';
    }

    spaces -= 4;
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
        quicksort(&x[0], &x[n], true);
        auto end = std::chrono::high_resolution_clock::now();
        // end timer
        double time = std::chrono::duration<double, std::milli>(end - start).count();
        // total_time += time for this sort
        total_time += time;
    }
    //print(&x[0], &x[n]);
    
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

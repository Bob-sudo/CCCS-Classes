// File: a04q03.cpp
// Name: Ethan Graham

#include <iostream>
// Swaps the values *p, *q
void swap(int * p, int * q)
{
    int t = *p;
    *p = *q;
    *q = t;
}


// Performs bubblesort from *begin to one int before *end.
// For swapping, you should use the above swap function.
void bubblesort(int * begin, int * end)
{
    for (int * p = begin; p < end - 1; ++p)
    {
        for (int * q = begin; q < end - (p - begin) - 1; ++q)
        {
            if (*q > *(q + 1))
            {
                swap(q, q + 1);
            }
        }
    }
}


// Prints array from *begin to one int before *end. The print format is
// {1, 4, -2, 42}.
void println(int * begin, int * end)
{
    std::cout << "{";
    for (int * p = begin; p < end; ++p)
    {
        if (p != begin)
        {
            std::cout << ", ";
        }
        std::cout << *p;
    }
    std::cout << "}\n";
}


int main()
{
    int x[1024];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    println(&x[0], &x[n]);
    
    bubblesort(&x[0], &x[n]);
    println(&x[0], &x[n]);
    
    return 0;
}

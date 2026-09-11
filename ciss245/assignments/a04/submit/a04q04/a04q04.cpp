// File: a04q04.cpp
// Name: Ethan Graham

#include <iostream>
void filter(int x[], int n)
{
    // Allocate an integer array of size n for p to point to.
    int * p = new int[n];
    
    // Compute the weighted average values of x and store in the array
    // that p points to.
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            p[i] = x[i];
        }
        else
        {
            p[i] = (x[i - 1] + x[i] + x[i + 1]) / 3;
        }
    }
    
    // Copy the values in the array that p points to into
    // the values of array x.
    for (int i = 0; i < n; i++)
    {
        x[i] = p[i];
    }
    
    // Deallocate the memory used by p.
    delete[] p;
    
    return;
}
int main()
{
    int x[1024];
    
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    filter(x, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}

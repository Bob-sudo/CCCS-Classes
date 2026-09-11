// File: a04q06.cpp
// Name: Ethan Graham

#include <iostream>

int opendoors(int n)
{
    bool * open;   // open[i] is true when door i is open.
    int count = 0; // This will count the number of values in the
                   // array that open points to which are true.
    
    // Allocate an array of n values for open to point to.
    open = new bool[n];

    for (int i = 0; i < n; ++i)
    {
        open[i] = true;
    }
    
    // Scan (left and right) and update the array that open points to
    // a certain number of times.
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i - 1; i < n; ++i)
        {
            open[i] = !open[i];
        }
    }
    
    // Update count.
    for (int i = 0; i < n; ++i)
    {
        if (open[i]) {
            ++count;
        }
    }
    
    // Deallocate the memory used by the open pointer.
    delete[] open;
    
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << opendoors(n) << std::endl;
    return 0;
}

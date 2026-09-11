// File: skeleton.cpp

#include <iostream>
#include <cstdlib>
#include <vector>

// Your implementation of the sorting algorithm

int main(int argc, char * argv[])
{
    //-------------------------------------------------------------------------
    // Seed the random generator. argv[1] is a numeric string for the seed of
    // the random generator.
    // Convert argv[1] to integer value and assign to seed.
    //-------------------------------------------------------------------------
    int seed = 0;
    // Assign to seed the integer value from the numeric string argv[1]
    srand(seed);

    //-------------------------------------------------------------------------
    // Create a vector x of n random values in the range 0..m.
    // n is the integer from the numeric string argv[2]
    // m is the integer from the numeric string argv[3]
    //-------------------------------------------------------------------------
    int n = 0;
    // Assign to n the integer value from the numeric string argv[2]
    std::vector< int > x(n, 0); // int vector of size n, all zeros

    int m = 0;
    // Assign to m the integer value from the numeric string argv[3]
    
    //-------------------------------------------------------------------------
    // k is the integer from the numeric string argv[4]
    //-------------------------------------------------------------------------
    int k = 0;
    // Assign to k the integer value from the numeric string argv[4]

    //-------------------------------------------------------------------------
    // Call your sorting algorithm to sort x a total of k times and in
    // ascending order and verbose=true.
    //-------------------------------------------------------------------------
    double total_time = 0.0;
    for (int i = 0; i < k; ++i)
    {
        // Randomize vector x
        for (int i = 0; i < n; ++i)
        {
            x[i] = rand() % m;
        }

        // start timer
        bubblesort(&x[0], &x[n], true);
        // end timer
        // total_time += time for this sort
    }
    
    //-------------------------------------------------------------------------
    // Print the average runtime.
    // p is the integer from the numeric string argv[5]
    // If p is 1, print the average runtime.
    // If p is 0, the average runtime is not printed.
    //-------------------------------------------------------------------------
    int p = 0;
    // Assign to p the integer value from the numeric string argv[5]
    // If p is 1, print the average runtime.
    
    return 0;
}

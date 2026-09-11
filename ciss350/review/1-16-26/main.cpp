#include <iostream>
#include "Mat.h"

int linearsrch(int x[], int start, int end, int target)
{
    for(int i = start; i < end; i++)
    {
        if (x[i] == target) return i;
    }
    return -1;
}

int * linearsrch(int * start, int * end, int target)
{
    for (int * p = start; p < end; ++p)
    {
        if (*p == target) return p;
    }
    return NULL;
}

int main()
{
    /*
    int x[] = {5, 3, 1, 2, 4, 6, 9, 8, 7};
    std::cout << linearsrch(x, 0, 9, 8) << '\n';
    int * p = linearsrch(&x[2], &x[7], 6);
    std::cout << (*p) << '\n';
    p = linearsrch(&x[2], &x[7], 1000);
    std::cout << p << '\n';
    */

    Mat m(3, 4);
    std::cout << m << '\n';
    m(0,0) = 42;
    m(2,3) = -1;
    std::cout << m << '\n';

    Mat n(10,10);
    n = m;
    std::cout << n << '\n';
    
    Mat p(m); // Needs copy constructor (I.e. Mat(const Mat &))
    std::cout << p << '\n';
    
    return 0;
}

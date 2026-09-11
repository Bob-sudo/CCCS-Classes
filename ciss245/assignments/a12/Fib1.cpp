#include "Fib1.h"

int Fib1::operator()(int n)
{
    if (n <= 1) return 1;
    return (*this)(n - 1) + (*this)(n - 2);
}

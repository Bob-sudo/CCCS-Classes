#include "Fib2.h"

Fib2::Fib2()
{
    for (int i = 0; i < 20; i++)
    {
        table[i] = -1;
    }
    table[0] = 1;
    table[1] = 1;
}

int Fib2::operator()(int n)
{
    if (n < 0) return 1;

    if (n < 20)
    {
        if (table[n] == - 1)
        {
            table[n] = (*this)(n - 1) + (*this)(n - 2);
        }
        return table[n];
    }
    else
    {
        return (*this)(n - 1) + (*this)(n - 2);
    }
}

int Fib2::operator[](int index) const
{
    if (index >= 0 && index < 20) return table[index];
    return -1;
}

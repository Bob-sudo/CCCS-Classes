#include "Fib3.h"

int Fib3::table[20];
bool Fib3::is_init = false;

void Fib3::init()
{
    if(!is_init)
    {
        for (int i = 0; i < 20; i++)
        {
            table[i] = -1;
        }
        table[0] = 1;
        table[1] = 1;
        is_init = true;
    }
    
}

int Fib3::operator()(int n)
{
    init();

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

int Fib3::lookup(int n)
{
    init();
    if(n >= 0 && n < 20) return table[n];
    else return -1;
}

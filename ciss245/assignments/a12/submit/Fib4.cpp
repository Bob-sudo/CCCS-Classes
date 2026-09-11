#include "Fib4.h"

#include <iostream>

int * Fib4::table = NULL;
int Fib4::size = 0;
bool Fib4::is_init = false;

Fib4::Fib4()
{
    init(20);
}

Fib4::Fib4(int new_size)
{
    init(new_size);
}

void Fib4::init(int new_size)
{
    if (new_size <= 0) new_size = 20;

    int* new_table = new int[new_size];
    
    for (int i = 0; i < new_size; i++)
    {
        if(is_init && i < size)
        {
            new_table[i] = table[i];
        }
        else
        {
            new_table[i] = -1;
        }
    }

    if (table != NULL)
    {
        delete[] table;
    }

    table = new_table;
    size = new_size;

    if(size > 0) table[0] = 1;
    if(size > 1) table[1] = 1;

    is_init = true;  
}

int Fib4::operator()(int n)
{
    if (n < 0) return 1;

    if (n < size)
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

int Fib4::lookup(int n)
{
    if(!is_init || n < 0 || n >= size) return -1;
    return table[n];
}

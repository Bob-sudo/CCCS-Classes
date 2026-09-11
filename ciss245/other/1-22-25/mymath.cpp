// Filename: mymath.cpp

#include "mymath.h"

int max(int x, int y)
{
    if(x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int min(int x, int y, int z)
{
    if(x <= y)
    {
        if(x <= z)
        {
            return x;
        }
    }
    return 0;
}

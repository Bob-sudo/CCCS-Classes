#include <iostream>

// int sum(int x[], int start, int end)
// {
//     int s = 0;
//     for (int i = start; i < end; ++i)
//     {
//         s += x[i];
//     }
//     return s;
// }

// int sum(int * start, int * end)
// {
//     int s = 0;
//     for (int * p = start; p < end; p++)
//     {
//         s += (*p);
//     }
//     return s;
// }

void bubblesort_pass(int x[], int start, int end)
{
    for (int i = start; i < end - 1; i++)
    {
        if (x[i] > x[i + 1])
        {
            int t = x[i];
            x[i] = x[i + 1];
            x[i + 1] = t;
        }
    }
}

void bubblesort_pass(int * start, int * end)
{
    /*
    for (int * p = start; p < end - 1; p++)
    {
        if (*p > *(p + 1))
        {
            int t = *p;
            *p = *(p + 1);
            *(p + 1) = *p;
        }
    }
    */

    if (start >= end)
    {
        return;
    }
    else
    {
        if (*start > *(start + 1))
        {
            int t = *start;
            *start = *(start + 1);
            *(start + 1) = *start;
        }
        bubblesort_pass(start + 1, end);
    }
}

void bubblesort(int * start, int * end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        return bubblesort_pass(start, end);
        return bubblesort(start, end - 1);
    }
    
}

int main()
{
    int x[] = {5, 3, 1, 2, 4};
    //std::cout << sum(x, 1, 4) << '\n';
    //std::cout << sum(&x[1], &x[4]) << '\n';

    bubblesort(&x[0], &x[4]);
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';

    
    return 0;
}

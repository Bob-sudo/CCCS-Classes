#include <iostream>

bool is_ascending(int x[], int len)
{
    bool ascending = true;
    for(int i = 0; i < len; ++i)
    {
        if(x[i] > x[i + 1])
        {
            ascending = false;
            break;
        }
    }

    return ascending;
}

void sort(int x[], int len)
{
    int tp_index = 0;

    while(x[tp_index] <= x[tp_index + 1])
    {
        ++tp_index;
    }

    //flip values at the TP
    int j = len - 1;
    for(int i = tp_index + 1; i <= j; ++i)
    {
        std::swap(x[i], x[j]);
        j--;
    }

    int left = 0, right = tp_index + 1, k = 0;

    int t[1000] = { 0 };
    
    while(left < tp_index + 1 && right < len)
    {
        if(x[left] <= x[right])
            t[k++] = x[left++];
        else
            t[k++] = x[right++];
    }

    while(left < tp_index + 1)
        t[k++] = x[left++];
    while(right < len)
        t[k++] = x[left++];

    for(int i = 0; i < k; i++)
    {
        x[i] = t[i];
    }
}

int main()
{
    const int SIZE = 10;
    int x[SIZE] = { 2, 3, 3, 4, 7, 8, 9, 10, 11, 12 };

    std::cout << is_ascending(x, SIZE) << '\n';

    int y[12] = { 1, 4, 5, 6, 9, 8, 7, 5, 4, 2, 1, 0 };
    sort(y, 12);

    for(int i = 0; i < 12; ++i)
        std::cout << y[i] << ' ';
    std::cout << '\n';

    return 0;
}

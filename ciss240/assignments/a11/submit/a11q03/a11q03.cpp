//File: a11q03.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        std::cin >> a[i];
    }

    int j = 0;
    std::cin >> j;

    int count = 0, temp = 0;
    for(int i = j; i <= SIZE; i++)
    {
        if(a[j] == a[i])
        {
            count++;
            
        }
        if(a[j] != a[i])
        {
            if(count > temp)
            {
                temp = count;
                count = 0;
            }
        }
    }
    
    count = temp;

    std::cout << count << '\n';
}

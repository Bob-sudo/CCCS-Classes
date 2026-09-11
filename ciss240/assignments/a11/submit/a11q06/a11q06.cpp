//File: a11q06.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    const int SIZE = 1000;
    int x[SIZE] = {0}, y[SIZE] = {0};
    int num, x_len = 0, y_len = 0;

    for(int i = 0; i < SIZE; i++)
    {
        std::cin >> num;
        if(num == -9999)
        {
            break;
        }
        else
        {
            x[i] = num;
            x_len++;
        }
    }

    //Fill y
    for(int i = 0; i < SIZE; i++)
    {
        std::cin >> num;
        if(num == -9999)
        {
            break;
        }
        else
        {
            y[i] = num;
            y_len++;
        }
    }

    //Search for y in x
    int index = -1; 
    for (int i = 0; i <= x_len - y_len; i++)
    {
        bool match = true; 
        for (int j = 0; j < y_len; j++)
        {
            if (x[i + j] != y[j])
            {
                match = false; 
                break;
            }
        }
        if (match)
        {
            index = i;
            break;
        }
    }

    std::cout << index << '\n';
}

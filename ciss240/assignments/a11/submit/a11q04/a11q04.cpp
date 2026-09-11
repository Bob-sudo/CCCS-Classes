//File: a11q04.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int SIZE = 15;
    int a[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        std::cin >> a[i];
    }

    std::cout << "board: ";

    for(int i = 0; i < SIZE; i++)
    {
        std::cout << a[i];
    }

    std::cout << '\n' << "index to put a 1: ";
    int index;
    std::cin >> index;

    if(a[index] < 1)
    {
        a[index] += 1;
    }

    bool valid_right, valid_left;
    int right_capture, left_capture; //index for both capture points

    //Check for right
    for(int i = 0; i < SIZE; i++)
    {
        //Checks for right capture
        if(a[i] == 1 && a[i + 1] == 2)
        {
            valid_right = true;
            right_capture = i;
            break;
        }
        else
        {
            valid_right = false;
        }
    }

    //Check for left capture
    for(int i = SIZE - 1; i >= 0; i--)
    {
        if(a[i] == 1 && a[i - 1] == 2)
        {
            valid_left = true;
            left_capture = i;
            break;
        }
        else
        {
            valid_left = false;
        }
    }

    if(valid_right && valid_left)
    {
        for(int i = right_capture; i < left_capture; i++)
        {
            if(a[i] == 2)
            {
                a[i] = 1;
            }
        }
    }
    

    std::cout << "board: ";
    
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << a[i];
    }

    std::cout << '\n';
    
    return 0;
}

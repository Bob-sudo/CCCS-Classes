//File: a11q05.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    const int SIZE = 100;
    int x[SIZE] = {0}, x2[SIZE] = {0}, result[SIZE + 1] = {0};
    int num, x_len = 0, x2_len = 0, result_len = 0;
    int carry = 0;

    //Fill array 1
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> num;
        if (num != -1)
        {
            x[i] = num;
            x_len++;
        }
        else if (num == -1)
        {
            break;
        }
    }

    //Fill array 2
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> num;
        if (num != -1)
        {
            x2[i] = num;
            x2_len++;
        }
        else if (num == -1)
        {
            break;
        }
    }

    //Adding the two arrays
    int max_len = (x_len > x2_len) ? x_len : x2_len;
    int idx_x = x_len - 1; //Start from the end of array x
    int idx_x2 = x2_len - 1; //Start from the end of array x2

    for (int i = max_len - 1; i >= 0; i--) 
    {
        int digit_x = (idx_x >= 0) ? x[idx_x--] : 0;   //get digit from x, if out of bounds, 0
        int digit_x2 = (idx_x2 >= 0) ? x2[idx_x2--] : 0; //get digit from x2, if out of bounds, 0

        int sum = digit_x + digit_x2 + carry; 
        result[i + 1] = sum % 10;             
        carry = sum / 10;                    
    }

    // Handle leftover carry
    if (carry > 0)
    {
        result[0] = carry;
        result_len = max_len + 1;
    }
    else
    {
        //Shift if no carry
        for (int i = 1; i <= max_len; i++)
        {
            result[i - 1] = result[i]; 
        }
        result_len = max_len;
    }

    std::cout << 
    for (int i = 0; i < x_len; i++)
    {
        std::cout << x[i];
    }
    std::cout << '\n';
    
    for (int i = 0; i < x2_len; i++)
    {
        std::cout << x2[i];
    }
    std::cout << '\n';

    for (int i = 0; i < result_len; i++)
    {
        std::cout << result[i];
    }
    std::cout << '\n';


    return 0;
}

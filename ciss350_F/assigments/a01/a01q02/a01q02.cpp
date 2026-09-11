// File: a01q02.cpp
// Name: Ethan Graham

#include <iostream>

void draw_rising_hills(int n)
{
    
    for(int k = n; k > 0; k--)
    {
        int leading_spaces = 0;
        int post_spaces = 0;
        int peak = (k + (k - 1)) / 2;
        int base = (n - peak) * 2 - 1;

        // calculate lead/post spaces
        for(int i = k - 1; i > 0; i--)
        {
            leading_spaces += i + (i - 1);
            if(i == k - 1)
            {
                post_spaces = i + (i - 1);
            }
        }

        // print leading spaces then peak
        for(int i = 0; i < leading_spaces + peak; i++)
        {
            std::cout << '&';
        }
        
        for(int tot = 0; tot < (n - k - 1) * 2 - 1; tot++)
        {
            std::cout << k;
        }

        
        // print following spaces
        for(int i = 0; i <= post_spaces; i++)
        {
            if(k > 1)
                std::cout << '&';
        }

        /*
        // print base
        for(int i = base; i > 0; i--)
        {
            std::cout << '*';
        }
        */
        std::cout << '\n';
    }
}

int main()
{
    int n;
    std::cin >> n;
    draw_rising_hills(n);

    return 0;
}

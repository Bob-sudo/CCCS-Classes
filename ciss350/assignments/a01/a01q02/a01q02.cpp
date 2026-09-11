// File: a01q02.cpp
// Name: Ethan Graham

#include <iostream>

void draw_rising_hills(int n)
{
    int peak = 0; // Counts # of peaks printed
    int base = 0;
    
    
    for(int k = n; k > 0; k--)
    {
        int leading_spaces = k * (k - 1);
        int post_spaces = (k * 2) - 2;

        // print leading spaces
        for(int i = 0; i < leading_spaces; i++)
        {
            std::cout << ' ';
        }

        std::cout << '*'; // Print Peak

        // post spaces/bases
        for(int i = 0; i < post_spaces; i++)
        {
            std::cout << ' ';
        }
        int temp = 3;
        while(temp <= base)
        {
            for(int j = temp; j > 0; j--)
            {
                std::cout << '*';
            }
            temp += 2;
            for(int i = 0; i < post_spaces; i++)
            {
                std::cout << ' ';
            }
        }  
        (base == 0 ? base += 3 : base += 2);
        peak++;
        
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

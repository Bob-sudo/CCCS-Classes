// Name: Ethan Graham
// File: a01q01.cpp

#include <iostream>

void draw_spiral(int n)
{
    int lines = 4 * n + 1;  // number of rows

    for (int i = 1; i <= lines; i++)
    {
        if(i % 2 == 1) // if odd
        {
            if(i <= (lines + 1) / 2) // top half
            {   
                for(int j = 0; j < (i - 1) / 2; j++)
                {
                    std::cout << "|  ";
                }
                
                std::cout << '+';

                int num_dashes = 6 * n + 2 - 6 * ((i - 1) / 2);
                for(int j = 0; j < num_dashes; j++)
                {
                    std::cout << '-';
                }
                
                std::cout << '+';
                
                for(int j = 0; j < (i - 1) / 2; j++)
                {
                    std::cout << "  |";
                }
                std::cout << '\n';
            }
            else // bottom half
            {
                
                int mirror_i = lines - i + 1;

                for (int j = 0; j < (mirror_i - 1) / 2; j++)
                    std::cout << "|  ";

                std::cout << '+';

                int num_dashes = 6 * n + 2 - 6 * ((mirror_i - 1) / 2);
                for (int j = 0; j < num_dashes; j++)
                    std::cout << '-';

                std::cout << '+';

                for (int j = 0; j < (mirror_i - 1) / 2; j++)
                    std::cout << "  |";

                std::cout << '\n';
                
            }
        }
        else // else even
        {
            
        }
    }
}

int main()
{
    int n;
    
    std::cin >> n;
    draw_spiral(n);
    
    return 0;
}

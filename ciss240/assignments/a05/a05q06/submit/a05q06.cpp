//File: a05q06.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int row, col;
    std::cin >> row >> col;
    
    bool reg_room = true;

    if (row == 1 || row == 2)
    {
        if (col >= 2 && col <= 8)
        {
            reg_room =false;
        }
    }

    if (row == 5 || row == 6)
    {
        if (col >= 4 && col <= 7)
        {
            reg_room =false;
        }
    }

    if (row > 7 || col > 8)
    {
        reg_room = false;
    }
    
    std::cout << reg_room << '\n';
    
    return 0;
}

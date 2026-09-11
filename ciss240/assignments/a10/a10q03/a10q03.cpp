//File: a10q03.cpp
//Name: Ethan Graham

#include <iostream>
#include <cstdlib>

int main()
{
    int gold_x = 0, gold_y = 0, moves = 0, n, dir, pos_x = 0, pos_y = 0;

    std::cout << "seed: ";
    std::cin >> n;
    srand(n);

    while(gold_x == 0 && gold_y == 0)
    {
        gold_x = rand() % 5;
        gold_y = rand() % 5;
    }

    std::cout << "gold hunting game!!!" << '\n' << '\n';
    
    while(dir != 99)
    {
        std::cout << "position of pot: x=" << gold_x << ", y=" << gold_y << '\n';
        std::cout << "your position: x=" << pos_x << ", y=" << pos_y << '\n';
        std::cout << "0-north, 1-south, 2-east, 3-west, 99-quit: ";
        std::cin >> dir;
        std::cout << '\n';

        switch(dir)
        {
            case 0:
                if(pos_y < 4)
                {
                    pos_y++;
                }
                break;
            case 1:
                if(pos_y > 0)
                {
                    pos_y--;
                }
                break;
            case 2:
                if(pos_x < 4)
                {
                    pos_x++;
                }
                break;
            case 3:
                if(pos_x > 0)
                {
                    pos_x--;
                }
                break;
            case 99:
                break;
        }
        moves++;

        if(pos_x == gold_x && pos_y == gold_y)
        {
            std::cout << "you got the gold!" << '\n';
            break;
        }
    }

    std::cout << "number of moves: " << moves - 1 << '\n';

     return 0;
}

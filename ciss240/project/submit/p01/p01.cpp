//File: p01.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    char input;
    bool cont = true;
    
    while (cont)
    {
        
        std::cout << "Welcome to Super Othello Version 1.0" << '\n'
                  << "By Ethan Graham"  << '\n' << '\n';
        std::cout << "[?]   Help" << '\n'
                  << "[P/p] Play a new game" << '\n'
                  << "[L/l] Load a previous game" << '\n'
                  << "[S/s] Setup the board" << '\n'
                  << "[Q/q] Quit" << '\n';

        
        std::cout << "Enter option: ";
        std::cin >> input;

        //Quit
        if (input == 'q' || input == 'Q')
        {
            std::cout << '\n' << "Thanks for playing Super Othello Version 1.0" << '\n' << '\n';
            break;
        }

        //Get Input
        switch (input)
        {
            case 'p':
                std::cout << '\n' << "*** P/p: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 'P':
                std::cout << '\n' << "*** P/p: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 'l':
                std::cout << '\n' << "*** L/l: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 'L':
                std::cout << '\n' << "*** L/l: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 's':
                std::cout << '\n' << "*** S/s: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 'S':
                std::cout << '\n' << "*** S/s: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            case 'q':
                std::cout << '\n' << "Thanks for playing Super Othello Version 1.0" << '\n' << '\n';
                cont = false;
                break;
            case 'Q':
                std::cout << '\n' << "Thanks for playing Super Othello Version 1.0" << '\n' << '\n';
                cont = false;
                break;
            case '?':
                std::cout << '\n' << "*** ?: TO BE IMPLEMENTED ***" << '\n' << '\n';
                break;
            default:
                std::cout << '\n' << "*** INVALID INPUT ***" << '\n' << '\n';
        }
    }

    return 0;
}

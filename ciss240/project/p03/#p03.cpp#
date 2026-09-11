//File: p03.cpp
//Name: Ethan Graham

#include <iostream>

void help(); // Information on game
void play(); // Play game
void setup();
void load(); 

void init(char [8][8]); // Initialize board
void draw(char [8][8]); // Draw Board
void test_draw();

// Main Function
int main()
{
    test_draw();
    
    char input; // Takes option for game
    bool quit = false; // Quit case

    // Game Loop
    while (!quit)
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

        // Play input
        switch (input)
        {
            case 'p': play(); break;
            case 'P': play(); break;
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
                quit = true;
                break;
            case 'Q':
                std::cout << '\n' << "Thanks for playing Super Othello Version 1.0" << '\n' << '\n';
                quit = true;
                break;
            case '?': help(); break;
            default: std::cout << '\n' << "*** INVALID INPUT ***" << '\n' << '\n';
        }
    }

    return 0;
}

// Game information
void help()
{
    std::cout << '\n' << "The official rules can be found at" << '\n'
              << "http://en.wikipedia.org/wiki/Reversi" << '\n' << '\n'
              << "The Othello board is set up in the following manner" << '\n' << '\n'
              << "  ABCDEFGH  " << '\n'
              << " +--------+ " << '\n'
              << "1|        |1" << '\n'
              << "2|        |2" << '\n'
              << "3|        |3" << '\n'
              << "4|   O@   |4" << '\n'
              << "5|   @O   |5" << '\n'
              << "6|        |6" << '\n'
              << "7|        |7" << '\n'
              << "8|        |8" << '\n'
              << " +--------+ " << '\n'
              << "  ABCDEFGH  " << '\n' << '\n';
    std::cout << "BLACK plays @ and WHITE plays O. Players take turn in entering" << '\n'
              << "moves. The first player to enter a move is BLACK. To place a @" << '\n'
              << "at row 6 and column E, BLACK enters 6E. The result of the move" << '\n'
              << "is" << '\n' << '\n';
    std::cout << "  ABCDEFGH  " << '\n'
              << " +--------+ " << '\n'
              << "1|        |1" << '\n'
              << "2|        |2" << '\n'
              << "3|        |3" << '\n'
              << "4|   O@   |4" << '\n'
              << "5|   @@   |5" << '\n'
              << "6|    @   |6" << '\n'
              << "7|        |7" << '\n'
              << "8|        |8" << '\n'
              << " +--------+ " << '\n'
              << "  ABCDEFGH  " << '\n' << '\n';
    std::cout << "Note that the WHITE piece at E5 is now a BLACK piece" << '\n' << '\n';

    return;
}

// Play function of game
void play()
{
    int turn = 0;
    char s[100];
    while(true)
    {
        std::cout << '\n' << "*** Othello board: TO BE IMPLEMENTED  ***" << '\n' << '\n';

        // Even turns: Black, Odd turns: White
        if(turn % 2 == 0)
        {
            std::cout << "BLACK's turn: ";
            std::cin >> s;
        }
        else
        {
            std::cout << "WHITE's turn: ";
            std::cin >> s;
           
        }
        turn++;
    }   
}

// Function to initialize the Board
void init(char b[8][8])
{
    // Fill with blanks
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            b[i][j] = ' ';
        }
    }

    // Put pieces in
    b[3][3] = 'O';
    b[3][4] = '@';
    b[4][4] = 'O';
    b[4][3] = '@';
}

// Function to print board b onto the console window
void draw(char b[8][8])
{
    int row = 1; // Used to print row number

    std::cout << "  ABCDEFGH  " << '\n'
              << " +--------+ " << '\n';
    for (int i = 0; i < 8; i++)
    {
        std::cout << row << '|';
        for (int j = 0; j < 8; j++)
        {
            std::cout << b[i][j];
        }
        std::cout << '|' << row << '\n';
        row ++;
    }
    std::cout << " +--------+ " << '\n'
              << "  ABCDEFGH  " << '\n' << '\n';
}

// Function to the test draw() function
void test_draw()
{
    char b[8][8];
    std::cout << "Testing draw() function ..." << '\n';
    init(b);
    draw(b);

    b[0][0] = '@'; // put '@' at row 0, column 0
    draw(b);
}

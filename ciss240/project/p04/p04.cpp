// File: p04.cpp
// Name: Ethan Graham

#include <iostream>

// Constants
const char VERS[] = "0.1";
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'O';

// Typedefs
typedef char Board [8][8];

// Prototypes
void help(); // Information on game
void play(); // Play game
void setup();
void load(); 

void init(Board); // Initialize board
void draw(Board); // Draw Board
void test_draw();

// Main Function
int main()
{
    //test_draw();
    
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
    int turn = 0; // Turn Counter
    char input[100];
    Board board; // Board for game
    bool quit = false; // Quit function

    init(board);
    
    while(!quit)
    {
        draw(board);

        int row = 0;
        int col = 0;
        bool move_valid = false;
        
        // Even turns: Black, Odd turns: White
        if(turn == BLACK)
        {
            while (!move_valid)
            {
                std::cout << "BLACK's turn: ";
                std::cin >> input;

                // Quit Game
                if(input[0] == 'q' && input[1] == '\0')
                {
                    quit = true;
                    std::cout << '\n';
                    break;
                }

                // Check if column is valid
                switch(input[0])
                {
                    case 'A': move_valid = true; break;
                    case 'B': move_valid = true; break;
                    case 'C': move_valid = true; break;
                    case 'D': move_valid = true; break;
                    case 'E': move_valid = true; break;
                    case 'F': move_valid = true; break;
                    case 'G': move_valid = true; break;
                    case 'H': move_valid = true; break;
                    default: move_valid = false;
                }
                // Check if row is valid
                switch(input[1])
                {
                    case '1': move_valid = true; break;
                    case '2': move_valid = true; break;
                    case '3': move_valid = true; break;
                    case '4': move_valid = true; break;
                    case '5': move_valid = true; break;
                    case '6': move_valid = true; break;
                    case '7': move_valid = true; break;
                    case '8': move_valid = true; break;
                    default: move_valid = false;
                }
                
                col = input[0] - 'A';
                row = input[1] - 49;

                // Check if space is free
                if(board[row][col] == ' ')
                {
                    board[row][col] = BLACK_PIECE;
                    move_valid = true;
                }
                else
                {
                    move_valid = false;
                }

                // Continue if move is valid
                if(move_valid)
                {
                    turn++;
                }
                else
                {
                    std::cout << "Invalid Position" << '\n';
                }
            }   
        }
            
        else if (turn == WHITE)
        {
            while (!move_valid)
            {
                std::cout << "WHITE's turn: ";
                std::cin >> input;
            
                // Quit Game
                if(input[0] == 'q' && input[1] == '\0')
                {
                    quit = true;
                    std::cout << '\n';
                    break;
                }

                // Check if column is valid
                switch(input[0])
                {
                    case 'A': move_valid = true; break;
                    case 'B': move_valid = true; break;
                    case 'C': move_valid = true; break;
                    case 'D': move_valid = true; break;
                    case 'E': move_valid = true; break;
                    case 'F': move_valid = true; break;
                    case 'G': move_valid = true; break;
                    case 'H': move_valid = true; break;
                    default: move_valid = false;
                }
                // Check if row is valid
                switch(input[1])
                {
                    case '1': move_valid = true; break;
                    case '2': move_valid = true; break;
                    case '3': move_valid = true; break;
                    case '4': move_valid = true; break;
                    case '5': move_valid = true; break;
                    case '6': move_valid = true; break;
                    case '7': move_valid = true; break;
                    case '8': move_valid = true; break;
                    default: move_valid = false;
                }
            
                col = input[0] - 'A';
                row = input[1] - 49;

                // Check if space is free
                if(board[row][col] == ' ')
                {
                    board[row][col] = WHITE_PIECE;
                    move_valid = true;
                }
                else
                {
                    move_valid = false;
                }
                
                // Continue if move is valid
                if(move_valid)
                {
                    turn--;
                }
                else
                {
                    std::cout << "Invalid Position" << '\n';
                }
            }
        }      
    }
}

// Function to initialize the Board
void init(Board b)
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
    b[3][3] = WHITE_PIECE;
    b[3][4] = BLACK_PIECE;
    b[4][4] = WHITE_PIECE;
    b[4][3] = BLACK_PIECE;
}

// Function to print board b onto the console window
void draw(Board b)
{
    int row = 1; // Used to print row number

    std::cout << '\n';
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

// File: p05.cpp
// Name: Ethan Graham

#include <iostream>


// Constants
const char VERS[] = "0.1";
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'O';
const int BOARD_SIZE = 8;

    
// Typedefs
typedef char Board [BOARD_SIZE][BOARD_SIZE];

// Prototypes
void help(); // Information on game
void play(); // Play game
void setup();
void load();
int get_row(char[]);
int get_col(char[]);
void valid_horiz(int, Board);
void init(Board); // Initialize board
void draw(Board); // Draw Board
bool is_valid_column(char);
bool is_valid_row(char);
bool is_space_free(Board, int, int);
bool can_capture_in_direction(Board, int, int, int, int, char);
bool is_valid_move(Board, int, int, char);
void capture_in_direction(Board, int, int, int, int, char);
void place_piece_and_capture(Board, int, int, char);


// Main Function
int main()
{
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
              << "at row 6 and column E, BLACK enters E6. The result of the move" << '\n'
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


// Gameloop
void play()
{
    int turn = BLACK; // Turn Counter
    char input[100];
    Board board;   // Board for the game
    bool quit = false; // Quit flag

    init(board);

    while (!quit)
    {
        draw(board);

        bool move_valid = false;
        char current_piece = (turn == BLACK) ? BLACK_PIECE : WHITE_PIECE;

        while (!move_valid)
        {
            std::cout << ((turn == BLACK) ? "BLACK" : "WHITE");
            std::cout << "'s turn: ";
            std::cin >> input;

            // Quit the game
            if (input[0] == 'q' && input[1] == '\0')
            {
                quit = true;
                std::cout << '\n';
                break;
            }

            
            if (is_valid_column(input[0]) && is_valid_row(input[1]))
            {
                int row = get_row(input);
                int col = get_col(input);

                // Capture if move is valid
                if (is_valid_move(board, row, col, current_piece))
                {
                    place_piece_and_capture(board, row, col, current_piece);
                    move_valid = true;
                    turn = (turn == BLACK) ? WHITE : BLACK; // Toggle turn
                }
                else
                {
                    std::cout << "Invalid Position" << '\n';
                }
            }
            else
            {
                std::cout << "Invalid Position." << '\n';
            }

            
            
        }
    }
}



bool is_valid_column(char col)
{
    return col >= 'A' && col <= 'H';
}


bool is_valid_row(char row)
{
    return row >= '1' && row <= '8';
}


bool is_space_free(Board board, int row, int col)
{
    return board[row][col] == ' ';
}


int get_row(char input[100])
{
    return input[1] - 49;
}


int get_col(char input[100])
{
    return input[0] - 'A';
}


// Function to initialize the Board
void init(Board b)
{
    // Fill with blanks
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
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
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << row << '|';
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << b[i][j];
        }
        std::cout << '|' << row << '\n';
        row ++;
    }
    std::cout << " +--------+ " << '\n'
              << "  ABCDEFGH  " << '\n' << '\n';
}

// Function to check captures in one direction
bool can_capture_in_direction(Board board, int row, int col, int d_row, int d_col, char player_piece)
{
    int opponent_piece = (player_piece == BLACK_PIECE) ? WHITE_PIECE : BLACK_PIECE;
    bool found_opponent = false;

    // Step through the direction
    int current_row = row + d_row;
    int current_col = col + d_col;

    while (current_row >= 0 && current_row < BOARD_SIZE &&
           current_col >= 0 && current_col < BOARD_SIZE)
    {
        if (board[current_row][current_col] == opponent_piece)
        {
            found_opponent = true;
        }
        else if (board[current_row][current_col] == player_piece)
        {
            return found_opponent; // Valid capture if opponent pieces were found
        }
        else
        {
            break; // Empty space or invalid piece, no capture
        }

        current_row += d_row;
        current_col += d_col;
    }

    return false; // No valid capture in this direction
}

// Function to check if a move is valid (captures pieces)
bool is_valid_move(Board board, int row, int col, char player_piece)
{
    if (!is_space_free(board, row, col))
    {
        return false;
    }
    // Check all 8 directions
    for (int d_row = -1; d_row <= 1; ++d_row)
    {
        for (int d_col = -1; d_col <= 1; ++d_col)
        {
            if (d_row == 0 && d_col == 0)
            {
                continue; // Skip the current position
            }
            if (can_capture_in_direction(board, row, col, d_row, d_col, player_piece))
            {
                return true; // Valid move if any direction allows capture
            }
        }
    }

    return false;
}

// Function to capture pieces in one direction
void capture_in_direction(Board board, int row, int col, int d_row, int d_col, char player_piece)
{
    int opponent_piece = (player_piece == BLACK_PIECE) ? WHITE_PIECE : BLACK_PIECE;
    int current_row = row + d_row;
    int current_col = col + d_col;

    // Flip opponent pieces until we encounter the player's piece
    while (board[current_row][current_col] == opponent_piece)
    {
        board[current_row][current_col] = player_piece;
        current_row += d_row;
        current_col += d_col;
    }
}

// Function to place a piece and capture
void place_piece_and_capture(Board board, int row, int col, char player_piece)
{
    // Place the piece
    board[row][col] = player_piece;

    // Capture in all valid directions
    for (int d_row = -1; d_row <= 1; ++d_row)
    {
        for (int d_col = -1; d_col <= 1; ++d_col)
        {
            if (d_row == 0 && d_col == 0)
            {
                continue;
            }
            if (can_capture_in_direction(board, row, col, d_row, d_col, player_piece))
            {
                capture_in_direction(board, row, col, d_row, d_col, player_piece);
            }
        }
    }
}

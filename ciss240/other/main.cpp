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
typedef char Board[BOARD_SIZE][BOARD_SIZE];

// Prototypes
void help(); // Information on game
void play(); // Play game
void setup();
void load();
void valid_check(char[], bool&, Board, int); // Checks for valid move
bool check_board(Board); // Check board for valid spaces
int get_row(char[]);
int get_col(char[]);
void get_valid_positions(int, Board, int[], int[], int&);
bool is_valid_position_at(int, Board, int, int, bool);
void flip(Board&, int, int, int, int);

void init(Board); // Initialize board
void draw(Board); // Draw Board

// Main Function
int main() {
    char input; // Takes option for game
    bool quit = false; // Quit case

    // Game Loop
    while (!quit) {
        std::cout << "Welcome to Super Othello Version 1.0" << '\n'
                  << "By Ethan Graham" << '\n' << '\n';
        std::cout << "[?]   Help" << '\n'
                  << "[P/p] Play a new game" << '\n'
                  << "[L/l] Load a previous game" << '\n'
                  << "[S/s] Setup the board" << '\n'
                  << "[Q/q] Quit" << '\n';

        std::cout << "Enter option: ";
        std::cin >> input;

        // Play input
        switch (input) {
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
void help() {
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
void play() {
    int turn = BLACK; // BLACK starts
    char input[100] = {' '};
    Board board;
    bool quit = false;
    int valid_row[BOARD_SIZE * BOARD_SIZE];
    int valid_col[BOARD_SIZE * BOARD_SIZE];
    int valid_len;

    init(board);

    while (!quit && check_board(board)) {
        draw(board);

        get_valid_positions(turn, board, valid_row, valid_col, valid_len);

        // Check if there are any valid moves
        if (valid_len == 0) {
            std::cout << (turn == BLACK ? "BLACK" : "WHITE") << " has no valid moves.\n";
            turn = (turn == BLACK) ? WHITE : BLACK; // Skip turn
            continue;
        }

        bool move_valid = false;

        while (!move_valid) {
            std::cout << (turn == BLACK ? "BLACK's" : "WHITE's") << " turn: ";
            std::cin >> input;

            // Quit Game
            if (input[0] == 'q' && input[1] == '\0') {
                quit = true;
                break;
            }

            // Convert input to row and col
            int row = get_row(input);
            int col = get_col(input);

            for (int i = 0; i < valid_len; ++i) {
                if (row == valid_row[i] && col == valid_col[i]) {
                    move_valid = true;
                    break;
                }
            }

            if (move_valid) {
                board[row][col] = (turn == BLACK) ? BLACK_PIECE : WHITE_PIECE;

                // Perform flipping in all valid directions
                is_valid_position_at(turn, board, row, col, true);

                // Switch turn
                turn = (turn == BLACK) ? WHITE : BLACK;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }
}

// Function to check if a move is valid
void valid_check(char input[100], bool &move_valid, Board board, int turn) {
    // Check if column is valid
    switch (input[0]) {
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
    switch (input[1]) {
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

    // Check if there are any values beyond input[1]
    for (int i = 2; i < 100; i++) {
        if (input[i] > ' ') {
            move_valid = false;
        }
    }

    // Check if space is free
    if (board[get_row(input)][get_col(input)] == ' ' && turn == WHITE) {
        board[get_row(input)][get_col(input)] = WHITE_PIECE;
    } else if (board[get_row(input)][get_col(input)] == ' ' && turn == BLACK) {
        board[get_row(input)][get_col(input)] = BLACK_PIECE;
    } else {
        move_valid = false;
    }
}

// Check if board is full or not
bool check_board(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return true;
            }
        }
    }

    return false;
}

int get_row(char input[100]) {
    if (input[1] < '1' || input[1] > '8') {
        return -1;
    }
    return input[1] - '1';
}

int get_col(char input[100]) {
    if (input[0] < 'A' || input[0] > 'H') {
        return -1;
    }
    return input[0] - 'A';
}

// Function to get valid positions
void get_valid_positions(int turn, Board board, int valid_row[], int valid_col[], int &valid_len) {
    valid_len = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (is_valid_position_at(turn, board, row, col)) {
                valid_row[valid_len] = row;
                valid_col[valid_len] = col;
                valid_len++;
            }
        }
    }
}

// Function to check validity and optionally flip pieces
bool is_valid_position_at(int turn, Board board, int row, int col, bool do_flip) {
    if (board[row][col] != ' ') {
        return false; // Position must be empty
    }

    bool valid = false;

    // Check all directions
    const int directions[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // NORTH, SOUTH, WEST, EAST
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST
    };

    for (int i = 0; i < 8; ++i) {
        int dr = directions[i][0];
        int dc = directions[i][1];
        
        int r = row + dr;
        int c = col + dc;

        bool found_opponent = false;

        while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == ((turn == BLACK) ? WHITE_PIECE : BLACK_PIECE)) {
            found_opponent = true;
            r += dr;
            c += dc;
        }

        if (found_opponent && r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == ((turn == BLACK) ? BLACK_PIECE : WHITE_PIECE)) {
            valid = true;
            if (do_flip) {
                flip(board, turn, row, col, dr, dc);
            }
        }
    }

    return valid;
}

// Function to flip pieces in a given direction
void flip(Board &board, int turn, int row, int col, int dr, int dc) {
    char opponent_piece = (turn == BLACK) ? WHITE_PIECE : BLACK_PIECE;
    char current_piece = (turn == BLACK) ? BLACK_PIECE : WHITE_PIECE;

    row += dr;
    col += dc;

    while (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == opponent_piece) {
        row += dr;
        col += dc;
    }

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == current_piece) {
        row -= dr;
        col -= dc;

        while (board[row][col] == opponent_piece) {
            board[row][col] = current_piece;
            row -= dr;
            col -= dc;
        }
    }
}

// Function to initialize the Board
void init(Board b) {
    // Fill with blanks
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
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
void draw(Board b) {
    int row = 1; // Used to print row number

    std::cout << '\n';
    std::cout << "  ABCDEFGH  " << '\n'
              << " +--------+ " << '\n';
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << row << '|';
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << b[i][j];
        }
        std::cout << '|' << row << '\n';
        row++;
    }
    std::cout << " +--------+ " << '\n'
              << "  ABCDEFGH  " << '\n' << '\n';
}

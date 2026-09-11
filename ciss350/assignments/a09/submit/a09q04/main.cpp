#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TreeNodel.h"
#include "GameState.h"

char check_winner(const std::string& b, int n)
{
    // Rows
    for(int i = 0; i < n; i++)
    {
        char first = b[i*n];
        
        if (first == '_')
            continue;

        bool win = true;
        for (int j = 1; j < n; j++)
        {
            if (b[i*n + j] != first)
            {
                win = false;
                break;
            }
        }

        if (win) return first;
    }

    // Column
    for(int i = 0; i < n; i++)
    {
        char first = b[i];
        
        if (first == '_')
            continue;

        bool win = true;
        for (int j = 1; j < n; j++)
        {
            if (b[j*n + i] != first)
            {
                win = false;
                break;
            }
        }

        if (win) return first;
    }

    char first = b[0];
    // First Diagonal (\)
    for(int i = 0; i < n; i++)
    {
        
        
        if (first == '_')
            continue;

        bool win = true;
        for (int j = 1; j < n; j++)
        {
            if (b[i*n + j] != first)
            {
                win = false;
                break;
            }
        }

        if (win) return first;
    }

    // Second Diagonal (/)
    first = b[n-1];
    if (first != '_')
    {
        bool win = true;
        for (int i = 1; i < n; i++)
        {
            if (b[i*n + (n-1-i)] != first)
            {
                win = false;
                break;
            }
        }
        if (win) return first;
    }

    return '_';
}

void print(TreeNodel<GameState>* node, int depth, int n)
{
    for(int i = 0; i < depth; ++i)
    {
        std::cout << "    ";
    }

    std::cout << node->get_key().board;

    char winner = check_winner(node->get_key().board, n);

    if (node->get_children().empty())
    {
        if (winner != '_')
            std::cout << " (" << winner << ")";
        else
            std::cout << " (_)";
    }

    std::cout << '\n';

    for(auto child : node->get_children())
    {
        print(child, depth + 1, n);
    }
}

void build(TreeNodel<GameState>* node, int n)
{
    GameState temp = node->get_key();

    char winner = check_winner(temp.board, n);

    if(winner != '_' || temp.board.find('_') == std::string::npos)
        return;

    for(int i = 0; i < temp.board.size(); ++i)
    {
        if(temp.board[i] == '_')
        {
            GameState next = temp;

            next.board[i] = temp.player;
            next.player = (temp.player == 'X') ? 'O' : 'X';
            node->insert(node->get_children().size(), next);

            TreeNodel<GameState>* child =
                node->child(node->get_children().size() - 1);

            build(child, n);
        }   
    }
}

std::string format_board(const std::string& b, int n)
{
    std::string result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result += b[i*n + j];
        }

        if (i < n - 1)
            result += "\\n";
    }

    return result;
}

void write_dot(TreeNodel<GameState>* node, std::ofstream& out, int n)
{
    std::string board = node->get_key().board;
    
    out << "\"" << board << "\" "
        << "[shape=box, fontsize=6, label=\""
        << format_board(board, n)
        << "\"];\n";

    for (auto child : node->get_children())
    {
        std::string childBoard = child->get_key().board;

        out << "\"" << board << "\" -> \""
            << childBoard << "\";\n";

        write_dot(child, out, n);
    }
}

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    char player = argv[2][0];
    std::string board = argv[3];

    GameState start{board, player};

    TreeNodel<GameState> root(start);

    build(&root, n);

    print(&root, 0, n);

    std::ofstream out("tree.dot");
    out << "digraph G {\n";
    write_dot(&root, out, n);
    out << "}\n";
    
    return 0;
}

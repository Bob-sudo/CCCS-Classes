#include "cell.h"
#include "containers.h"
#include <vector>
#include <cstdlib>
#include <iostream>

bool Cell::operator==(const Cell & other) const
{
    return row_ == other.row_ && col_ == other.col_;
}

std::vector<PunchedWall> build_maze(int n, int r, int c)
{
    Unvisited UNVISITED;
    Visited VISITED;
    Path PATH;
    Punched PUNCHED;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!(i == r && j == c))
            {
                UNVISITED.add(Cell(i, j));
            }
        }
    }

    PATH.push(Cell(r, c));
    VISITED.add(Cell(r, c));

    print_maze(n, PUNCHED.getAll(), PATH.top());
    std::cout << '\n';

    while (!PATH.empty())
    {
        // find available neighboring cells
        Cell x = PATH.top();
        std::vector<Cell> available;

        if (x.row_ > 0)
        {
            Cell north(x.row_ - 1, x.col_);
            if (UNVISITED.has(north))
                available.push_back(north);
        }

        if (x.row_ < n - 1)
        {
            Cell south(x.row_ + 1, x.col_);
            if (UNVISITED.has(south))
                available.push_back(south);
        }
        
        if (x.col_ > 0)
        {
            Cell west(x.row_, x.col_ - 1);
            if (UNVISITED.has(west))
                available.push_back(west);
        }
        
        if (x.col_ < n - 1)
        {
            Cell east(x.row_, x.col_ + 1);
            if (UNVISITED.has(east))
                available.push_back(east);
        }

        if (!available.empty())
        {
            int k = rand() % available.size();
            Cell y = available[k];

            
            VISITED.add(y);
            UNVISITED.remove(y);
            PATH.push(y);

            PUNCHED.add(x, y);
            PUNCHED.add(y, x);
        }
        else
        {
            // go backwards
            PATH.pop();
        }

        if(!PATH.empty())
        {
            Cell curr = PATH.top();
            print_maze(n, PUNCHED.getAll(), curr);
            std::cout << '\n';
        }
    }

    return PUNCHED.getAll();
}

void print_maze(int n, const std::vector<PunchedWall> &walls, Cell curr)
{
    // print top border
    for (int i = 0; i < n; ++i)
        std::cout << "+-";
    std::cout << "+\n";

    for (int r = 0; r < n; ++r)
    {
        // print vertical walls
        for (int c = 0; c < n; ++c)
        {
            if(c == 0)
                std::cout << "|";
            else
            {

                bool punched = false;
                for(const auto &walls_ : walls)
                {
                    Cell a = walls_.c0_;
                    Cell b = walls_.c1_;

                    if(a.row_ == r && a.col_ == c - 1 &&
                       b.row_ == r && b.col_ == c)
                    {
                        punched = true;
                        break;
                    }
                }
                if(punched)
                    std::cout << " ";
                else
                    std::cout << "|";
            }
            // print x
            if(r == curr.row_ && c == curr.col_)
                std::cout << 'x';
            else
                std::cout << ' ';
        }

        std::cout << "|\n";

        // print horizontal walls
        for (int c = 0; c < n; ++c)
        {
            std::cout << "+";
            
            bool punched = false;
            for(const auto &walls_ : walls)
            {
                Cell a = walls_.c0_;
                Cell b = walls_.c1_;

                if(r < n - 1 &&
                   a.row_ == r && a.col_ == c &&
                   b.row_ == r + 1 && b.col_ == c)
                {
                    punched = true;
                    break;
                }
            }
            if(punched)
                std::cout << ' ';
            else
                std::cout << '-';
        }

        std::cout << "+\n";
    }
}

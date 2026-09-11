#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 

std::vector<PunchedWall> build_maze(int n, int r, int c)
{
    srand((unsigned int)time(NULL));

    Unvisited unvisited;
    Visited visited;
    Path path;
    Punched punched;

    // Fill unvisited
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i == r && j == c))
                unvisited.add(Cell(i, j));
        }
    }

    Cell start(r, c);
    visited.add(start);
    path.push(start);

    // north, east, south, west
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, 1, -1 };

    // Print initial state
    print_maze(4, punched.getAll(), path.top().r, path.top().c);    
    while (!path.empty())
    {
        Cell current = path.top();

        // Find available neighbors
        Cell neighbors[4];
        int num_neighbors = 0;

        for (int k = 0; k < 4; k++)
        {
            int nr = current.r + dr[k];
            int nc = current.c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n)
            {
                Cell next(nr, nc);
                if (unvisited.has(next))
                {
                    neighbors[num_neighbors++] = next;
                }
            }
        }

        if (num_neighbors > 0)
        {
            int rand_idx = rand() % num_neighbors;
            Cell chosen = neighbors[rand_idx];

            visited.add(chosen);
            unvisited.remove(chosen);

            punched.add(current, chosen);

            path.push(chosen);
        }
        else
        {
            path.pop(); // Backtrack
        }

        // Print updated state
        print_maze(4, punched.getAll(), path.top().r, path.top().c);
    }

    return punched.getAll();
    
}

void print_maze(int n, const std::vector<PunchedWall>& walls, int r, int c)
{
    bool open_north[4][4] = { false };
    bool open_south[4][4] = { false };
    bool open_east[4][4]  = { false };
    bool open_west[4][4]  = { false };

    // Mark punched walls as open
    for (std::vector<PunchedWall>::const_iterator i = walls.begin();
         i != walls.end(); i++)
    {
        Cell a = i->c0;
        Cell b = i->c1;

        if (a.r == b.r && a.c + 1 == b.c)
        {
            open_east[a.r][a.c] = true;
            open_west[b.r][b.c] = true;
        }
        else if (a.r == b.r && a.c - 1 == b.c)
        {
            open_west[a.r][a.c] = true;
            open_east[b.r][b.c] = true;
        }
        else if (a.c == b.c && a.r + 1 == b.r)
        {
            open_south[a.r][a.c] = true;
            open_north[b.r][b.c] = true;
        }
        else if (a.c == b.c && a.r - 1 == b.r)
        {
            open_north[a.r][a.c] = true;
            open_south[b.r][b.c] = true;
        }
    }

    // Print maze
    for (int i = 0; i < n; i++)// rows
    {
        for (int j = 0; j < n; j++) // cols
        {
            std::cout << "+";
            if (open_north[i][j])
                std::cout << " ";
            else
                std::cout << "-";
        }
        std::cout << "+\n";

        for (int j = 0; j < n; j++) // cols
        {
            if (open_west[i][j])
                std::cout << " ";
            else
                std::cout << "|";
            // Show current location of x
            if( i == r && j == c )
                std::cout << 'x';
            else
                std::cout << " ";
        }
        std::cout << "|\n";
    }

    for (int j = 0; j < n; j++)
        std::cout << "+-";
    std::cout << "+\n";

    std::cin.get();
}

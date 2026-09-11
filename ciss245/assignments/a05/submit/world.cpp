/*********************************************************************
File : world.cpp
Author: Ethan Graham
Implementation of world.h.
*********************************************************************/
#include <iostream>
#include "world.h"
#include "Robot.h"

void init(char world[10][10])
{
    srand((unsigned int) time(NULL));
    
    // Fill ' '
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            world[i][j] = ' ';
        }
    }

    // Erect walls
    int walls_placed = 0;
    while(walls_placed < 2)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        int dir = rand() % 4;

        if(can_place_wall(world, x, y, dir, 4))
        {
            build_wall(world, x, y, dir, 4);
            walls_placed++;
        }
    }

    //place gold
    int x = rand() % 10;
    int y = rand() % 10;
    bool gold_placed = false;
    while(!gold_placed)
    {
        if(is_unoccupied(world, x, y))
        {
            world[y][x] = 'G';
            gold_placed = true;
        }
    }
}

void print(char world[10][10])
{
    std::cout << "  0123456789  " << '\n'
              << " XXXXXXXXXXXX " << '\n';
    for(int i = 0; i < 10; i++)
    {
        std::cout << i <<'X';
        for(int j = 0; j < 10; j++)
        {
            std::cout << world[i][j];
        }
        std::cout << 'X' << '\n';
    }
    std::cout << " XXXXXXXXXXXX " << '\n';
}

void set(char world[10][10], int x, int y, char c)
{
    world[y][x] = c;
}

void clear(char world[10][10], int x, int y)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            world[i][j] = ' ';
        }
    }
}

bool is_occupied(char world[10][10], int x, int y)
{
    return world[x][y] != ' ';  
}

bool is_unoccupied(char world[10][10], int x, int y)
{
    return world[x][y] == ' ';  
}

void build_wall(char world[10][10], int x, int y, int dir, int len)
{
    for(int i = 0; i < len; i++)
    {
        world[x][y] = 'X';

        if (dir == 0) y--; // North
        else if (dir == 1) y++; // South
        else if (dir == 2) x++; // East
        else if (dir == 3) x--; // West
    }
}

bool can_place_wall(char world[10][10], int x, int y, int dir, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(x < 0 || x >= 10 || y < 0 || y >= 10 || is_occupied(world, x, y))
        {
            return false;
        }

        if (dir == 0) y--; // North
        else if (dir == 1) y++; // South
        else if (dir == 2) x++; // East
        else if (dir == 3) x--; // West
    }

    return true;
}

void place_power_station(char world[10][10], PowerStation & ps)
{
    srand((unsigned int) time(NULL));
    // create powerstation
    init(ps, -1, -1, 100);
    
    // place in the map
    bool is_placed = false;
    while(!is_placed)
    {
        ps.x = rand() % 10;
        ps.y = rand() % 10;
        if(is_unoccupied(world, ps.x, ps.y))
        {
            world[ps.x][ps.y] = 'P';
            is_placed = true;
        }
    }
}

void place_robot(char world[10][10], Robot & r, char name)
{
    srand((unsigned int) time(NULL));
    // create robot
    r_init(r, name, -1, -1, 100);
    
    // place in the map
    bool is_placed = false;
    while(!is_placed)
    {
        r.x = rand() % 10;
        r.y = rand() % 10;
        if(is_unoccupied(world, r.x, r.y))
        {
            world[r.x][r.y] = name;
            is_placed = true;
        }
    }
}

void move(char world[10][10], Robot & r, char name)
{
    int oldX = r.x;
    int oldY = r.y;

    int dir = rand() % 4;

    switch (dir)
    {
        case 0:
            move_north(r);
            break;
        case 1:
            move_south(r);
            break;
        case 2:
            move_east(r);
            break;
        case 3:
            move_west(r);
            break;
    }

    if (r.x >= 0 && r.x < 10 && r.y >= 0 && r.y < 10
        && is_unoccupied(world, r.x, r.y))
    {
        world[oldX][oldY] = ' ';   // Clear previous position
        world[r.x][r.y] = name;    // Set new position
    }
    else
    {
        r.x = oldX;
        r.y = oldY;
    }
    r.energylevel--;
}

bool found_gold(char world[10][10], Robot & r)
{
    if(world[r.x][r.y++] == 'G'
       || world[r.x][r.y--] == 'G'
       || world[r.x++][r.y] == 'G'
       || world[r.x--][r.y] == 'G')
    {
        return true;
    }
    else return false;
}

void energy_transfer(char world[10][10], Robot & r, PowerStation & ps)
{
    if(world[r.x][r.y++] == 'P'
       || world[r.x][r.y--] == 'P'
       || world[r.x++][r.y] == 'P'
       || world[r.x--][r.y] == 'P')
    {
        dec_energylevel(ps, 1);
        inc_energylevel(r, 1);
    }

}

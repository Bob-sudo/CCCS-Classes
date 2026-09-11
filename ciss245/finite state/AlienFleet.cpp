#include "AlienFleet.h"
#include <iostream>


AlienFleet::AlienFleet(Surface* psurface, Spaceship* ship_pointer)
    : dx_(1), shoot_timer_(60)
{
    int spacing_x = 50;
    int spacing_y = 40;
    int start_x = 100;
    int start_y = 50;

    // Initialize everything to NULL
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {            
            aliens_[row][col] = NULL;
        }
    }
    
    // Assign Yellow Aliens
    int x = start_x + 3 * spacing_x;
    int y = start_y + 0 * spacing_y;
    aliens_[0][3] = new YellowAlien(psurface, x, y, 10, 1, 0);

    x = start_x + 6 * spacing_x;
    y = start_y + 0 * spacing_y;
    aliens_[0][6] = new YellowAlien(psurface, x, y, 10, 1, 0);

    // Assign Red Aliens
    for(int col = 2; col < 8; ++col)
    {
        x = start_x + col * spacing_x;
        y = start_y + 1 * spacing_y;

        aliens_[1][col] = new RedAlien(psurface, x, y, 10, 1, 0);
    }

    // Assign Purple Aliens
    for(int col = 1; col < 9; ++col)
    {
        x = start_x + col * spacing_x;
        y = start_y + 2 * spacing_y;

        aliens_[2][col] = new PurpleAlien(psurface, x, y, 10, 1, 0);
    }

    // Assign Blue Aliens
    for (int row = 3; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            x = start_x + col * spacing_x;
            y = start_y + row * spacing_y;
            
            aliens_[row][col] = new BlueAlien(psurface, x, y, 10, 1, 0);
        }
    }
    
}

void AlienFleet::remove_alien(int row, int col)
{
     if (aliens_[row][col])
     {
        delete aliens_[row][col];
        aliens_[row][col] = NULL;
    }
}

void AlienFleet::run()
{
    bool edge_hit = false;

    // Check if Aliens Have hit an edge
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            Alien* alien = aliens_[row][col];
            if (!alien) continue; 

            int x = alien->get_x();
            int r = alien->get_r();

            if ((x + r >= W && dx_ > 0) || (x - r <= 0 && dx_ < 0))
            {
                edge_hit = true;
                break;
            }
        }
    }

    if(edge_hit) dx_ = -dx_; 
    
    // Move all Aliens
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            if (aliens_[row][col])
            {
                Alien* alien = aliens_[row][col];
                if (alien)
                {
                    // Red behavior
                    if(alien->is_red() && alien->can_attack(*this, row, col))
                    {
                        alien->set_FSM(1);
                    }
                    if (alien->can_attack(*this, row, col))
                    {
                        alien->get_FSM().run();
                    }
                    alien->run(dx_);
                }
                
            }
        }
    }
}

void AlienFleet::draw()
{
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            if (aliens_[row][col]) aliens_[row][col]->draw();
        }
    }
}

Alien* AlienFleet::alien_at(int row, int col) const
{
     if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS)
     {
        return aliens_[row][col];
     }
    return NULL;
}

void AlienFleet::rand_shoot(std::vector<Laser*> & enemy_las)
{   
    if (--shoot_timer_ <= 0)
    {
        int row = rand() % MAX_ROWS;
        int col = rand() % MAX_COLS;

        Alien* shooter = alien_at(row, col);
        if (shooter)
        {
            Laser* laser = shooter->shoot();
            if (laser)
            {
                enemy_las.push_back(laser);
                shoot_timer_ = 60;  // Reset timer
            }
        }
    }
}

void AlienFleet::set_target_for_all(Spaceship* ship)
{
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            if (aliens_[row][col])
                aliens_[row][col]->set_target_ship(ship);
        }
    }
}

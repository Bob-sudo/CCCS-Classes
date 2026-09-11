/****************************************************************************
 Yihsiang Liow
 Copyright
 ****************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

#include "Alien.h"
#include "AlienFleet.h"
#include "Spaceship.h"
#include "Laser.h"

void check_laser_collisions(std::vector<Laser*>& lasers, AlienFleet* fleet, Spaceship & s)
{
    for (int i = 0; i < lasers.size(); )
    {
        lasers[i]->update();

        bool hit = false;
        for (int r = 0; r < MAX_ROWS; ++r)
        {
            for (int c = 0; c < MAX_COLS; ++c)
            {
                Alien* alien = fleet->alien_at(r, c);
                if (alien &&
                    lasers[i]->collides(alien->get_x(),
                                        alien->get_y(),
                                        alien->get_r()))
                {
                    // Add points when alien collides
                    int points = 0;

                    if (alien->is_red()) points = 40;
                    else if (alien->is_yellow()) points = 50;
                    else if (alien->is_purple()) points = 20;
                    else if (alien->is_blue()) points = 10;

                    // Double if in attack state
                    if (alien->get_FSM().state() == 1)
                        points *= 2;

                    s.add_points(points);
                    
                    // Collision occurres
                    fleet->remove_alien(r, c);
                    delete lasers[i];
                    lasers.erase(lasers.begin() + i);
                    hit = true;
                    break;
                }
            }
            if (hit) break;
        }

        if (!hit) ++i;
    }
}

bool check_alien_collisions(AlienFleet* f, Spaceship& s)
{
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            Alien* alien = f->alien_at(row, col);
            if (alien)
            {
                int dx = alien->get_x() - s.getX();
                int dy = alien->get_y() - s.getY();
                int dist_sq = dx * dx + dy * dy;
                int min_dist = alien->get_r() + 10;

                if (dist_sq < min_dist * min_dist)
                {
                    s.lose_life();
                    f->remove_alien(row, col);

                    return true;
                }
            }
        }
    }
    return false;  // No collisions
}

void welcome_screen(Surface& surf, Event& e)
{
    bool game_started = false;

    while (!game_started)
    {
        e.poll();
        if (e.type() == QUIT)
            exit(0);  
        if (e.type() == KEYDOWN && e.keypressed(SPACE))
            game_started = true;

        surf.lock();
        surf.fill(BLACK);

        // Game title
        surf.put_text("GALAXIAN", W / 2 - 100, 80, 255, 255, 255, "fonts/FreeSansBold.ttf", 40);
        surf.put_text("By Ethan Graham", W / 2 - 80, 140, 0, 255, 0, "fonts/FreeSansBold.ttf", 20);

        // Points for each alien type
        surf.put_text("Red Alien: 40 pts", W / 2 - 100, 200, 255, 0, 0, "fonts/FreeSansBold.ttf", 20);
        surf.put_text("Yellow Alien: 50 pts", W / 2 - 100, 230, 255, 255, 0, "fonts/FreeSansBold.ttf", 20);
        surf.put_text("Purple Alien: 20 pts", W / 2 - 100, 260, 150, 0, 255, "fonts/FreeSansBold.ttf", 20);
        surf.put_text("Blue Alien: 10 pts", W / 2 - 100, 290, 0, 100, 255, "fonts/FreeSansBold.ttf", 20);

        // Prompt to begin
        surf.put_text("Press SPACE to Begin", W / 2 - 130, 400, 255, 255, 255, "fonts/FreeSansBold.ttf", 24);

        surf.unlock();
        surf.flip();

        delay(30);
    }
}

void prototype3()
{
    srand((unsigned int) time(NULL));
    Surface surface(W, H);
    Event event;
    Keyboard kbd(event);
    int dir = 0;
    std::vector<Laser *> las;
    std::vector<Laser *> enemy_las;

    int laser_cooldown = 0;
    const int laser_delay = 30;

    Spaceship ship(W / 2, H - 60, 10, 5, &surface, W);
    AlienFleet *fleet = new AlienFleet(&surface, &ship);

    // Welcome Screen
    welcome_screen(surface, event);
    
    while(1)
    {
        int start = getTicks();

        // Space laser cooldown
        if (laser_cooldown > 0)
            laser_cooldown--;
        
        // Process all input events	
        if (event.poll())
        {
            if (event.type() == QUIT) break;

            else if (event.type() == KEYDOWN || event.type() == KEYUP )
            {
                kbd.update(event);
                if(event.keypressed(SPACE) && laser_cooldown <= 0)
                {
                    // Update laser cooldown
                    las.push_back(ship.shoot());
                    laser_cooldown = laser_delay;
                    std::cout << "shoot laser?\n";
                }
                
            }
        }
        if (kbd.keypressed(LEFTARROW)) ship.move(-1);
        else if (kbd.keypressed(RIGHTARROW)) ship.move(1);

        // Update the laser
        for (int i = 0; i < las.size(); i++)
        {
            las.at(i)->update();

            // Delete laser if offscreen
            if(las.at(i)->is_offscreen(H))
            {
                delete las[i];
                las.erase(las.begin() + i);
                std::cout << "Laser deleted\n";
            }
            else i++;
        }
        
        fleet->run();
        fleet->set_target_for_all(&ship);

        // Random Alien shoots
        fleet->rand_shoot(enemy_las);
        
        // Check for laser to alien collision and inc. points
        check_laser_collisions(las, fleet, ship);

        // Check for alien collision, dec. life
        check_alien_collisions(fleet, ship);

        // draw
        surface.lock();
        surface.fill(BLACK);
        ship.draw();
        fleet->draw();
        // Draw Laser
        for (int i = 0; i < las.size(); i++)
            las.at(i)->draw(&surface);

        // Diplay Points
        surface.put_text("Points: ", W / 2 - 200, 0, 255, 0, 0, "fonts/FreeSansBold.ttf", 20);
        surface.put_text(std::to_string(ship.get_points()).c_str(), W / 2 - 125, 0, 255, 0, 0, "fonts/FreeSansBold.ttf", 20);

        // Display Lives
        surface.put_text("Lives:", 400, 0, 255, 255, 255, "fonts/FreeSansBold.ttf", 20);
        surface.put_text(std::to_string(ship.get_lives()).c_str(), 460, 0, 255, 255, 255, "fonts/FreeSansBold.ttf", 20);
        
        surface.unlock();
        surface.flip();

        if (check_alien_collisions(fleet, ship))
        {
            delay(1000); 
        }
        if (ship.get_lives() <= 0)
        {
            std::cout << "Lives hit 0!\n";
        }
    
        int end = getTicks();
        int dt = end - start;
        int leftover = 1000 / 30 - dt;
        if (leftover > 0) delay(leftover);

        // Game over 
        if(ship.get_lives() <= 0)
        {
            surface.lock();
            surface.fill(BLACK);
            surface.put_text("GAME OVER", W / 2 - 150, 100, 255, 0, 0, "fonts/FreeSansBold.ttf", 80);
            surface.unlock();
            surface.flip();
            
            delay(10000);
            prototype3();
        }
    }
}


int main(int argc, char* argv[])
{
    // Prints to console window
    std::cout << "hello world" << std::endl;

    prototype3();
        
    
    return 0;
}

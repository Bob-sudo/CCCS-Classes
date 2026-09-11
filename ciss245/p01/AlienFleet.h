#ifndef ALIENFLEET_H
#define ALIENFLEET_H

#include <vector>

#include "Alien.h"
#include "BlueAlien.h"
#include "YellowAlien.h"
#include "RedAlien.h"
#include "PurpleAlien.h"

#include "Laser.h"

const int MAX_ROWS = 6;
const int MAX_COLS = 10;

class AlienFleet
{
public:
    AlienFleet(Surface * psurface, Spaceship* ship_pointer);
    void remove_alien(int row, int col);

    void run();
    void draw();

    Alien* alien_at(int row, int col) const;
    void rand_shoot(std::vector<Laser*>& enemy_lasers);

    void set_target_for_all(Spaceship* ship);
private:
    Alien* aliens_[MAX_ROWS][MAX_COLS];
    int dx_;
    int shoot_timer_;
};

#endif

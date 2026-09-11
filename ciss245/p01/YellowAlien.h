#ifndef YELLOWALIEN_H
#define YELLOWALIEN_H

#include "Alien.h"

class AlienFleet;
class YellowAlien : public Alien
{
public:
    YellowAlien(Surface* p, int x, int y, int r, int dx, int dy);

    void run(int dir);  
    bool can_attack(const AlienFleet& fleet, int row, int col) const;
    Laser* shoot() const;
    void draw();
    bool is_yellow() const;
};

#endif

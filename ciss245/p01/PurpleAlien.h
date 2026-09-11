#ifndef PURPLEALIEN_H
#define PURPLEALIEN_H

#include "Alien.h"

class AlienFleet;
class PurpleAlien : public Alien
{
public:
    PurpleAlien(Surface* p, int x, int y, int r, int dx, int dy);

    void run(int dir);  
    bool can_attack(const AlienFleet& fleet, int row, int col) const;
    Laser* shoot() const;
    void draw();
    bool is_purple() const;
};

#endif

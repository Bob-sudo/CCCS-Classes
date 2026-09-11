#ifndef BLUEALIEN_H
#define BLUEALIEN_H

#include "Alien.h"

class AlienFleet;
class BlueAlien : public Alien
{
public:
    BlueAlien(Surface* p, int x, int y, int r, int dx, int dy);

    void run(int);
    bool can_attack(const AlienFleet& fleet, int row, int col) const;
    Laser* shoot() const;
    void draw();
    bool is_blue() const;
};

#endif


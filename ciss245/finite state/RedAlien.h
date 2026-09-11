#ifndef REDALIEN_H
#define REDALIEN_H

#include "Alien.h"

class AlienFleet;
class RedAlien : public Alien
{
public:
    RedAlien(Surface* p, int x, int y, int r, int dx, int dy);

    void run(int dir);
    bool can_attack(const AlienFleet& fleet, int row, int col) const;
    Laser* shoot() const;
    void draw();
    bool is_red() const;
};

#endif

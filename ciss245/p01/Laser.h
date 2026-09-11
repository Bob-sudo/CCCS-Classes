#ifndef LASER_H
#define LASER_H

#include "Surface.h"

class Laser
{
public:
    Laser(int x, int y, int dy, bool from_player);

    void update(); // Move the laser vertically
    void draw(Surface* surface) const; 
    bool is_offscreen(int screen_height) const;
    void set_color(int r, int g, int b); // White laser for player,
                                         // red for alien
    bool collides(int target_x, int target_y, int target_r) const;
  private:
    int red_, green_, blue_;
    int x_, y_;
    int dy_;
    bool from_player_;
};

#endif

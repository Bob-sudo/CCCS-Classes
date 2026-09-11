#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream>
#include "Includes.h"
#include "Constants.h"
#include "Surface.h"
#include "Event.h"

#include "Laser.h"

class Spaceship
{
  public:
    Spaceship(int start_x, int start_y, int r,
              int speed, Surface* psurface, int screen_width);

    void draw();
    void move(int dir);

    int getX() const;
    int getY() const;
    int get_points() const;
    void add_points(int points);
    int get_lives()const;
    void lose_life();

    Laser* shoot();
  private:
    int x_, y_, r_;
    int speed_;
    int screen_width_;
    Surface * psurface_;
    Spaceship * pspaceship_;
    Image* sprite_;
    int points_, lives_;
};

#endif

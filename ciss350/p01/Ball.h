#ifndef BALL_H
#define BALL_H

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

#include <cmath>

class Ball
{
  public:
    Ball()
    {
        x = rand() % W;
        y = rand() % H;

        dx = rand() % 3 - 2;
        dy = rand() % 3 - 2;

        if (dx == 0) dx = 1;
        if (dy == 0) dy = 1;

        radius = 3;
        collided = false;
    };
    ~Ball()
    {}
    
    void move();
    void bounce(int, int);
    void collideWith(Ball&);
    
    //private:
    double x;
    double y;
    double dx;
    double dy;
    double radius;
    bool collided;
};

#endif

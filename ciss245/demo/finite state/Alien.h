#ifndef ALIEN_H
#define ALIEN_H

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

class Alien;
class AlienFSM
{
public:
  AlienFSM(Alien * palien)
      : state_(0), palien_(palien)
    {}
    void set_alien_pointer(Alien * palien);
    void run();
    int state() const;

private:
    Alien * palien_;
    int state_;
};

    
class Alien
{
  public:
  Alien(Surface * p, int x, int y, int r, int dx, int dy)
      : psurface_(p),
        x_(x), y_(y),
        r_(r),
        dx_(dx), dy_(dy),
        fsm_(this)
    {}
    void run();  
    void draw();
    
//private:
    Surface * psurface_;
    int x_, y_; // fleet coordinates
    int r_;
    int x1_, y1_; // attack coordinates
    int dx_, dy_;
    int attack_offset_x_, attack_offset_y_;
    AlienFSM fsm_;
};
#endif

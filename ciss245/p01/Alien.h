#ifndef ALIEN_H
#define ALIEN_H

#include <iostream>
#include "Includes.h"
#include "Constants.h"
#include "Surface.h"
#include "Image.h"

#include "Laser.h"
#include "Spaceship.h"


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
    void set_state(int);
    int state_;
private:
    Alien * palien_;
    
};

class AlienFleet;    
class Alien
{
  public:
  Alien(Surface * p, int x, int y, int r, int dx, int dy)
      : psurface_(p),
        x_(x), y_(y),
        r_(r),
        dx_(dx), dy_(dy),
        fsm_(this),
        sprite_(NULL),
        target_ship_(NULL)
    {}
    ~Alien() {};
    virtual void run(int);
    virtual void draw();

    int get_x() const;
    void set_x(int x);
    int get_y() const;
    int get_r() const;
    AlienFSM& get_FSM();
    int set_FSM(int);

    void set_target_ship(Spaceship* ship);
    Spaceship* get_target_ship() const;
    void move_toward(int x_target);

    virtual bool can_attack(const AlienFleet& fleet, int row, int col) const;
    virtual bool is_yellow() const { return false; }
    virtual bool is_red() const { return false; }
    virtual bool is_purple() const { return false; }
    virtual bool is_blue() const { return false; }
    virtual Laser* shoot() const;
    
//private:
    int x1_, y1_; // attack coordinates
    int dx_, dy_;
    int attack_offset_x_, attack_offset_y_;

protected:
    Surface * psurface_;
    int x_, y_; // fleet coordinates
    int r_;
    AlienFSM fsm_;
    Image* sprite_;
    Spaceship* target_ship_;
};

#endif

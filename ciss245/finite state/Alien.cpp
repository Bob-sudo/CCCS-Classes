#include "Alien.h"
#include "AlienFleet.h"


void AlienFSM::set_alien_pointer(Alien * palien)
{
    palien_ = palien;
}

void AlienFSM::run()
{
    //std::cout << "STATE: "<< state_ << std::endl;
    switch(state_)
    {
        case 0:
        {
            // in-fleet to attack state
            if (rand() % 1000 == 0)
            {
                state_ = 1;

                palien_->dx_ = 0; 
                palien_->x1_ = palien_->get_x();
                palien_->y1_ = palien_->get_y();
                palien_->attack_offset_x_ = palien_->get_x();
                palien_->attack_offset_y_ = palien_->get_y();
            }
            return;
        } 
        case 1:
        {
            // attack to rejoin state
            if (palien_->y1_ > H)
            {
                palien_->y1_ = 0;
                state_ = 2;
            }

            // Get target and move toward target
            if (palien_->get_target_ship())
            {
                int ship_x = palien_->get_target_ship()->getX();
                palien_->move_toward(ship_x);

            }
            return;
        }
        case 2:
        {
            if (abs(palien_->x1_ - palien_->get_x()) < 5
                &&
                abs(palien_->y1_ - palien_->get_y()) < 5)
            {
                state_ = 0;
                palien_->set_x(palien_->x1_);
            }
            
            return;
        }
        
    }
    return;
}


int AlienFSM::state() const
{
    return state_;
}

void AlienFSM::set_state(int s)
{
    state_ = s;
}

void Alien::run(int dir)
{
    switch (fsm_.state())
    {
        case 0: // In fleet state
            x_ += dx_ * dir;
            break;

        case 1: // Attack state
            y_ += 2;  // Attack speed
            if (y_ > H)
            {
                y_ = 0;
                fsm_.set_state(2);
            }
            break;

        case 2: // Rejoin state
        {
            if (abs(x_ - x1_) > 1)
                x_ += (x1_ > x_) ? 2 : -2;
            else
                x_ = x1_;

            if (abs(y_ - y1_) > 1)
                y_ += (y1_ > y_) ? 2 : -2;
            else
                y_ = y1_;

            if (abs(x_ - x1_) < 5 && abs(y_ - y1_) < 5)
            {
                x_ = x1_;
                y_ = y1_;
                fsm_.set_state(0);
            }

            break;
        }
    }
}

    
void Alien::draw()
{
    if (!sprite_ || !sprite_->image) return;

    int w = sprite_->image->w;
    int h = sprite_->image->h;
    psurface_->put_image(*sprite_, Rect(x_ - w / 2, y_ - h / 2, w, h));
}

int Alien::get_x() const
{
    return x_;
}

void Alien::set_x(int x)
{
    x_ = x;
}

int Alien::get_y() const
{
    return y_;
}

int Alien::get_r() const
{
    return r_;
}

AlienFSM& Alien::get_FSM()
{
    return fsm_;
}

int Alien::set_FSM(int state)
{
    fsm_.set_state(state);
    return state;
}

bool Alien::can_attack(const AlienFleet& fleet, int row, int col) const
{
    return true;
}

void Alien::set_target_ship(Spaceship* ship)
{
    target_ship_ = ship;
}

Spaceship* Alien::get_target_ship() const
{
    return target_ship_;
}

void Alien::move_toward(int x_target)
{
    if (x_ < x_target) x_ += 1;
    else if (x_ > x_target) x_ -= 1;
}
  
Laser* Alien::shoot() const
{
    return new Laser(x_, y_ + r_, 5, false);
}

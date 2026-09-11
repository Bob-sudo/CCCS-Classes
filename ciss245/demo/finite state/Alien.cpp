#include "Alien.h"


void AlienFSM::set_alien_pointer(Alien * palien)
{
    palien_ = palien;
}

void AlienFSM::run()
{
    switch(state_)
    {
        case 0:
        {
            // in-fleet to attack state
            if (rand() % 50 == 0)
            {
                state_ = 1;
                palien_->x1_ = palien_->x_;
                palien_->y1_ = palien_->y_;
                palien_->attack_offset_x_ = palien_->x_;
                palien_->attack_offset_y_ = palien_->y_;
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
            return;
        }
        case 2:
        {
            if (abs(palien_->x1_ - palien_->x_) < 5
                &&
                abs(palien_->y1_ - palien_->y_) < 5)
            {
                state_ = 0;
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


void Alien::run()
{
    switch(fsm_.state())
    {
        case 0: // in-fleet state
        {
            x_ += dx_;
            if (x_ + r_ > W)
            {
                dx_ = -dx_;
            }
            else if (x_ - r_ < 0)
            {
                dx_ = -dx_;
            }
                
            fsm_.run();
            break;
        }
        case 1: // attack state
        {
            // track the return position in the fleet
            x_ += dx_;
            if (x_ + r_ > W)
            {
                dx_ = -dx_;
            }
            else if (x_ - r_ < 0)
            {
                dx_ = -dx_;
            }
                
            // x1 ... later make sine function
            y1_ += 1;
            double y2 = y1_ - attack_offset_y_;
            double x2 = 50 * sin(0.1 * y2);
            x1_ = attack_offset_x_ + x2;
            
            fsm_.run();                
            break;
        }
        case 2: // rejoin state
        {
            // move return position
            x_ += dx_;
            if (x_ + r_ > W)
            {
                dx_ = -dx_;
            }
            else if (x_ - r_ < 0)
            {
                dx_ = -dx_;
            }
                
            // rejoin fleet
            if (y_ > y1_)
            {
                ++y1_;
            }
                
            if (x_ > x1_) ++x1_;
            else if (x_ < x1_) --x1_;

            fsm_.run();
            break;
        }
            
    }
}
    
void Alien::draw()
{
    switch(fsm_.state())
    {
        case 0: // in-fleet state
        {
            psurface_->put_circle(x_, y_, r_, 255, 0, 0);
            break;
        }
        case 1: // attack state
        {
            psurface_->put_circle(x_, y_, r_/2, 0, 255, 0); // return
            psurface_->put_circle(x1_, y1_, r_, 255, 0, 0);
            break;
        }
        case 2: // rejoin state
        {
            psurface_->put_circle(x_, y_, r_/2, 0, 255, 0); // return
            psurface_->put_circle(x1_, y1_, r_, 255, 0, 0);
            break;
        }
    }
}

#include "Spaceship.h"
#include "Event.h"

Spaceship::Spaceship(int start_x, int start_y, int r,
                     int speed, Surface * psurface, int screen_width)
    : x_(start_x), y_(start_y), r_(r), speed_(speed),
      psurface_(psurface), screen_width_(screen_width)
{
    sprite_ = new Image("images/galaxian/GalaxianGalaxip.gif");
    points_ = 0;
    lives_ = 3;
}

void Spaceship::draw()
{
    if (!sprite_ || !sprite_->image) return;
    
    int w = sprite_->image->w;
    int h = sprite_->image->h;
    psurface_->put_image(*sprite_, Rect(x_ - w / 2, y_ - h / 2, w, h));
}

int Spaceship::getX() const
{
    return x_;
}

int Spaceship::getY() const
{
    return y_;
}

int Spaceship::get_points() const
{
    return points_;
}

void Spaceship::add_points(int points)
{
    points_ += points;
}

int Spaceship::get_lives() const
{
    return lives_;
}
void Spaceship::lose_life()
{
    if(lives_ > 0) lives_--;
}

void Spaceship::move(int dir)
{
    if(dir == 1 && x_ + r_ + speed_ < screen_width_)
        x_ += speed_ * dir;
    else if (dir == -1 && x_ - r_ - speed_ > 0)
        x_ += speed_ * dir;
}

Laser * Spaceship::shoot() 
{
    return new Laser(x_, y_ - r_, -10, true);
}

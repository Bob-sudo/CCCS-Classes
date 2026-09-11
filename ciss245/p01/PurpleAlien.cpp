#include "PurpleAlien.h"
#include "AlienFleet.h"


PurpleAlien::PurpleAlien(Surface * p, int x, int y, int r, int dx, int dy)
    : Alien(p, x, y, r, dx, dy)  // call base class constructor
{
    sprite_ = new Image("images/galaxian/GalaxianPurpleAlien.gif");
}

bool PurpleAlien::can_attack(const AlienFleet& fleet, int row, int col) const
{
    return true;
}

void PurpleAlien::run(int dir)
{
    Alien::run(dir);
}

Laser* PurpleAlien::shoot() const
{
    Laser* laser = new Laser(x_, y_ + r_, 5, false);
    laser->set_color(255, 0, 0);
    return laser;
}

void PurpleAlien::draw()
{
    if (!sprite_ || !sprite_->image) return;

    int w = sprite_->image->w;
    int h = sprite_->image->h;
    psurface_->put_image(*sprite_, Rect(x_ - w / 2, y_ - h / 2, w, h));
}

bool PurpleAlien::is_purple() const
{
    return true;
}

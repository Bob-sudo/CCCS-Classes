#include "BlueAlien.h"
#include "AlienFleet.h"


BlueAlien::BlueAlien(Surface * p, int x, int y, int r, int dx, int dy)
    : Alien(p, x, y, r, dx, dy)  // call base class constructor
{
    sprite_ = new Image("images/galaxian/GalaxianAquaAlien.gif");
}

// Only allow attack if there's no alien below in the same column
bool BlueAlien::can_attack(const AlienFleet& fleet, int row, int col) const
{
    for (int r = row + 1; r < MAX_ROWS; r++)
    {
        if (fleet.alien_at(r, col) != NULL)
        {
            return false;
        }
    }
    return true;
}

void BlueAlien::run(int dir)
{
    Alien::run(dir);
}

Laser* BlueAlien::shoot() const
{
    Laser* laser = new Laser(x_, y_ + r_, 5, false);
    laser->set_color(255, 0, 0);
    return laser;
}

void BlueAlien::draw()
{
    if (!sprite_ || !sprite_->image) return;

    int w = sprite_->image->w;
    int h = sprite_->image->h;
    psurface_->put_image(*sprite_, Rect(x_ - w / 2, y_ - h / 2, w, h));
}

bool BlueAlien::is_blue() const
{
    return true;
}

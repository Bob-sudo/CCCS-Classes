#include "RedAlien.h"
#include "YellowAlien.h"
#include "AlienFleet.h"

RedAlien::RedAlien(Surface* p, int x, int y, int r, int dx, int dy)
    : Alien(p, x, y, r, dx, dy)
{
    sprite_ = new Image("images/galaxian/GalaxianRedAlien.gif");
}

void RedAlien::run(int dir)
{
    Alien::run(dir);
}

bool RedAlien::can_attack(const AlienFleet& fleet, int row, int col) const
{
    int prev_row = row - 1;
    if (prev_row < 0) return false;

    for (int dc = -1; dc <= 1; ++dc)
    {
        int check_col = col + dc;
        if (check_col >= 0 && check_col < MAX_COLS)
        {
            Alien* above = fleet.alien_at(prev_row, check_col);
            if (above && above->get_FSM().state() > 0)
            {
                return true;
            }
        }
    }

    return false;
}

Laser* RedAlien::shoot() const
{
    Laser* laser = new Laser(x_, y_ + r_, 5, false);
    laser->set_color(255, 0, 0);
    return laser;
}

void RedAlien::draw()
{
    if (!sprite_ || !sprite_->image) return;

    int w = sprite_->image->w;
    int h = sprite_->image->h;
    psurface_->put_image(*sprite_, Rect(x_ - w / 2, y_ - h / 2, w, h));
}

bool RedAlien::is_red() const
{
    return true;
}

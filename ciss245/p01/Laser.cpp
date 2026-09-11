#include "Laser.h"

Laser::Laser(int x, int y, int dy, bool from_player)
    : x_(x), y_(y), dy_(dy), from_player_(from_player)
{
    if (from_player_) set_color(255, 255, 255); // white
    else set_color(255, 0, 0); // red
}

void Laser::update()
{
    y_ += dy_;
}

void Laser::draw(Surface* surface) const
{
    surface->put_rect(x_, y_, 4, 8, red_, green_, blue_);
}

bool Laser::is_offscreen(int screen_height) const
{
    return (y_ < 0 || y_ > screen_height);
}

void Laser::set_color(int r, int g, int b)
{
    red_ = r;
    green_ = g;
    blue_ = b;
}

bool Laser::collides(int target_x, int target_y, int target_r) const
{
    int dx = x_ - target_x;
    int dy = y_ - target_y;
    int dist = dx * dx + dy * dy;
    return dist < (target_r * target_r);
}

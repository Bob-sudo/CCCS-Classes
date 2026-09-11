#include "Ball.h"

void Ball::move()
{
    x += dx;
    y += dy;
}

void Ball::bounce(int width, int height)
{
    if(x + radius > width)
    {
        x = width - radius;
        dx = -dx;
    }
    if(x - radius < 0)
    {
        x = radius;
        dx = -dx;
    }
    if(y + radius > height)
    {
        y = height - radius;
        dy = -dy;
    }
    if(y - radius < 0)
    {
        y = radius;
        dy = -dy;
    }
}

void Ball::collideWith(Ball& other)
{
    double diffX = other.x - x;
    double diffY = other.y - y;
    double distance = sqrt(diffX * diffX + diffY * diffY);

    if(distance == 0)
    {
        return;
    }

    // compute collision direction
    double nx = diffX / distance;
    double ny = diffY / distance;
    
    // compute relative velocity
    double rvx = other.dx - dx;
    double rvy = other.dy - dy;
    double rVel = rvx * nx + rvy * ny;

    if(rVel >= 0)
    {
        return;
    }

    // apply impulse and update velocities
    dx -= rVel * nx;
    dy -= rVel * ny;

    other.dx += rVel * nx;
    other.dy += rVel * ny;

    // handle overlap
    double overlap = (radius + other.radius) - distance;

    if(overlap > 0)
    {
        double moveX = nx * overlap / 2;
        double moveY = ny * overlap / 2;

        x += moveX;
        y += moveY;

        other.x -= moveX;
        other.y -= moveY;
    }
    
    // handle speed so they don't go crazy
    double speed = sqrt(dx * dx + dy * dy);

    if(speed != 0)
    {
        dx = (dx / speed) * 1.0;
        dy = (dy / speed) * 1.0;
    }

    double otherSpeed = sqrt(other.dx * other.dx + other.dy * other.dy);

    if(otherSpeed != 0)
    {
        other.dx = (other.dx / otherSpeed) * 1.0;
        other.dy = (other.dy / otherSpeed) * 1.0;
    }
    
}

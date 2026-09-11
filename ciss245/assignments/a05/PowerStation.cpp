#include <iostream>
#include "PowerStation.h"

void init(PowerStation & powerstation, int x, int y, int energylevel)
{
    powerstation.x = x;
    powerstation.y = y;
    powerstation.energylevel = energylevel;
}

void print(const PowerStation & powerstation)
{
    std::cout << "<PowerStation: x=" << powerstation.x << ", y=" << powerstation.y 
              << ", energylevel=" << powerstation.energylevel << '\n';
}

void dec_energylevel(PowerStation & powerstation, int d)
{
    powerstation.energylevel -= d;
    if (powerstation.energylevel < 0) powerstation.energylevel = 0;
}

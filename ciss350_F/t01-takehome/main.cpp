#include "maze.h"
#include <iostream>

int main()
{
    // Build maze object
    std::vector<PunchedWall> punched_walls = build_maze(4, 0, 0);

    return 0;
}

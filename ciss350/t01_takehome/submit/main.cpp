#include "cell.h"
#include "containers.h"
#include <iostream>
#include <vector>

int main()
{
    int n, r, c;
    std::cin >> n >> r >> c;

    std::vector< PunchedWall > punched_walls = build_maze(n, r, c);

    return 0;
}

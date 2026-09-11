#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "containers.h"

std::vector<PunchedWall> build_maze(int n, int r, int c);

void print_maze(int n, const std::vector<PunchedWall>& punched, int row, int col);

#endif

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 

class Cell
{
  public:
    Cell(int row = 0, int col = 0)
        : row_(row), col_(col)
    {}
    int row_, col_;
    bool operator==(const Cell & other) const;
};

class PunchedWall
{
  public:
  PunchedWall(Cell c0, Cell c1)
      : c0_(c0), c1_(c1)
    {}
    
    Cell c0_, c1_;
};

std::vector<PunchedWall> build_maze(int n, int r, int c);

void print_maze(int n, const std::vector<PunchedWall>& walls, Cell curr);

#endif

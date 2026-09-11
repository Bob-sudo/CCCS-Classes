#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell
{
  public:
    Cell(int row = 0, int column = 0)
        : r(row), c(column)
    {}
    int r, c;
    bool operator==(const Cell & other) const;
};

class PunchedWall
{
  public:
  PunchedWall(Cell a, Cell b)
      : c0(a), c1(b)
    {}
    
    Cell c0, c1;
};

#endif

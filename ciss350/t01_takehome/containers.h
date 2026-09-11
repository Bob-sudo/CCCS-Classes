#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "cell.h"
#include <vector>

class Unvisited
{
  public:
    void add(const Cell & c);
    void remove(const Cell & c);
    bool has(const Cell & c) const;
    bool empty() const;
  private:
    std::vector<Cell> cells;
};

class Visited
{
  public:
    void add(const Cell & c);
    bool has(const Cell & c) const;
  private:
    std::vector<Cell> visited;
};

class Path
{
  public:
    void push(const Cell & c);
    Cell pop();
    Cell top() const;
    bool empty() const;
  private:
    std::vector<Cell> trail;
};

class Punched
{
  public:
    void add(const Cell & a, const Cell & b);
    bool has(const Cell & a, const Cell & b);
    const std::vector<PunchedWall> & getAll() const;
  private:
    std::vector<PunchedWall> walls;
};

#endif

#include "containers.h"

// UNVISITED
void Unvisited::add(const Cell & c)
{
    cells.push_back(c);
}

void Unvisited::remove(const Cell & c)
{
    for(std::vector< Cell >::iterator i = cells.begin();
        i != cells.end(); ++i)
    {
        if(*i == c)
        {
            cells.erase(i);
            return;
        }
    }
}

bool Unvisited::has(const Cell & c) const
{
    for (std::vector<Cell>::const_iterator i = cells.begin();
         i != cells.end(); i++)
    {
        if (*i == c)
            return true;
    }
    return false;
}

bool Unvisited::empty() const
{
    return cells.empty();
}

// VISITED
void Visited::add(const Cell & c)
{
    visited.push_back(c);
}

bool Visited::has(const Cell & c) const
{
    for (std::vector<Cell>::const_iterator i = visited.begin();
         i != visited.end(); i++)
    {
        if (*i == c)
            return true;
    }
    return false;
}

// PATH

void Path::push(const Cell & c)
{
    trail.push_back(c);
}

Cell Path::pop()
{
    Cell last = trail.back();
    trail.pop_back();
    return last;
}

Cell Path::top() const
{
    return trail.back();
}

bool Path::empty() const
{
    return trail.empty();
}

// PUNCHED

void Punched::add(const Cell & a, const Cell & b)
{
    walls.push_back(PunchedWall(a, b));
    walls.push_back(PunchedWall(b, a));
}

bool Punched::has(const Cell & a, const Cell & b)
{
    for (std::vector<PunchedWall>::iterator i = walls.begin();
         i != walls.end(); i++)
    {
        if (i->c0_ == a && i->c1_ == b)
            return true;
    }
    return false;
}

const std::vector<PunchedWall> & Punched::getAll() const
{
    return walls;
}

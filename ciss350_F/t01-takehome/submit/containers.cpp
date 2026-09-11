#include "containers.h"
#include <vector>

// Unvisited 
void Unvisited::add(const Cell & c)
{
    cells.push_back(c);
}
 
void Unvisited::remove(const Cell & c)
{
    for (std::vector<Cell>::iterator i = cells.begin();
         i != cells.end(); i++)
    {
        if (*i == c)
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

// Visited
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

// Path
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

// Punched
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
        if (i->c0 == a && i->c1 == b)
            return true;
    }
    return false;
}


const std::vector<PunchedWall> & Punched::getAll() const
{
    return walls;
}


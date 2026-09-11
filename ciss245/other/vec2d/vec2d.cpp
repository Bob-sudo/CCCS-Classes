#include <iostream>
#include "vec2d.h"


vec2d::vec2d()
    : x_(0), y_(0)
{}

vec2d::vec2d(double x, double y)
    : x_(x), y_(y)
{}

double vec2d::get_x() const
{
    return x_;
}

double vec2d::get_y() const
{
    return y_;
}

double vec2d::operator[](int i) const
{
    if (i == 0) return x_;
    else if (i == 1) return y_;
    else return 99999; // WRONG ... need exception
}
double & vec2d::operator[](int i)
{
    if (i == 0) return x_;
    else if (i == 1) return y_;
    else return x_; // WRONG .. need exception
}

vec2d & vec2d::operator*=(double d)
{
    x_ *= d;
    y_ *= d;
    return (*this);
}

vec2d vec2d::operator*(double d)
{
    return (vec2d(*this) *= d);
}

vec2d & vec2d::operator+=(const vec2d & v)
{
    x_ += v.x_;
    y_ += v.y_;
    return (*this);
}

vec2d vec2d::operator+(const vec2d & v) const
{
    return (vec2d(*this) += v);
}


std::ostream & operator<<(std::ostream & cout, const vec2d & v)
{
    cout << '<' << v.get_x() << ", " << v.get_y() << '>';
    return cout;
}

vec2d operator*(double c, const vec2d & v)
{
    return v * c; // i.e v.operator*(c);
}

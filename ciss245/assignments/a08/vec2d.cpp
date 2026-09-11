/**********************************************************************

File : vec2d.cpp
Author: Ethan Graham
Date : 3/4/2025
Description
This is the implementation file the vec2d class. Refer to vec2d.h
for the interface.

**********************************************************************/

#include <iostream>
#include <cmath>
#include "vec2d.h"

std::ostream & operator<<(std::ostream & cout, const vec2d & v)
{
    cout << '<' << v.get_x() << ", " << v.get_y() << '>';
    return cout;
}

std::istream & operator>>(std::istream & cin, vec2d & v)
{
    double x, y;
    cin >> x >> y;
    
    if (cin)
    {
        v.set_x(x);
        v.set_y(y);
    }
    
    return cin;
}

double vec2d::get_x() const
{
    return x_;
}

double vec2d::get_y() const
{
    return y_;
}

void vec2d::set_x(double x)
{
    x_ = x;
}

void vec2d::set_y(double y)
{
    y_ = y;
}

bool vec2d::operator==(const vec2d & v) const
{
    return (x_ == v.x_ && y_ == v.y_);
}

bool vec2d::operator!=(const vec2d & v) const
{
    return (x_ == v.x_ && y_ == v.y_);
}

double vec2d::operator[](int i) const
{
    return (i == 0) ? x_ : y_;
}

double & vec2d::operator[](int i)
{
    return (i == 0) ? x_ : y_;
}

vec2d vec2d::operator+() const
{
    return *this;
}

vec2d & vec2d::operator+=(const vec2d & v)
{
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

vec2d vec2d::operator+(const vec2d & v) const
{
    return (vec2d(*this) += v);
}

vec2d vec2d::operator-() const
{
    return *this;
}

vec2d & vec2d::operator-=(const vec2d & v)
{
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}

vec2d vec2d::operator-(const vec2d & v) const
{
    return (vec2d(*this) -= v);
}

vec2d & vec2d::operator*=(double d)
{
    x_ *= d;
    y_ *= d;
    return (*this);
}

vec2d vec2d::operator*(double d) const
{
    return (vec2d(*this) *= d);
}

vec2d & vec2d::operator/=(double d)
{
    x_ /= d;
    y_ /= d;
    return (*this);
}

vec2d vec2d::operator/(double d) const
{
    return (vec2d(*this) /= d);
}

double vec2d::len() const
{
    return std::sqrt(x_ * x_ + y_ * y_);
}

vec2d operator*(double c, const vec2d & v)
{
    return v * c; // i.e v.operator*(c);
}

double len(const vec2d & v)
{
    return v.len();
}

double dotprod(const vec2d & u, const vec2d & v)
{
    return u.get_x() * v.get_x() + u.get_y() * v.get_y();
}

vec2d norm(const vec2d & v)
{
    return v / v.len();
}

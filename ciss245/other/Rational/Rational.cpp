#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d)
    : n_(n), d_(d)
{}

Rational::Rational()
    : n_(0), d_(1)
{}

int Rational::n() const
{
    return n_;
}

int & Rational::n()
{
    return n_;
}

int Rational::d() const
{
    return d_;
}

int & Rational::d()
{
    return d_;
}

std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    cout << r.n << '/' << r.d;
    return cout;
}

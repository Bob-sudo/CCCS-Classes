#include <iostream>
#include "Rational.h"
std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    return cout;
}
std::istream & operator>>(std::istream & cin, Rational & r)
{

    return cin;
}

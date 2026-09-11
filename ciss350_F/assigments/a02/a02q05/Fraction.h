#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
  public:
    Fraction(int, int);
    Fraction(const Fraction&);
    
  private:
    int n;
    int d;
    int gcd(int, int);
}

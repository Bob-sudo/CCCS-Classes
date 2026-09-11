// Author: Ethan Graham
// File : Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction
{
    int n; // numerator
    int d; // denominator
    int gcd(int, int);
};

std::ostream & operator<<(std::ostream &, const Fraction &);
Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);
bool operator==(const Fraction &, const Fraction &);
bool operator!=(const Fraction &, const Fraction &);
void reduce(Fraction &);
Fraction get_Fraction(int n, int d); // Used to create a Fraction
                                     // with the given n and d
int get_n(const Fraction & f); // Return copy of the numerator
int get_d(const Fraction & f); // Return copy of the denominator
void set_n(Fraction & r, int new_n); // Set r.n to new_n
void set_d(Fraction & r, int new_d); // Set r.d to new_d
void set(Fraction & r, int new_n, int new_d); // Sets both n and d of r
                                              // with the new values
Fraction get_Fraction(int, int);
int get_int(const Fraction &);
int get_double(const Fraction &);

Fraction & operator+=(Fraction &, const Fraction &);
Fraction & operator-=(Fraction &, const Fraction &);
Fraction & operator*=(Fraction &, const Fraction &);
Fraction & operator/=(Fraction &, const Fraction &);

#endif

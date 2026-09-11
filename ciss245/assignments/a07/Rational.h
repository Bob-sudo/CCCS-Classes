/*************************************************************************
File : Rational.h
Author: Ethan Graham
Rational class
[WRITE A COMPLETE DOCUMENTATION FOR THIS LIBRARY]
*************************************************************************/

#include <iostream>
#ifndef RATIONAL_H
#define RATIONAL_H
int GCD(int, int);
int sign(int);
class Rational
{
public:
Rational(int a = 0, int b = 1) : n(a), d(b) {}
Rational(const Rational & r) : n(r.n), d(r.d) {}
int get_n() const { return n; }
int get_d() const { return d; }
void reduce();
bool operator==(const Rational &) const;
bool operator!=(const Rational &) const;
bool operator> (const Rational &) const;
bool operator>=(const Rational &) const;
bool operator< (const Rational &) const;
bool operator<=(const Rational &) const;
Rational & operator+=(const Rational &);
Rational & operator-=(const Rational &);
Rational & operator*=(const Rational &);
Rational & operator/=(const Rational &);
Rational operator+() const;
Rational operator-() const;
Rational operator+(const Rational &) const;
Rational operator-(const Rational &) const;
Rational operator*(const Rational &) const;
Rational operator/(const Rational &) const;
Rational abs() const;
Rational pow(int) const;
int get_int() const;
double get_double() const;
//operator int() const; // You need not implement this.
// SEE COMMENTS BELOW
//operator double() const; // You need not implement this.
// SEE COMMENTS BELOW
private:
int n; // numerator
int d; // denominator
};

std::ostream & operator<<(std::ostream &, const Rational &);
std::istream & operator>>(std::istream &, Rational &);
void reduce(Rational &);
Rational abs(const Rational &);
Rational pow(const Rational &, int);
// Operations with int on the left
bool operator==(int, const Rational &);
bool operator!=(int, const Rational &);
bool operator> (int, const Rational &);
bool operator>=(int, const Rational &);
bool operator< (int, const Rational &);
bool operator<=(int, const Rational &);
int & operator+=(int &, const Rational &);
int & operator-=(int &, const Rational &);
int & operator*=(int &, const Rational &);
int & operator/=(int &, const Rational &);
Rational operator+(int, const Rational &);
Rational operator-(int, const Rational &);
Rational operator*(int, const Rational &);
Rational operator/(int, const Rational &);
// Operations with double on the left
// (This section is OPTIONAL. Once you implement the corresponding
// functions for int, should should be able to do it very quickly dor
// double.
/*
bool operator==(double, const Rational &);
bool operator!=(double, const Rational &);
bool operator> (double, const Rational &);
bool operator>=(double, const Rational &);
bool operator< (double, const Rational &);
bool operator<=(double, const Rational &);
double & operator+=(double &, const Rational &);
double & operator-=(double &, const Rational &);
double & operator*=(double &, const Rational &);
double & operator/=(double &, const Rational &);
double operator+(double, const Rational &);
double operator-(double, const Rational &);
double operator*(double, const Rational &);
double operator/(double, const Rational &);
*/

#endif

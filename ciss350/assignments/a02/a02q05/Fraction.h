#include <ostream>
#ifndef FRACTION_H
#define FRACTION_H

class ZeroDivisionError
{};

class Fraction
{
public:
    Fraction(int n, int d);
    Fraction(int n);
    Fraction();
    Fraction(const Fraction &);
    int numerator() const;
    int denominator() const;
    int gcd(int, int);

    // Fraction & Fraction
    Fraction & operator=(const Fraction &);
    Fraction operator+(const Fraction &) const;
    Fraction & operator+=(const Fraction &);
    Fraction operator-(const Fraction &) const;
    Fraction & operator-=(const Fraction &);
    Fraction operator*(const Fraction &) const;
    Fraction & operator*=(const Fraction &);
    Fraction operator/(const Fraction &) const;
    Fraction & operator/=(const Fraction &);

    // unary operators
    Fraction operator+() const;
    Fraction operator-() const;

    // Fraction & Int
    Fraction & operator=(const int);
    Fraction operator+(const int) const;
    Fraction & operator+=(const int);
    Fraction operator-(const int) const;
    Fraction & operator-=(const int);
    Fraction operator*(const int) const;
    Fraction & operator*=(const int);
    Fraction operator/(const int) const;
    Fraction & operator/=(const int);

    

    
    
private:
    int n_, d_;
};

// Int & Fraction
Fraction operator+(int, const Fraction &);

// abs & pwr
Fraction abs(const Fraction &);
Fraction pow(const Fraction &, int);

std::ostream & operator<<(std::ostream &, const Fraction &);

#endif

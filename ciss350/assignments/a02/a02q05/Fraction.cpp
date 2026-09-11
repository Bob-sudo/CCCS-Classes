#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int n, int d)
{
    if(d == 0)
        throw ZeroDivisionError();
    if (d < 0)
    {
        n = -n;
        d = -d;
    }
    int div = gcd(n, d);
    n_ = n / div;
    d_ = d / div;
}

Fraction::Fraction(int n)
    : n_(n), d_(1)
{}

Fraction::Fraction()
    : n_(0), d_(1)
{}

Fraction::Fraction(const Fraction & f)
    : n_(f.n_), d_(f.d_)
{}

int Fraction::numerator() const
{
    return n_;
}

int Fraction::denominator() const
{
    return d_;
}

int Fraction::gcd(int n, int d)
{
    if(n < 1)
        n = -n;
    if(d < 1)
        d = -d;
    if(d == 0)
        return n;
    else
        return gcd(d, n % d);
}

Fraction & Fraction::operator=(const Fraction & f)
{
    if(this != &f)
    {
        n_ = f.n_;
        d_ = f.d_;
    }
    return (*this);
}

Fraction Fraction::operator+(const Fraction & f) const
{
    return Fraction((n_ * f.d_) + (f.n_ * d_), d_ * f.d_);
}

Fraction & Fraction::operator+=(const Fraction & f)
{
    *this = *this + f;
    return (*this);
}

Fraction Fraction::operator-(const Fraction & f) const
{
    return Fraction((n_ * f.d_) - (f.n_ * d_), d_ * f.d_);
}

Fraction & Fraction::operator-=(const Fraction & f)
{
    *this = *this - f;
    return (*this);
}

Fraction Fraction::operator*(const Fraction & f) const
{
    return Fraction(n_ * f.n_, d_ * f.d_);
}

Fraction & Fraction::operator*=(const Fraction & f)
{
    *this = *this * f;
    return (*this);
}

Fraction Fraction::operator/(const Fraction & f) const
{
    return Fraction(n_ * f.d_, d_ * f.n_);
}

Fraction & Fraction::operator/=(const Fraction & f)
{
    *this = *this / f;
    return (*this);
}

// Fraction & int
Fraction & Fraction::operator=(const int i)
{
    n_ = i;
    d_ = 1;
    return (*this);
}

Fraction Fraction::operator+(const int i) const
{
    return Fraction(n_ + (i * d_), d_);
}
Fraction & Fraction::operator+=(const int i)
{
    *this = *this + i;
    return (*this);
}

Fraction Fraction::operator-(const int i) const
{
    return Fraction(n_ - (i * d_), d_);
}

Fraction & Fraction::operator-=(const int i)
{
    *this = *this - i;
    return (*this);
}

Fraction Fraction::operator*(const int i) const
{
    return Fraction(n_ * i, d_);
}

Fraction & Fraction::operator*=(const int i)
{
    *this = *this * i;
    return (*this);
}

Fraction Fraction::operator/(const int i) const
{
    return Fraction(n_, d_ * i);
}

Fraction & Fraction::operator/=(const int i)
{
    *this = *this / i;
    return (*this);
}

// Unary operators

Fraction Fraction::operator+() const
{
    return (*this);
}

Fraction Fraction::operator-() const
{
    return Fraction(-n_, d_);
}

// Int & Fraction
Fraction operator+(int i, const Fraction & f)
{
    return Fraction(f.numerator() + i * f.denominator(),
                    f.denominator());
}

Fraction abs(const Fraction & f)
{
    if(f.numerator() < 0)
        return -f;
    else
        return f;
}

Fraction pow(const Fraction & f, int i)
{
    if(i == 0)
        return Fraction(1);
    
    if(i > 0)
        return f * pow(f, i - 1);
    
    else
        return Fraction(1) / pow(f, -i);
    
}


std::ostream & operator<<(std::ostream & cout, const Fraction & f)
{
    if(f.denominator() == 1 || f.numerator() == 0)
    {
        cout << f.numerator();
    }
    else
    {
        cout << f.numerator() << '/' << f.denominator();
    }
    return cout;
}

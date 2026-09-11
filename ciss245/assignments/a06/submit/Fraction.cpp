// Author: Ethan Graham
// File : Fraction.cpp

#include <iostream>
#include "Fraction.h"

int gcd(int n, int d)
{
    if(n < 0)
    {
        n = -n;
    }
    if(d < 0)
    {
        d = -d;
    }
    
    while(d != 0)
    {
        int r = n % d; //Remainder
        n = d;
        d = r;
    }
    return n;
}
std::ostream & operator<<(std::ostream & cout, const Fraction & r)
{
    if (r.d == 0)
    {
        cout << "undefined";
    }
    else if (r.n == 0)
    {
        cout << "0";
    }
    else
    {
        int n = r.n;
        int d = r.d;

        // Normalize signs
        if (d < 0)
        {
            n = -n;
            d = -d;
        }

        int div = gcd(n, d);
        n /= div;
        d /= div;
        
        if (d == 1)
        {
            cout << n;
        }
        else
        {
            cout << n << '/' << d;
        }
    }

    return cout;
}

Fraction operator+(const Fraction & a, const Fraction & b)
{
    Fraction r;
    r.n = a.n * b.d + b.n * a.d;
    r.d = a.d * b.d;
    return r;
}

Fraction operator-(const Fraction & a, const Fraction & b)
{
    Fraction r;
    r.n = a.n * b.d - b.n * a.d;
    r.d = a.d * b.d;
    return r;
}

Fraction operator*(const Fraction & a, const Fraction & b)
{
    Fraction r;
    r.n = a.n * b.n;
    r.d = a.d * b.d;
    return r;
}

Fraction operator/(const Fraction & a, const Fraction & b)
{
    Fraction r;
    r.n = a.n * b.d;
    r.d = a.d * b.n;
    return r;
}


bool operator==(const Fraction & a, const Fraction & b)
{
    int n1 = a.n, d1 = a.d;
    int n2 = b.n, d2 = b.d;

    // Normalize signs
    if (d1 < 0) {
        n1 = -n1;
        d1 = -d1;
    }
    if (d2 < 0) {
        n2 = -n2;
        d2 = -d2;
    }

    int gcd1 = gcd(n1, d1);
    int gcd2 = gcd(n2, d2);

    n1 /= gcd1;
    d1 /= gcd1;

    n2 /= gcd2;
    d2 /= gcd2;

    return (n1 == n2 && d1 == d2);
}

bool operator!=(const Fraction & a, const Fraction & b)
{
    return !(a == b);
}

void reduce(Fraction & a)
{
    if (a.d == 0) return;
    
    if (a.n == 0)
    {
        a.d = 1;
        return;
    }

    if (a.d < 0)
    {
        a.n = -a.n;
        a.d = -a.d;
    }

    int div = gcd(a.n, a.d);
    a.n /= div;
    a.d /= div;
}

Fraction get_Fraction(int n, int d)
{
    Fraction f;
    f.n = n;
    f.d = d;
    return f;
}

int get_n(const Fraction & f)
{
    return f.n;
}

int get_d(const Fraction & f)
{
    return f.d;
}

void set_n(Fraction & r, int new_n)
{
    r.n = new_n;
}

void set_d(Fraction & r, int new_d)
{
    r.d = new_d;
}

void set(Fraction & r, int new_n, int new_d)
{
    r.n = new_n;
    r.d = new_d;
}

int get_int(const Fraction & f)
{
    return get_n(f) / get_d(f);
}

int get_double(const Fraction & f)
{
    return 1.0 * get_n(f) / get_d(f);
}

Fraction & operator+=(Fraction & a, const Fraction & b)
{
    int n1 = get_n(a);
    int d1 = get_d(a);
    int n2 = get_n(b);
    int d2 = get_d(b);

    int new_n = n1 * d2 + n2 * d1;
    int new_d = d1 * d2;

    set(a, new_n, new_d);
    return a;
}

Fraction & operator-=(Fraction & a, const Fraction & b)
{
    int n1 = get_n(a);
    int d1 = get_d(a);
    int n2 = get_n(b);
    int d2 = get_d(b);

    int new_n = n1 * d2 - n2 * d1;
    int new_d = d1 * d2;

    set(a, new_n, new_d);
    return a;
}

Fraction & operator*=(Fraction & a, const Fraction & b)
{
    int n1 = get_n(a);
    int d1 = get_d(a);
    int n2 = get_n(b);
    int d2 = get_d(b);

    int new_n = n1 * n2;
    int new_d = d1 * d2;

    set(a, new_n, new_d);
    return a;
}

Fraction & operator/=(Fraction & a, const Fraction & b)
{
    int n1 = get_n(a);
    int d1 = get_d(a);
    int n2 = get_n(b);
    int d2 = get_d(b);

    int new_n = n1 * d2;
    int new_d = d1 * n2;

    set(a, new_n, new_d);
    return a;
}

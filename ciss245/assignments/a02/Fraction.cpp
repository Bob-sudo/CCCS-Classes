// File: Fraction.cpp
// Author: Ethan Graham

#include <iostream>

void Fraction_print(int n, int d)
{
    if (n == 0) std::cout << '0';
    else if (d == 0) std::cout << "undefined";
    else if (n % d == 0) std::cout << n / d;
    else if (n % d != 0 && n > 0 && d > 0)
    {
        // Find GCD (Greatest Common Divisor)
        int GCD = 1;
        int min = n > d ? d : n;
        for (int i = 1; i <= min; i++)
        {
            if (n % i == 0 && d % i == 0) GCD = i;
        }
        std::cout << n / GCD << '/' << d / GCD;
    }
    else if (n < 0 || d < 0)
    {
        if(n < 0 && d > 0) std::cout << n << '/' << d;
        else if(d < 0 && n > 0 || n < 0 && d < 0) std::cout << n * -1 << '/' << d * -1;
    }
    
}

void Fraction_add(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd)
{
    xd = yd * zd;
    xn = (yn * zd) + (zn * yd);
    
    // Simplify the fraction by finding the greatest common divisor (GCD)
    int a = xn, b = xd;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    xn /= a;
    xd /= a;
}

void Fraction_sub(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd)
{
    xd = yd * zd;
    xn = (yn * zd) - (zn * yd);
    
    // Simplify the fraction by finding the greatest common divisor (GCD)
    int a = xn, b = xd;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    xn /= a;
    xd /= a;
}

void Fraction_mult(int &xn, int &xd,
                   int yn, int yd,
                   int zn, int zd)
{
    xn = yn * zn;
    xd = yd * zd;
}

void Fraction_div(int &xn, int &xd, int yn, int yd, int zn, int zd)
{
    xn = yn * zd;
    xd = yd * zn;
}

bool Fraction_eq(int yn, int yd, int zn, int zd)
{
    return (yn * zd == zn * yd);
}

bool Fraction_neq(int yn, int yd, int zn, int zd)
{
    return !Fraction_eq(yn, yd, zn, zd);
}

bool Fraction_lt(int yn, int yd, int zn, int zd)
{
    return (yn * zd < zn * yd);
}

// Function to compute the negative of a fraction
void Fraction_neg(int &xn, int &xd, int yn, int yd)
{
    xn = -yn;
    xd = yd;
}

void Factorize_Polynomial(int an, int ad, int bn, int bd, int cn, int cd)
{
    bool found = false;

    for (int dn = -50; dn <= 50; ++dn)
    for (int dd = 1; dd <= 50; ++dd)
    for (int en = dn; en <= 50; ++en)  
    for (int ed = dd; ed <= 50; ++ed)
    for (int fn = en; fn <= 50; ++fn)
    for (int fd = ed; fd <= 50; ++fd)
    {
        // Compute expected coefficients
        int left_an, left_ad, left_bn, left_bd, left_cn, left_cd;

        // Compute - (d + e + f)
        Fraction_neg(left_an, left_ad, dn * ed * fd + en * dd * fd + fn * dd * ed, dd * ed * fd);

        // Compute de + df + ef
        left_bn = (dn * en * fd + dn * fn * ed + en * fn * dd);
        left_bd = (dd * ed * fd);

        // Compute - (def)
        Fraction_neg(left_cn, left_cd, dn * en * fn, dd * ed * fd);

        // Check if coefficients match
        if (Fraction_eq(left_an, left_ad, an, ad) &&
            Fraction_eq(left_bn, left_bd, bn, bd) &&
            Fraction_eq(left_cn, left_cd, cn, cd))
        {
            std::cout << "x^3 + (" << an << "/" << ad << ")x^2 + ("
                      << bn << "/" << bd << ")x + (" << cn << "/" << cd
                      << ") = (x - (" << dn << "/" << dd << "))"
                      << "(x - (" << en << "/" << ed << "))"
                      << "(x - (" << fn << "/" << fd << "))" << std::endl;
            found = true;
        }
    }

    if (!found)
        std::cout << "not found" << std::endl;
}

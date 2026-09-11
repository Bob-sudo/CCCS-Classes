// File: Fraction.h
// Name: Ethan Graham

//-----------------------------------------------------------------------------
// Print fraction modeled by numerator n and denominator d.
//-----------------------------------------------------------------------------
void Fraction_print(int, int);

//-----------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e., xn/xd,
// is set to the sum of the fractions modeled by yn/yd and zn/zd, i.e.,
// xn/xd = yn/yd + zn/zd
//-----------------------------------------------------------------------------
void Fraction_add(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd);

//-----------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e., xn/xd,
// is set to the difference of the fractions modeled by yn/yd and zn/zd, i.e.,
// xn/xd = yn/yd - zn/zd
//-----------------------------------------------------------------------------
void Fraction_sub(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd);

void Fraction_mult(int &xn, int &xd,
                   int yn, int yd,
                   int zn, int zd);

void Fraction_div(int &xn, int &xd,
                  int yn, int yd,
                  int zn, int zd);

bool Fraction_eq(int yn, int yd,
                 int zn, int zd);

bool Fraction_neq(int yn, int yd,
                  int zn, int zd);

bool Fraction_lt(int yn, int yd,
                 int zn, int zd);

void Fraction_neg(int &xn, int &xd,
                  int yn, int yd);

void Factorize_Polynomial(int an, int ad,
                          int bn, int bd,
                          int cn, int cd);

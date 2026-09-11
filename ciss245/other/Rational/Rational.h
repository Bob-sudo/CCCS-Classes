#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
  public:
    Rational();
    Rational(int, int);
    int n() const;
    int & n();
    int d() const;
    int & d();
  private:
    int n_, d_;
};

std::ostream & operator<<(std::ostream &, const Rational &);

#endif

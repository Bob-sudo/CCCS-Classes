#ifndef FIB2_H
#define FIB2_h

#include <iostream>

class Fib2
{
  public:
    Fib2();
    int operator()(int);
    int operator[](int) const; 
  private:
    int table[20];
};

#endif

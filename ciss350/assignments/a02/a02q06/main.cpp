// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include "vector.h"
int main()
{
    std::cout << "creating vector< int > object a ...\n";
    vector< int > a(5);
    a[0] = 42; // a.operator[](0) = 42
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = -5000;
    std::cout << "a: " << a << std::endl;
    std::cout << "testing exception catching ...\n";
    try
    {
        std::cout << a[6] << '\n';
    }
    catch (IndexError & e)
    {
        std::cout << "successfully caught IndexError exception\n";
    }
/*
  vector< int > b(3);
  b = a; // b.operator=(a)
  std::cout << b << std::endl;
  vector< int > c(0), d(0);
  c = d = b;
  std::cout << c << '\n';
  std::cout << d << '\n';
  vector< int > e(3);
  for (int i = 0; i < 3; ++i)
  {
  e[i] = i;
  }
  std::cout << "e : " << e << std::endl;
  e.push_back(42);
  std::cout << "e : " << e << std::endl;
*/
    /*
      std::cout << "creating vector< double > object x ...\n";
      vector< double > x(10);
      for (int i = 0; i < 10; i++)
      {
      x[i] = 0.1 * i;
      }
      std::cout << "x: " << x << std::endl;
    */
/*
  std::cout << "creating vector< char > object y ...\n";
  vector< char > y(26);
  for (int i = 0; i < 26; i++)
  {
  y[i] = 'A' + i;
  }
  std::cout << "y: " << y << std::endl;
*/
    return 0;
}

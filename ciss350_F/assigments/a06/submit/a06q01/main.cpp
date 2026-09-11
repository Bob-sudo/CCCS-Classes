// Name: Ethan Graham
// File: main.cpp

#include <iostream>
#include "vector.h"

int main()
{
    vector< int > v(10, 0); // v is 10 0s in array of capacity 20
    typename vector< int >::iterator p = v.begin();
    typename vector< int >::const_iterator q = v.begin();
    std::cout << v[0] << '\n'; // prints 0
    std::cout << (*p) << '\n'; // prints 0
    std::cout << (*q) << '\n'; // prints 0
    v[0] = 42;
    std::cout << v[0] << '\n'; // prints 42
    std::cout << (*p) << '\n'; // prints 42
    std::cout << (*q) << '\n'; // prints 42
    *p = -1;
    std::cout << v[0] << '\n'; // prints -1
    std::cout << (*p) << '\n'; // prints -1
    std::cout << (*q) << '\n'; // prints -1
    // *q = 0; // ERROR during compilation
    v[1] = 1;
    ++p;
    ++q;
    std::cout << v[1] << '\n'; // prints 1
    std::cout << (*p) << '\n'; // prints 1
    std::cout << (*q) << '\n'; // prints 1
    v[10] = -9999; // Note: this is outside the valid index range of 0..9
    p = v.end();
    q = v.end();
    std::cout << v[10] << '\n'; // prints -9999
    std::cout << (*p) << '\n'; // prints -9999
    std::cout << (*q) << '\n'; // prints -9999
    v[9] = -9998;
    --p;
    --q;
    std::cout << v[9] << '\n'; // prints -9998
    std::cout << (*p) << '\n'; // prints -9998
    std::cout << (*q) << '\n'; // prints -9998
    *p = -9997;
    std::cout << v[9] << '\n'; // prints -9997
    std::cout << (*p) << '\n'; // prints -9997
    std::cout << (*q) << '\n'; // prints -9997

    // other stuff
    p = v.begin();
    std::cout << (*(p++)) << '\n';
    std::cout << (*(++p)) << '\n';
    p += 3; // NOTE: operator+= is not available for all \cpp\ STL classes
    *p = 42;
    std::cout << v[3] << '\n';
    std::cout << *p << '\n';
    p -= 2;
    *p = 43;
    std::cout << v[1] << '\n';
    std::cout << (*p) << '\n';

    return 0;
}

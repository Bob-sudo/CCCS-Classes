// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f(2, 3);
    Fraction g(42);
    Fraction h;                               // default constructor

    std::cout << f << '\n';                   // prints "2/3" (without the double quotes)
    std::cout << g << '\n';                   // prints "42"
    std::cout << h << '\n';                   // prints "0"

    std::cout << Fraction(2, 4) << '\n';      // prints "1/2"
    std::cout << Fraction(-2, 4) << '\n';     // prints "-1/2"
    std::cout << Fraction(2, -4) << '\n';     // prints "-1/2"
    std::cout << Fraction(-2, -4) << '\n';    // prints "1/2"
    
    std::cout << Fraction(2, 2) << '\n';      // prints "1"
    std::cout << Fraction(2, -2) << '\n';     // prints "-1"
    std::cout << Fraction(-2, 2) << '\n';     // prints "-1"
    std::cout << Fraction(-2, -2) << '\n';    // prints "1"

    
    std::cout << Fraction(100, 20) << '\n';   // prints "5"
    std::cout << Fraction(100, -20) << '\n';  // prints "-5"
    std::cout << Fraction(-100, 20) << '\n';  // prints "-5"
    std::cout << Fraction(-100, -20) << '\n'; // prints "5"
    
    std::cout << Fraction(100) << '\n';       // prints "100"
    std::cout << Fraction(-100, 1) << '\n';   // prints "-100"
    std::cout << Fraction(100, -1) << '\n';   // prints "-100"
    std::cout << Fraction(-100, -1) << '\n';  // prints "100"
    
    std::cout << Fraction() << '\n';          // prints "0"
    std::cout << Fraction(0, 100) << '\n';    // prints "0"
    std::cout << Fraction(0, -100) << '\n';   // prints "0"

    // Testing division by zero exception catching
    try
    {
        std::cout << Fraction(0, 0) << '\n';
    }
    catch (ZeroDivisionError & e)
    {
        std::cout << "ZeroDivisionError exception caught\n";
    }
    
    try
    {
        std::cout << Fraction(-10, 0) << '\n';
    }
    catch (ZeroDivisionError & e)
    {
        std::cout << "ZeroDivisionError exception caught\n";
    }

    Fraction f0(1, 2);
    Fraction f1(f0); // copy constructor
    f1 = f0;         // assignment operator

    std::cout << f0 << '\n'; // Prints 1/2
    std::cout << f1 << '\n'; // Prints 1/2
    std::cout << f0 + f1 << '\n'; // Prints 1
    f0 += f1;
    std::cout << f0 << '\n'; // Prints 1

    Fraction f2(3, 4), f3(1, 4);
    std::cout << f2 - f3 << '\n'; // Prints 1/2
    f2 -= f3;
    std::cout << f2 << '\n'; // Prints 1/2

    Fraction f4(1, 2), f5(1, 2);
    Fraction f6(1, 3), f7(1, 4);
    std::cout << f4 * f5 << '\n'; // prints 1/4
    f6 *= f7;
    std::cout << f6 << '\n'; // prints 1/12

    Fraction f8(1, 2), f9(1, 2);
    Fraction f10(1, 3), f11(1, 4);
    std::cout << f8 / f9 << '\n'; // prints 1
    f10 /= f11;
    std::cout << f10 << '\n'; // print 4/3

    std::cout << "FRACTIONS & INT: " << '\n';

    Fraction f00(1, 2), f01(3, 4), f02;
    
    f02 = f00 + 42;
    std::cout << f02 << '\n';
    f02 = f00 - 42;
    std::cout << f02 << '\n';
    f02 = f00 * 42;
    std::cout << f02 << '\n';
    f02 = f00 / 42;
    std::cout << f02 << '\n';

    f02 = (f00 += 42);
    std::cout << f02 << '\n';
    f02 = (f00 -= 42);
    std::cout << f02 << '\n';
    f02 = (f00 *= 42);
    std::cout << f02 << '\n';
    f02 = (f00 /= 42);
    std::cout << f02 << '\n';

    // Unary
    std::cout << "+f02: " << +f02 << " -f02: " << -f02 << '\n';
    
    /*
    f02 = 42 + f00;
    f02 = 42 - f00;
    f02 = 42 * f00;
    f02 = 42 / f00;
    
    int i = 42, j;
    j = (i += f00);
    j = (i -= f00);
    j = (i *= f00);
    j = (i /= f00);
    */


    // abs & pow
    Fraction f04(-1, 3), f05(1, 3), f06(-1, -3);
    std::cout << "abs(f04): " << abs(f04) <<
        " abs(f05): " << abs(f05) <<
        " abs(f06): " << abs(f06) << '\n';

    Fraction f07(1, 2);
    std::cout << "pow(f07, 5) " << pow(f07, 5) << '\n';
    std::cout << "pow(f07, -5) " << pow(f07, -5) << '\n';

    return 0;
}

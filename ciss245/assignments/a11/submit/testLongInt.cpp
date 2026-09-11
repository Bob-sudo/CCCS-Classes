// File: testLongInt.cpp
// Name: Ethan Graham

#include <iostream>
#include "LongInt.h"

typedef LongInt Z;

int main()
{
    std::cout << "< Constructors & Assignment >\n";
    Z i;
    std::cout << i << '\n';

    Z j(123);
    std::cout << j << '\n';

    Z k("9876543210");
    std::cout << k << '\n';

    Z l("-9876543210");
    std::cout << l << '\n';

    Z m = l;
    std::cout << m << '\n';

    m = "42";
    std::cout << m << '\n';

    std::cout << "\n< Addition Operators >\n";
    Z a("12345"), b("555");
    Z c = a + b;
    Z d = a + 100;
    Z e = 200 + a;
    std::cout << a << " + " << b << " = " << c << '\n';
    std::cout << a << " + 100 = " << d << '\n';
    std::cout << "200 + " << a << " = " << e << '\n';

    a += b;
    std::cout << "a += b -> " << a << '\n';
    a += 50;
    std::cout << "a += 50 -> " << a << '\n';

    std::cout << "\n< Subtraction Operators >\n";
    Z f = a - b;
    Z g = a - 100;
    Z h = 1000 - a;
    std::cout << "a - b = " << f << '\n';
    std::cout << "a - 100 = " << g << '\n';
    std::cout << "1000 - a = " << h << '\n';

    a -= b;
    std::cout << "a -= b -> " << a << '\n';
    a -= 10;
    std::cout << "a -= 10 -> " << a << '\n';

    std::cout << "\n< Multiplication Operators >\n";
    Z x("10"), y("5");
    Z z1 = x * y;
    Z z2 = x * 3;
    Z z3 = 4 * x;
    std::cout << "x * y = " << z1 << '\n';
    std::cout << "x * 3 = " << z2 << '\n';
    std::cout << "4 * x = " << z3 << '\n';

    x *= y;
    std::cout << "x *= y -> " << x << '\n';
    x *= 2;
    std::cout << "x *= 2 -> " << x << '\n';

    std::cout << "\n< Division Operators >\n";
    x = Z("100");
    y = Z("4");
    Z z4 = x / y;
    Z z5 = x / 5;
    Z z6 = 200 / x;
    std::cout << "x / y = " << z4 << '\n';
    std::cout << "x / 5 = " << z5 << '\n';
    std::cout << "200 / x = " << z6 << '\n';

    x /= y;
    std::cout << "x /= y -> " << x << '\n';
    x /= 2;
    std::cout << "x /= 2 -> " << x << '\n';

    std::cout << "\n< Modulo Operators >\n";
    x = Z("123");
    y = Z("10");
    Z z7 = x % y;
    Z z8 = x % 7;
    Z z9 = 456 % x;
    std::cout << "x % y = " << z7 << '\n';
    std::cout << "x % 7 = " << z8 << '\n';
    std::cout << "456 % x = " << z9 << '\n';

    x %= y;
    std::cout << "x %= y -> " << x << '\n';
    x %= 3;
    std::cout << "x %= 3 -> " << x << '\n';

    std::cout << "\n< Increment (++) / Decrement (--) >\n";
    Z inc("10");
    std::cout << "inc = " << inc << '\n';
    std::cout << "++inc = " << ++inc << '\n';
    std::cout << "inc++ = " << inc++ << '\n';
    std::cout << "inc = " << inc << '\n';

    Z dec("10");
    std::cout << "--dec = " << --dec << '\n';
    std::cout << "dec-- = " << dec-- << '\n';
    std::cout << "dec = " << dec << '\n';

    std::cout << "\n< Comparison Operators >\n";
    Z cmp1("100"), cmp2("100"), cmp3("200");
    std::cout << "cmp1 = 100, cmp2 = 100, cmp3 = 200)" << '\n';
    std::cout << "cmp1 == cmp2: " << (cmp1 == cmp2) << '\n';
    std::cout << "cmp1 != cmp3: " << (cmp1 != cmp3) << '\n';
    std::cout << "cmp1 < cmp3: " << (cmp1 < cmp3) << '\n';
    std::cout << "cmp1 <= cmp2: " << (cmp1 <= cmp2) << '\n';
    std::cout << "cmp3 > cmp1: " << (cmp3 > cmp1) << '\n';
    std::cout << "cmp3 >= cmp2: " << (cmp3 >= cmp2) << '\n';

    std::cout << "cmp1 == 100: " << (cmp1 == 100) << '\n';
    std::cout << "cmp1 != 200: " << (cmp1 != 200) << '\n';
    std::cout << "cmp1 < 200: " << (cmp1 < 200) << '\n';
    std::cout << "cmp1 <= 100: " << (cmp1 <= 100) << '\n';
    std::cout << "cmp3 > 50: " << (cmp3 > 50) << '\n';
    std::cout << "cmp3 >= 200: " << (cmp3 >= 200) << '\n';

    std::cout << "100 == cmp1: " << (100 == cmp1) << '\n';
    std::cout << "200 != cmp1: " << (200 != cmp1) << '\n';
    std::cout << "50 < cmp3: " << (50 < cmp3) << '\n';
    std::cout << "100 <= cmp1: " << (100 <= cmp1) << '\n';
    std::cout << "200 > cmp1: " << (200 > cmp1) << '\n';
    std::cout << "200 >= cmp3: " << (200 >= cmp3) << '\n';

    return 0;
}

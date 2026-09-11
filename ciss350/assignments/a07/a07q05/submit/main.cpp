#include "Polynomial.h"
#include <iostream>

int deg(const Polynomial & poly)
{
    std::list< Monomial > q = poly.get_list();
    if(q.empty())
    {
        return 0;
    }
    auto i = --q.end();
    return i->degree;
}

int main()
{
    Polynomial p("3*x^2 + 7*x^12 - 9*x^100 + -2*x^32 + x^5 + 0*x^6 + 6*x^2 + 32 + 1*x^0");
    std::cout << p << '\n'; // prints -9x^100 - 2x^32 + 7x^12 + x^5 + 9x^2 + 33

    Polynomial p0(42); // p0 = 42 as a polynomial
    std::cout << p0 << '\n';

    Polynomial p1(p);
    std::cout << p1 << '\n';

    std::cout << '\n' << "==/!=: " << '\n';
    std::cout << (p0 == p) << '\n';
    std::cout << (p1 != p) << '\n';
    std::cout << (5 == p) << '\n';
    std::cout << (p != 5) << '\n';

    std::cout << "Degree: ";
    std::cout << deg(p) << '\n'; // degree of p

    Polynomial q("x^2 + x + 1");
    std::cout << q << '\n';

    p += q;
    std::cout << "+=: " << p << '\n';
    p -= q;
    std::cout << "-=: " << p << '\n';
    p *= q;
    std::cout << "*=: " << p << '\n';

    Polynomial r("3*x^2 + 7*x^12 - 9*x^100 + -2*x^32 + x^5 + 0*x^6 + 6*x^2 + 32 + 1*x^0");
    p = r;

    r = p - q;
    std::cout << '\n' << "r: " << '\n';
    std::cout << r << '\n';
    r = p * q;
    std::cout << r << '\n';

    std::cout << '\n' << "r: int/polynomial plus" << '\n';
    r = 42 + p;
    std::cout << r << '\n';
    std::cout << '\n' << "r: polynomial/int plus" << '\n';
    r = p + 42;
    std::cout << r << '\n';

    std::cout << '\n' << "r: int/polynomial minus" << '\n';
    r = 42 - p;
    std::cout << r << '\n';
    std::cout << '\n' << "r: polynomial/int minus" << '\n';
    r = p - 42;
    std::cout << r << '\n';

    std::cout << '\n' << "r: int/polynomial mult" << '\n';
    r = 42 * p;
    std::cout << r << '\n';
    std::cout << '\n' << "r: polynomial/int mult" << '\n';
    r = p * 42;
    std::cout << r << '\n';
    
    return 0;
}

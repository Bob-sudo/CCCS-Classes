// file: sort2.cpp

#include <iostream>

template < typename T >
class Less
{
public:
    bool operator()(const T & x, const T & y) const
    {
        return (x < y);
    }
};

template < typename T >
class Greater
{
public:
    bool operator()(const T & x, const T & y) const
    {
        return (x > y);
    }
};

template < typename T >
void sort2(T * p, T * q, bool verbose=false) // sort in ascending
{
    if (verbose)
    {
        std::cout << *p << ' ' << *q << '\n';
    }
    if (*q < *p)
    {
        T t = *p;
        *p = *q;
        *q = t;
    }
    if (verbose)
    {
        std::cout << *p << ' ' << *q << '\n';
    }
}

template < typename T, typename C >
void sort2(T * p, T * q, const C & less, bool verbose=false) // sort based on less
{
    if (verbose)
    {
        std::cout << "verbose on ... " << *p << ' ' << *q << '\n';
    }
    if (less(*q, *p))
    {
        T t = *p;
        *p = *q;
        *q = t;
    }
    if (verbose)
    {
        std::cout << "verbose on ... " << *p << ' ' << *q << '\n';
    }
}

int main()
{
    int x[] = {1, 0};
    std::cout << '\n';
    sort2(&x[0], &x[1]);
    std::cout << x[0] << ' ' << x[1] << '\n';

    int y[] = {1, 0};
    std::cout << '\n';
    sort2(&y[0], &y[1], Less< int >());
    std::cout << x[0] << ' ' << x[1] << '\n';

    int z[] = {0, 1};
    std::cout << '\n';
    sort2(&z[0], &z[1], Greater< int >(), true);
    
    return 0;
}


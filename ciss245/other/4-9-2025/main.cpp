#include <iostream>

int f(int a, int b, int c)
{
    // Suppose not allowed to have zero numerator
    // precondition b != c
    if (b == c) throw 42;
    if (a + b == 0) throw 2.1;
    
    return(a + b) / (c - b);
}

class vec2d_exception
{
};

class vec2d
{
public:
    double operator[](int i)
    {
        if (i < 0 || i > 1) vec2d_exception();
        
        if (i == 0) return x_;
        else return y_;
    }
    double x_;
    double y_;
};

int main()
{
    try
    {
        int x = f(2, 3, 4);
        std::cout << "x: " << x << '\n';

        x = f(2, 3, 3);
        std::cout << "x: " << x << '\n';
    }
    catch (int x)
    {
        std::cout << "This is the catch block ... caught " << x << '\n';
    }
    catch(double y)
    {
        std::cout << "this is the catch block ... caught double " << y << '\n';
    }

    try
    {
        vec2d v;
        std::cout << v[500];
    }
    catch(vec2d_exception & e)
    {
    }

    return 0;
}

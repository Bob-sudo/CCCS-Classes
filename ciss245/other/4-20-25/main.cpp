#include <iostream>

class X
{
public:
    X(int id)
        : id_(id)
    {}
    ~X()
    {
        std::cout << id_ << " died\n";
    }
    int id_;
};

int main()
{
    X x(42);
    for (int i = 0; i < 3; ++i)
    {
        X a(i);
    }
    return 0;
}

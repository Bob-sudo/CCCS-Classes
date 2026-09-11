//File: a05q02.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    bool ascending;
        
    if (a <= b && b <= c)
    {
        ascending = true;
    }
    else
    {
        ascending = false;
    }

    std::cout << ascending << '\n';

    return 0;
}

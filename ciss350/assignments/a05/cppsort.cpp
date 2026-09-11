// file: cppsort.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::ostream & operator<<(std::ostream & cout, const std::vector< int > & v)
{
    cout << '{';
    std::string delim = "";
    for (auto & e: v)
    {
        cout << delim << e;
        delim = ", ";
    }
    cout << '}';
    return cout;
}

int main()
{
    std::vector< int > v {1, 3, 5, 6, 4, 2};
    std::sort(v.begin(), v.end());
    std::cout << v << '\n';

    v = {1, 3, 5, 6, 4, 2};
    std::sort(v.begin(), v.end(), [](int x, int y){ return x < y; });
    std::cout << v << '\n';
    
    v = {1, 3, 5, 6, 4, 2};
    std::sort(v.begin(), v.end(), [](int x, int y){ return x > y; });
    std::cout << v << '\n';

    return 0;
}

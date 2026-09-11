#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template < typename T >
std::ostream & operator<<(std::ostream & cout, const std::vector< T > & v)
{
    cout << '{';
    std::string delim = "";
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        cout << delim << v[i]; delim = ", ";
    }
    cout << '}';
    return cout;
}

int main()
{
    std::vector< int > x {5, 3, 1, 2, 4, 0};
    std::cout << x << '\n';
    std::sort(x.begin(), x.end());
    std::cout << x << '\n';
    return 0;
    
}

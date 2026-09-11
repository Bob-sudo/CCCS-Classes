#include <iostream>
#include <sstream>

int main()
{
    char s[100] = "42";
    std::istringstream cin(s);
    int i;
    cin >> i;
    std::cout << i << ' ' << i + 1 << '\n';
    return 0;
}

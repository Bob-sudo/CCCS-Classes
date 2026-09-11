// File: pretty-print-recursion.cpp

#include <iostream>
#include <iomanip>

int f(int n)
{
    static int spaces = -4;
    spaces += 4;
    std::cout << std::setw(spaces) << "";
    std::cout << "f(" << n << ") enter ...\n";
    if (n < 2)
    {
        int ret = 1;
        std::cout << std::setw(spaces) << "";
        std::cout << "f(" << n << ") = " << ret << '\n';
        spaces -= 4;
        return ret;
    }
    else
    {
        int ret = f(n - 1) + f(n - 2);
        std::cout << std::setw(spaces) << "";
        std::cout << "f(" << n << ") = " << ret << '\n';
        spaces -= 4;
        return ret;
    }
}

int main()
{
    std::cout << "VALUE:" << f(3) << '\n';
    return 0;
}

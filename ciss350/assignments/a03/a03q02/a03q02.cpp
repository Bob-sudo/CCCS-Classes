// File: a03q02.cpp
// Name: Ethan Graham

#include <iostream>

int max_rec(int x[], int start, int end)
{
    if (start == end - 1)
    {
        int ret = x[0]; // set ret to correct value
        std::cout << "max_rec(x, " << start << ", " << end
                  << ") base case ... "
                  << "return " << ret << '\n';
        return ret;
    }
    else
    {
        std::cout << "max_rec(x, " << start << ", " << end
                  << ") recursive case ...\n";
        int ret = max_rec(x, start, end - 1); // set ret to correct value
        ret = ret > x[end - 1] ? ret : x[end - 1];
        std::cout << "max_rec(x, " << start << ", " <<  end
                  << ") recursive case ... "
                  << "return " << ret << '\n';
        return ret;
    }
}

int main()
{
    int n;
    std::cin >> n;
    int * x = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    int max = max_rec(x, 0, n);
    std::cout << max << '\n';
    delete [] x;
    return 0;
}

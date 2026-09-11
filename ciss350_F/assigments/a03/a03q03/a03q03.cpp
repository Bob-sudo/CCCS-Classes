// Name: Ethan Graham
// File: a03q03.cpp

#include <iostream>

int linearsearch_rec(int x[], int start, int end, int target)
{
    if (start == end)
    {
        int ret = -1; // set ret to correct value
        std::cout << "linearsearch_rec(x, " << start << ", " << end << ", "
                  << target << ") base case ... "
                  << "return " << ret << '\n';
        return ret;
    }
    else
    {
        std::cout << "linearsearch_rec(x, " << start << ", " << end << ", "
                  << target << ") recursive case ...\n";
        int ret = x[start] == target ?
            start : linearsearch_rec(x, start + 1, end, target); // set ret to correct value
        std::cout << "linearsearch_rec(x, " << start << ", " << end << ", "
                  << target << ") recursive case ... "
                  << "return " << ret << '\n';
        return ret;
    }
}

int main()
{
    int n, target;
    std::cin >> n;
    int * x = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    std::cin >> target;
    int index = linearsearch_rec(x, 0, n, target);
    std::cout << index << '\n';
    delete [] x;
    return 0;
}

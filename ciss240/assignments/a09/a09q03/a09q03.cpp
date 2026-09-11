//File: a09q03.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int n, a, num_sol = 0;
    std::cin >> n >> a;

    for(int x = 0; x < n; x++)
    {
        if(((x * x) % n) == a % n)
        {
            std::cout << x << ' ';
            num_sol += 1;
        }
    }
    std::cout << '\n' << num_sol << '\n';

    return 0;
}

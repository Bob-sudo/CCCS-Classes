#include <iostream>

void hanoi(int n, char from, char helper, char to)
{
    if(n == 1)
    {
        std::cout << from << " ---->" << to << '\n';
    }
    else
    {
        hanoi(n - 1, from, to, helper);
        hanoi(1, from, helper, to);
        hanoi(n - 1, helper, from, to);
    }     
}

int main()
{
    int n;
    std::cin >> n;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}

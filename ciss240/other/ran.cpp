#include <iostream>

int main()
{
    bool magic;
    int j, n = 1;
    std::cin >> j;

    for (int i = 0; i < 9; i++)
    {
        j = (j / n) % 10;
        n *= 10;
        if(j != (j / n) % 10)
        {
            magic = true;
        }
        else
        {
            magic = false;
        }
    }

    std::cout << magic << '\n';

    return 0;
}

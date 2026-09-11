#include <iostream>

void test_1(int n)
{
    for(int i = 0; i < n; i++)
    {
        //Print spaces
        for(int j = n - i; j > 1; j--)
        {
            std::cout << ' ';
        }
        //Draw triangle part
        for(int k = 0; k <= i; k++)
        {
            std::cout << (k % 2 == 0 ? '*' :  '-');
        }
        std::cout << '\n';
    }
}

void test_2(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - i; j > 1; j--)
        {
            std::cout << ' ';
        }
        for(int k = 0; k <= i; k++)
        {
            if(i % 2 == 0)
            {
                std::cout << (k % 2 == 0 ? '*' :  '-');
            }
            else
            {
                std::cout << '-';
            }
        }
        std::cout << '\n';
    }
}

int main()
{
    int n, o;
    std::cin >> n;
    std::cin >> o;

    switch(o)
    {
        case 1:
            test_1(n);
            break;
        case 2:
            test_2(n);
            break;
    }
}

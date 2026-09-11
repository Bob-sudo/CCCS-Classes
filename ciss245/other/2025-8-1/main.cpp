#include <iostream>

int main()
{
    int num;

    std::cin >> num;

    for(int i = num; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            std::cout << '*';    
        }
        std::cout << '\n';
    }

    return 0;
}

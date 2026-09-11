#include <iostream>

int main()
{   
    int num;
    std::cin >> num;
    int digits = 0;
    int div = 10;
    while(num > 0)
    {
        num /= div;
        digits++;
    }
    std::cout << digits << " Digits" << '\n';
    return 0;
}

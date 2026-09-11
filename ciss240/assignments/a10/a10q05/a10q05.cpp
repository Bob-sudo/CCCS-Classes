//File: a10q05.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int num, reverse = 0;
    std::cin >> num;
    int temp = num;

    while(temp > 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }

    bool is_palindrome;

    if(reverse == num)
    {
        is_palindrome = true;
    }
    else
    {
        is_palindrome = false;
    }

    std::cout << is_palindrome << '\n';

    return 0;
}

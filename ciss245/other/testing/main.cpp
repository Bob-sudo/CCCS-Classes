#include <iostream>

bool is_palindrome(char pal[], const int size)
{
    int L_indx = size - 1;
    bool is_pal;
    for (int i = 0; i < L_indx; i++)
    {
        if(pal[i] == pal[L_indx]) is_pal = true;
        else is_pal = false;
        L_indx--;
    }

    return is_pal;
}


int main()
{
    const int size = 5;
    char pal[size] = {'m', 'a', 'd', 'a', 'm'};
    std::cout << is_palindrome(pal, size) << '\n';
    
}

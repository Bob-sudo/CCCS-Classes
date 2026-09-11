// Name: Ethan
// File: a01q01
// Pancake-flipping for digits

#include <iostream>
#include <vector>
#include <string>

// Need this
std::vector<int> stringtovec(std::string s)
{
    std::vector<int> num(s.length(), 0);
    int n = s.length();

    for(int i = 0; i < n; ++i)
    {
        num[i] = (s[i] - 48);
    }

    return num;
}

void flip()
{
    
}

void pancakesort(int * start, int * end)
{
    for(int * i = end - 1; i >= start; --i)
    {
        
    }
}

int main()
{
    std::string n;
    
    std::cin >> n;

    std::vector<int> arr = stringtovec(n);
    int size = arr.size();

// Display, prolly keep for now

    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << '\n';

return 0;
}

// File: a01q03.cpp
// Name: Ethan Graham

#include <iostream>

int last_alive(int n)
{
    bool alive[1000];
    for (int i = 0; i < n; ++i)
    {
        alive[i] = true;
    }
    
    int count = n, index = 0;
    while (count > 1)
    {
        int skip = 0;
        while (skip < 1)
        {
            index = (index + 1) % n;
            if (alive[index])
            {
                skip++;
            }
        }
        
        alive[index] = false; 
        count--;

        // Find the next alive rebel
        while (!alive[index])
        { 
            index = (index + 1) % n;
        }
    }
    
    return index; // Last survivor
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << last_alive(n) << '\n';

    return 0;
}

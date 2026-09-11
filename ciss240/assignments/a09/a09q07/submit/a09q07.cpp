//File: a09q07.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int n, numstars = 1;
    
    std::cin >> n;

    int numspaces = (n - 2) / 2;
    
    for(int i = 1; i <= n; i++)
    {
        if(numspaces < 0)
        {
            numspaces = 0;
        }
        
        //print spaces
        for(int j = 0; j < numspaces; j++)
        {
            std::cout << ' ';
        }
        //print stars
        for (int j = 0; j < numstars; j++)
        {
            std::cout << '*'; 
        }

        std::cout << '\n';
        
        if(i % 3 > 0)
        {
            numstars += 2;
            numspaces -= 1;
        }
        else
        {
            numstars -= 2;
            numspaces += 1;
        }
    }
}

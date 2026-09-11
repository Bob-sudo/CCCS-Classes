//File: a11q02.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    const int size = 10;
    double a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    int window;

    std::cin >> a0 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> window;

    double arr[size] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};
    
    for(int i = 0; i < size; i++)
    {
        double temp = 0;

        if(i + 1 >= window)
        {
            for(int j = i; j < window + i; j++)
            {
                temp += arr[j - window + 1] / window;
            }
            std::cout << std::fixed << std::setprecision(4) << temp << ' ';
        }
        else
        {
            std::cout << std::fixed << std::setprecision(4) << arr[i] << ' ';
        }
        
    }
    std::cout << '\n';

    return 0;
}

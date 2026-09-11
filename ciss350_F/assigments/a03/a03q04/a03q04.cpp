// File: a03q04.cpp
// Name: Ethan Graham

#include <iostream>
#include <string>

void print(int x[], int end)
{
    std::string delim = "";
    std::cout << '{';
    for (int i = 0; i < end; ++i)
    {
        std::cout << delim << x[i];
        delim = ", ";
    }
    std::cout << '}';
}
void bubblesort_rec(int x[], int start, int end)
{
    if (start >= end - 1)
    {
        std::cout << "bubblesort_rec(";
        print(x, end);
        std::cout << ", " << start << ", " << end
                  << ") base case ... return\n";
        return;
    }
    else
    {     
        std::cout << "bubblesort_rec(";
        print(x, end);
        std::cout << ", " << start << ", " << end
                  << ") recursive case ...\n";

        for (int i = start; i < end - 1; i++)
        {
            if (x[i] > x[i + 1])
            {
                int temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
        
        bubblesort_rec(x, start, end - 1);
        
        std::cout << "bubblesort_rec(";
        print(x, end);
        std::cout << ", " << start << ", " << end
                  << ") recursive case ... return\n";

        
        return;
    }
}
int main()
{
    int n;
    std::cin >> n;
    int * x = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    bubblesort_rec(x, 0, n);
    print(x, n);
    std::cout << '\n';
    delete [] x;
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <chrono>

void bubble_sort(int x[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(x[j] > x[j + 1])
            {
                int t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    double total_time = 0;

    for(int i = 0; i < k; i++)
    {
        int x[n] = {};
        for(int j = 0; j < n; j++)
        {
            x[i] = rand();
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        bubble_sort(x, n);
        auto end = std::chrono::high_resolution_clock::now();

        double time = std::chrono::duration<double, std::milli>(end - start).count();
        total_time += time;
    }

    std::cout << total_time / k << '\n';
    
    return 0;
}
 

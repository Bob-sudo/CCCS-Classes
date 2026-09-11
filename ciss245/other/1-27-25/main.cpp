#include <iostream>

// void print(int x[], int n = 6)
// {
//     std::cout << '{';
//     for (int i = 0; i < n; i++)
//     {
//         std::cout << x[i];
//         if (i < n - 1) std::cout << ", ";
//     }
//     std::cout << '}' << '\n';
// }

// int max(int x, int y)
// {
//     return (x >= y ? x : y);
// }

// double max(double x, double y)
// {
//     return (x >= y ? x : y);
// }

// int main()
// {
//     int x[] = {2, 3, 5, 7, 11, 13};
//     print(x);
//     print(x, 3);

//     std::cout << max(2, 3) << '\n';
//     std::cout << max_double(2.5, 3.7) << '\n';
//     // mx of int array
//     // max of double array
    
//     return 0;
// }

int main()
{
    int x = 42;
    std::cout << x << ' '
              << (unsigned long long)(&x) << '\n';
    int y = 0;
    std::cout << y << ' '
              << (unsigned long long)(&y) << '\n';
    
    std::cout << sizeof(x) << '\n';

    int z[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++)
    {
        std::cout << z[i] << ' '
                  << (unsigned long long)(&z[i])
                  << '\n';
    }

    return 0;
}

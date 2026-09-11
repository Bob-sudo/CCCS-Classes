// Name: Ethan Graham
// File: a02q03.cpp

#include <iostream>

int f(int n, int a = 3, int b = 1, int d = 2)
{
    if (n % d == 0) return n / d;
    else if (n % d != 0 && n > 1) return a * n + b;
    return 1;
}


int fs(int * &p, int n, int a, int b, int d, int N)
{
    p = new int[N];
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        n = f(n, a, b, d);
        p[count++] = n;
        if (n == 1) break;
    }

    return count;
}

int main()
{
    int a, b, d, n0, n1, N;
    int *p;

    std::cin >> a >> b >> d >> n0 >> n1 >> N;

    for (int j = n0; j <= n1; j++)
    {
        int count = fs(p, j, a, b, d, N);

        std::cout << a << ' ' << b << ' '
                  << d << ' ' << j << ' '
                  << n1 << ' ' << N << ' ';

        if (p[count - 1] == 1)
            std::cout << "pass ";
        else
            std::cout << "fail ";

        std::cout << count << ' ' << j << ' ';

        for (int i = 0; i < count; i++)
        {
            std::cout << p[i] << ' ';
        }
        std::cout << '\n';

        delete[] p; 
    }

    return 0;
}

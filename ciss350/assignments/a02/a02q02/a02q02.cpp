// File: a02q02.cpp
// Name: Ethan Graham

#include <iostream>

int f(int n, int a, int b, int d)
{
    if(n > 1)
    {
        return (n % d == 0 ? n / d : (a*n) + b);
    }
    else 
        return 1;
}

int fs(int * & p, int n, int a, int b, int d, int N)
{
    p = new int[N];
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        n = f(n, a, b, d);
        p[count++] = n;
        if(n == 1) break;
    }

    return count;
}

int main()
{
    int a, b, d, n, N;
    int *p;
    std::cin >> a >> b >> d >> n >> N;

    int count = fs(p, n, a, b, d, N);
    
    std::cout << a << ' ' << b << ' '
              << d << ' ' << n << ' '
              << N << ' ';
    std::cout << (p[count - 1] == 1 ? "pass " : "fail ");
    std::cout << count << ' ' << n << ' ';
    for(int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << ' ' << '\n';
    
    delete[] p;
    return 0;
}

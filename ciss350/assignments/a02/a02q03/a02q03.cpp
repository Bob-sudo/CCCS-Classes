// File: a02q03.cpp
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
    
    if(n == 1)
    {
        p[count] = 1;
        return count;
    }
    for(int i = 0; i < N; i++)
    {
        n = f(n, a, b, d);
        p[count++] = n;
        if(n <= 1) break;
    }

    return count;
}

void main_f(int * & p, int n, int a, int b, int d, int N)
{
    int count = fs(p, n, a, b, d, N);
    
    std::cout << a << ' ' << b << ' '
              << d << ' ' << n << ' '
              << N << ' ';
    std::cout << (p[count - 1] == 1  || p[count] == 1 ? "pass " : "fail ");
    std::cout << count << ' ' << n << ' ';
    for(int i = 0; i < count; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << ' ' << '\n';
    
    delete[] p;
}

int main()
{
    int a, b, d, n1, n2, N;
    int *p;
    std::cin >> a >> b >> d >> n1 >> n2 >> N;

    for(int i = n1; i <= n2; i++)
    {
        main_f(p, i, a, b, d, N);
    }
    
    return 0;
}

//File: a10q04.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int a, b;

    std::cin >> a >> b;
    std::cout << "perfect numbers: ";

    
    int sum = 1, perfect_num = 0;
    
    for(int n = a; n < b; n++)
    {
      int sum = 1;
      
      for(int i = 2; i*i <= n; i++)
      {
          if(n % i == 0)
          {
              if(i * i != n)
              {
                  sum += i + n / i;
              }
              else
                  sum += i;
          }
      }
      if(sum == n && n != 1)
      {
          std::cout << n << ' ';
          perfect_num++;
      }
    }

    std::cout << '\n' << "number of perfect numbers found: " << perfect_num;
    std::cout << '\n';

    return 0;
}

#include <iostream>

int count(int * start, int * end, int target)
{
    int c = 0;
    if (start >= end)
    {
        return 0;
    }
    else
    {
      if (*start == target)
      {
        c++;
      }
      return c + count(start + 1, end, target);
    }
}

int main()
{
    int x[] = {1, 2, 3, 4, 3, 2, 1, 2, 3, 4};
    std::cout << count(x + 2, x + 8, 3) << '\n';
}

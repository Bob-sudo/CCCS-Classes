#include <iostream>
#include "mymath.h"

int main()
{
    std::cout << max(3, 5) << '\n';
    std::cout << max(5, 3) << '\n';
    std::cout << max(3, 3) << '\n';

    std::cout << min(2, 3, 4) << '\n';

    return 0;
}

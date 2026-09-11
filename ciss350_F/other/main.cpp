#include <iostream>
#include "Mat.h"

int main()
{
    Mat m(3, 4);
    std::cout << m << '\n';
    std::cout << m.nrows() << '\n';
    
    return 0;
}

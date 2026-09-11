//File: a05q03
//Name: Ethan Graham

#include <iostream>
#include <cmath>

int main()
{
    double x, y, z, target;
    std::cin >> x >> y >> z >> target;

    bool explode = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) <= target;
    
    std::cout << explode << '\n';

    return 0;
}

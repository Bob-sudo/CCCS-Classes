#include <iostream>
#include "vec2d.h"

int main()
{
    vec2d v(1.1, 2.2);
    std::cout << "v:" << v << '\n';

    std::cout << "v[0]:" << v[0] << '\n'; // v[0] = v.operator[](0) return VALUE of v.x_
    v[0] = 4.4; // same as v[0] = v.operator[](0) return REFERENCE to v.x_
    std::cout << v << '\n';

    v *= 2.5; // v.operator*=(2.5)
    std::cout << v << '\n';
    std::cout << v * 2.5 << '\n'; // v * 2.5 same as
                                  // v.operator*(2.5)

    v[0] = 0;
    v[1] = 1;
    vec2d u(0.1, 0.2);
    std::cout << (u += v) << '\n';
    std::cout << u + v << '\n';

    vec2d w;
    std::cout << "w:" << w << '\n';
    
    std::cout << "v:" << v << '\n';
    std::cout << "2 * v:" << 2 * v  // same as operator*(2, v)
              << '\n';              // or 2.operator*(v)
    
    return 0;
}

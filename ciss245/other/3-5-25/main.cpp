#include <iostream>
#include "IntPointer.h"

int main()
{
    // // REVIEW
    // int * p;
    // // ...
    // p = new int;
    // std::cout << (*p) << '\n';
    // *p= 42;
    // *p += 4;
    // // ...
    // delete p; // usually forget to deallocate ... leak!
    // // ...

    IntPointer p;
    std::cout << p.dereference() << '\n';
    std::cout << (*p) // *p is the same as p.operator*
              << '\n';
    //*p = 42;
    //std::cout << (*p) << '\n';

    *p = 42;
    std::cout << (*p) << '\n';
    return 0;
}

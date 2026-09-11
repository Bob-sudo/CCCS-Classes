#include <iostream>
#include "IntPointer.h"

IntPointer::IntPointer()
    : p_(new int)
{
    std::cout << "IntPointer::IntPointer() ... allocated\n";
}

int IntPointer::dereference() const
{
    return *p_;
}

int IntPointer::operator*() const
{
    return *p_;
}

int & IntPointer::operator*()
{
    return *p_;
}

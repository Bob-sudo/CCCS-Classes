#include "cell.h"

bool Cell::operator==(const Cell & other) const
{
    return r == other.r && c == other.c;
}

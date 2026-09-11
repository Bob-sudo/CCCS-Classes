#include "Mat.h"
#include <iostream>

Mat::Mat(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new double[nrows * ncols])
{}

Mat::~Mat()
{
    delete[] p_;
}

int Mat::nrows() const
{
    return nrows_;
}

int Mat::ncols() const
{
    return ncols_;
}

std::ostream & operator<<(std::ostream & cout, const Mat & m)
{
    for (int r = 0; r < m.nrows(); ++r)
    {
        for (int c = 0; c < m.ncols(); ++c)
        {
            std::cout << m(r, c) << ' ';
        }
        std::cout << '\n';
    }
    return cout;
}

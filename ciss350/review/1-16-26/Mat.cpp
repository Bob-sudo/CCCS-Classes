#include <iostream>
#include "Mat.h"

Mat::Mat(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new int[nrows * ncols])
{}



Mat::Mat(const Mat & m)
    : nrows_(m.nrows_), ncols_(m.ncols_), p_(new int[m.nrows_ * m.ncols_])
{
    for(int i = 0; i < m.nrows_ * m.ncols_; i++)
    {
        p_[i] = m.p_[i];
    }
}

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

int Mat::operator()(int r, int c) const
{
    return p_[r * ncols_ + c];
}

int & Mat::operator()(int r, int c)
{
    return p_[r * ncols_ + c];
}

Mat &  Mat::operator=(const Mat & m)
{
    if(this != &m)
    {
        nrows_ = m.nrows_;
        ncols_ = m.ncols_;
        delete[] p_; // release the array
        p_ = new int[m.nrows_ * m.ncols_];
        for(int i = 0; i < m.nrows_ * m.ncols_; i++)
        {
            p_[i] = m.p_[i];
        }
    }
    return(*this);
}

Mat & Mat::operator+=(const Mat & n)
{
    if(nrows != n.nrows_ || ncols_ != n.ncols_)
    {
        throw MatrixSizeIncompatible();
    }
    for(int i = 0; i < nrows_ * ncols_; i++)
    {
        p_[i] += n.p_[i];
    }
    return (*this);
}

Mat Mat::operator+(const Mat & n) const
{
    return (Mat(*this) += n); // Creates a copy of m, and adds n to it
}

std::ostream & operator<<(std::ostream & cout, const Mat & m)
{
    cout << '{';
    for(int r = 0; r < m.nrows(); ++r)
    {
        cout << ' ';
        for(int c = 0; c < m.ncols(); ++c)
        {
            cout << m(r, c);
            if(c < m.ncols() - 1) std::cout << ", ";
        }
        cout << ' ' << std::endl;
    }
    cout << '}';
    return cout;
}

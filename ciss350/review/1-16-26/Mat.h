#ifndef MAT_H
#define MAT_H

class MatrixSizeIncompatible
{};

class Mat
{
public:
    Mat(int nrows, int ncols); // Constructor
    ~Mat();                    // Destructor
    Mat(const Mat & m);        // Copy Constructor
    int nrows() const;
    int ncols() const;
    int operator()(int r, int c) const;
    int & operator()(int r, int c);
    Mat & operator=(const Mat & m);
    Mat & operator+=(const Mat & n);
    Mat operator+(const Mat & n) const;
private:
    int nrows_;
    int ncols_;
public:
    int *p_;
};

std::ostream & operator<<(std::ostream &, const Mat &);

#endif

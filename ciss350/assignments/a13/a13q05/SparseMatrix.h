#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "HashTable.h"

class IndexError
{};

class MatrixKey : public Hashable
{
  public:
    MatrixKey(int row, int col)
        : row_(row), col_(col)
    {}

    unsigned int hash() const override
    {
        std::string s = std::to_string(row_) + "," + std::to_string(col_);
        
        unsigned int h = 0;
        unsigned int power = 1;
        for (unsigned int i = 0; i < s.length(); i++)
        {
            h += int(s[i]) * power; power *= 10;
        }
        return h;
    }

    bool operator==(const MatrixKey& other) const
    {
        return row_ == other.row_ && col_ == other.col_;
    }
    
  private:
    int row_;
    int col_;
};

class SparseMatrix
{
  public:
    SparseMatrix(int row, int col)
        : row_(row), col_(col)
    {}

    double get(int row, int col)
    {
        if (row < 0 || row >= row_ || col < 0 || col >= col_)
            throw IndexError();
        
        MatrixKey key(row, col);
        try
        {
            return table.get(key);
        }
        catch(KeyError&)
        {
            return 0;
        }
    }

    void set(int row, int col, double value)
    {
        if (row < 0 || row >= row_ || col < 0 || col >= col_)
            throw IndexError();
        
        MatrixKey key(row, col);

        if(value == 0)
        {
            try
            {
                table.remove(key);
            }
            catch(KeyError&)
            {}
        }
        else
        {
            table.set(key, value);
        }
    }
  private:
    int row_;
    int col_;
    HT<MatrixKey, double> table;
};

#endif

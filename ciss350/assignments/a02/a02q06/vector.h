// File: vector.h

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>

class IndexError
{};

template < typename T >
class vector
{
  public:
  vector(int size)
      : size_(size), capacity_(size), p_(new T[size])
    {}
    
  // TODO: Set attributes, copy values at x.p_ to p_
  vector(const vector & x)
      : size_(0), p_(new T[0])
    {
        for (int i = 0; i < x.size_; ++i)
        {
            p_[i] = (x.p_)[i];
        }
    }
    
    vector(T arr[], int n)
    {
    }
    
    ~vector()
    {
        // TODO: deallocate memory used by p
        delete[] p;
    }
    
    int size() const
    {
        return size_;
    }
    
    int capacity() const
    {
        return capacity_;
    }
    
    T operator[](int index) const
    {
        if (index < 0 || index > size_)
        {
            throw IndexError();
        }
        // FIXIT
        return p_[0];
    }
    
    T & operator[](int index)
    {
        // FIXIT
        return p_[0];
    }
    
    const vector & operator=(const vector & x)
        {
            if (this != &x)
            {
                // FIXIT: Similar to copy constructor
            }
            return (*this);
        }
    
    bool operator==(const vector & x) const
        {
            // FIXIT
            return true;
        }
    
    void insert(int index, const T & value)
    {
        // TODO
    }
    
    void push_back(const T & value)
    {
        // TODO
    }
    
  private:
    int size_;
    int capacity_;
    T * p_;
};

template < typename T >

std::ostream & operator<<(std::ostream & cout,
                          const vector< T > & x)
{
    int size = x.size();
    cout << '{';
    std::string delim = "";
    for (int i = 0; i < size; ++i)
    {
        cout << delim << x[i]; // Recall: x[i] calls x.operator[](i)
        delim = ", ";
    }
    cout << '}';
    return cout;
}

#endif

// File: Deque.h

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class UnderflowError {}; // this is thrown when removing a value from an
                         // empty deque

class OverflowError {};  // this is thrown when a value cannot be added
                         // (when memory cannot be allocated)

template <typename T>
class Deque
{
  public:
    Deque()
        : size_(0), capacity_(5)
    {
        x_ = new T[capacity_];
    }

    Deque(const Deque & other)
        : size_(other.size_), capacity_(other.capacity_)
    {
        x_ = new T[capacity_];
        for (int i = 0; i < size_; i++)
        {
            x_[i] = other.x_[i];
        }
    }

    Deque& operator=(const Deque & other)
    {
        if (this != &other)
        {
            delete[] x_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            x_ = new T[capacity_];
            
            for (int i = 0; i < size_; i++)
            {
                x_[i] = other.x_[i];
            }
        }
        return *this;
    }

    ~Deque()
    {
        delete[] x_;
    }

    void insert_head(const T & val)
    {
        if (size_ == capacity_) resize(capacity_ + 1);

        for (int i = size_; i > 0; i--)
        {
            x_[i] = x_[i - 1];
        }

        x_[0] = val;
        size_++;
    }

    void insert_tail(const T & val)
    {
        if (size_ == capacity_) resize(capacity_ * 2);
        else x_[size_++] = val;
    }

    T remove_head()
    {
        if (size_ == 0) throw UnderflowError();
        else
        {
            T val = x_[0];
            for (int i = 1; i < size_; i++)
            {
                x_[i - 1] = x_[i];
            }
            size_--;
            return val;  
        }
    }

    T remove_tail()
    {
        if (size_ == 0) throw UnderflowError();
        else return x_[size_--];
    }

    void clear()
    {
        size_ = 0;
    }

    bool is_empty() const
    {
        return size_ == 0;
    }

    int get_size() const
    {
        return size_;
    }

    int get_x(int i) const
    {
        return x_[i];
    }

  private:
    T * x_;
    int size_;
    int capacity_;

    void resize(int new_cap)
    {
        T * new_x = new (std::nothrow) T[new_cap];

        // If new_x can't be assigned
        if (!new_x)
        {
            throw OverflowError();
        }
        
        for(int i = 0; i < size_; i++)
        {
            new_x[i] = x_[i];
        }
        
        delete[] x_;
        x_ = new_x;
        capacity_ = new_cap; 
    }
};


template <typename T>
std::ostream& operator<<(std::ostream& cout, const Deque<T> & dq)
{
    cout << "[";
    for (int i = 0; i < dq.get_size(); ++i)
    {
        cout << dq.get_x(i);
        if (i != dq.get_size() - 1) cout << ", ";
    }
    cout << "]";
    return cout;
}

#endif

// Name: Ethan Graham
// File: vector.h

#ifndef VECTOR_H
#define VECTOR_H

template < typename T >
class vector
{
  public:
    class iterator;
    class const_iterator;
    class iterator
    {
      public:
      iterator(T * const p)
          : p_(p)
        {}
        iterator & operator++()
        {
            ++p_;
            return *this;
        }
        const iterator operator++(int)
        {
            iterator temp = *this;
            ++p_;
            return temp;
        }
        iterator & operator--()
        {
            --p_;
            return *this;
        }
        const iterator operator--(int)
        {
            iterator temp = *this;
            --p_;
            return temp;
        }
        const T & operator*() const
        {
            return *p_;
        }
        T & operator*()
        {
            return *p_;
        }
        // += operator
        iterator operator+=(int n)
        {
            p_ += n;
            return *this;
        }
        iterator operator-=(int n)
        {
            p_ -= n;
            return *this;
        }
        // This is used by const_iterator(const iterator &)
        T * p() const
        {
            return p_;
        }
        
      private:
        T * p_;
    };
    class const_iterator
    {
      public:
        const_iterator(T * p)
        {}
      const_iterator(const iterator & p)
          : p_(p.p())
        {}
        const_iterator & operator++()
        {
            ++p_;
            return *this;
        }
        const const_iterator operator++(int)
        {
            const_iterator temp = *this;
            ++p_;
            return temp;
        }
        const_iterator & operator--()
        {
            --p_;
            return *this;
        }
        const const_iterator operator--(int)
        {
            const_iterator temp = *this;
            --p_;
            return temp;
        }
        const T & operator*() const
        {
            return *p_;
        }
      private:
        T * p_;
    };
  vector(int size, int val)
      : capacity_(size), size_(size), p_(new T[size])
    {
        for (int i = 0; i < size; ++i)
        {
            p_[i] = val;
        }
    }
    ~vector()
    {}
    // TODO: copy constructor
    vector(const vector& other)
        : capacity_(other.capacity_), size_(other.size_), p_(new T[other.size_])
    {
        for(int i = 0; i < size_; i++)
        {
            p_[i] = other.p_[i];
        }
    }
    // TODO: assignment operator
    vector& operator=(const vector& other)
        {
            if(this == &other)
            {
                return *this;
            }

            delete[] p_;

            capacity_ = other.capacity_;
            size_ = other.size_;
            p_ = new T[capacity_];
            for (int i = 0; i < size_; ++i)
            {
                p_[i] = other.p_[i];
            }
            return *this;
        }
    iterator begin()
    {
        // TODO: return iterator object that points to p_[0];
        return p_;
    }
    const_iterator begin() const
    {
        // TODO: return const_iterator object that points to p_[0];
        return p_;
    }
    iterator end()
    {
        // TODO: return iterator object that points to p_[size_];
        return p_ + size_;
    }
    const_iterator end() const
    {
        // TODO: return const_iterator object that points to p_[size_];
        return p_ + size_;
    }
    const T & operator[](int i) const
    {
        return p_[i];
    }
    T & operator[](int i)
    {
        return p_[i];
    }

    // += operator
    vector& operator +=(const vector& other)
    {
        if(size_ + other.size_ > capacity_)
        {
            capacity_ = size_ + other.size_;

            T* newData = new T[capacity_];

            for(int i = 0; i < size_; i++)
            {
                newData[i] = p_[i];
            }

            delete[] p_;
            p_ = newData;
        }
        for(int i = 0; i < other.size_; i++)
        {
            p_[i + size_] = other.p_[i];
        }
        
        size_ += other.size_;
        return *this;
    }
  private:
    int capacity_;
    int size_;
    T * p_;
};

#endif

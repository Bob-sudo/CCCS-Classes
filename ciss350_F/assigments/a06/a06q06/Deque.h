#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "DLList.h"
#include "DLNode.h"

// File: Deque

class UnderflowError // An UnderflowError object is thrown
{};                  // if you execute any operation to
                     // remove a value from a deque that is
                     // empty.

template < typename T >
class Deque
{
  public:
    Deque()
    {}
    
    void push_front(const T& key)
    {
        list_.insert_head(key);
    }
    
    void push_back(const T& key)
    {
        list_.insert_tail(key);
    }

    const T front() const
    {
        return list_.get_head();
    }

    const T back() const
    {
        return list_.get_tail();
    }

    T& front()
    {
        return list_.get_head();
    }
    
    T& back()
    {
        return list_.get_tail();
    }
    
    void pop_front()
    {
        list_.remove_head();
    }

    void pop_back()
    {
        list_.remove_tail();
    }

    int size()
    {
        return list_.size();
    }

    bool is_empty()
    {
        return list_.is_empty();
    }

    void clear()
    {
        list_.clear();
    }

    friend std::ostream & operator <<(std::ostream & cout, const Deque<T> & n)
    {
        cout << n.list_ << '\n';
        return cout;
    }
    
  private:
    DLList< T > list_;
};

#endif

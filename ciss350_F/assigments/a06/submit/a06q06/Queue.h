#ifndef QUEUE_H
#define QUEUE_H

// File: Queue.h

#include <iostream>
#include "Deque.h"

template < typename T >
class Queue
{
  public:
    Queue()
    {}
    
    void enqueue(const T & x)
    {
        deque_.push_back(x);
    }

    const T front() const
    {
        return deque_.front();
    }

    const T back() const
    {
        return deque_.back();
    }

    T& front()
    {
        return deque_.front();
    }
    
    T& back()
    {
        return deque_.back();
    }

    void dequeue()
    {
        deque_.pop_front();
    }

    int size()
    {
        return deque_.size();
    }

    void clear()
    {
        deque_.clear();
    }

    bool is_empty()
    {
        return deque_.is_empty();
    }

    friend std::ostream & operator <<(std::ostream & cout, const Queue<T> & n)
    {
        cout << n.deque_;
        return cout;
    }
  private:
    Deque< T > deque_;
};

#endif

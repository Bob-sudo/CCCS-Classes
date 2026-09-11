// Deque.h
#ifndef QUEUE_H
#define QUEUE_H

#include "Deque.h"

template < typename T >
class Queue
{
  public:
    Queue()
    {}
    Queue(Deque<T> deque)
        : deque_(deque)
    {}
    ~Queue()
    {
        clear();
    }

    void enqueue(const T & x)
    {
        deque_.push_back(x);
    }

    void dequeue()
    {
        deque_.pop_front();
    }

    T& front()
    {
        return deque_.front();
    }

    const T& front() const
    {
        return deque_.front();
    }

    T& back()
    {
        
        return deque_.back();
    }

    const T& back() const
    {
        return deque_.back();
    }

    Deque<T> get_deque() const
    {
        return deque_;
    }
    
    int size()
    {
        return deque_.size();
    }

    bool is_empty()
    {
        return deque_.is_empty();
    }

    void clear()
    {
        deque_.clear();
    }

    bool get_verbose() const
    {
        return verbose_queue;
    }

    static void debug_printing(bool b)
    {
        verbose_queue = b;
    }
  private:
    Deque< T > deque_;
    static bool verbose_queue;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const Queue<T> & q)
{
    if(q.get_verbose())
    {
        Deque< T >::debug_printing(true);
        cout << "<Queue:" << '\n';
        Deque<T> p = q.get_deque();
        cout << p;
        cout << '>';
    }
    else
    {
        Deque< T >::debug_printing(false);
        Deque<T> p = q.get_deque();
        cout << p;
    }
    return cout;
}

template < typename T >
bool Queue<T>::verbose_queue = true; 

#endif

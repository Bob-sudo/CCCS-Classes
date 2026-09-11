// Deque.h
#ifndef DEQUE_H
#define DEQUE_H

#include "DLList.h"

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
    Deque(DLList<T> list)
        : list_(list)
    {}
    DLList<T> get_list() const
    {
        return list_;
    }

    void push_front(const T& value)
    {
        list_.insert_head(value);
    }
    
    void push_back(const T& value)
    {
        list_.insert_tail(value);
    }

    T& front()
    {
        return list_.get_head_sentinel()->get_next()->get_key();
    }

    const T& front() const
    {
        return list_.get_head_sentinel()->get_next()->get_key();
    }

    T& back()
    {
        
        return list_.get_tail_sentinel()->get_prev()->get_key();
    }

    const T& back() const
    {
        return list_.get_tail_sentinel()->get_prev()->get_key();
    }

    T pop_front()
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        return list_.remove_head();
    }
    
    T pop_back()
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        return list_.remove_tail();
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

    bool get_verbose() const
    {
        return verbose_deque;
    }

    static void debug_printing(bool b)
    {
        verbose_deque = b;
    }
    
  private:
    DLList< T > list_;
    static bool verbose_deque;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const Deque<T> & d)
{
    if(d.get_verbose())
    {
        cout << "<Deque:" << '\n';
        DLList<T> p = d.get_list();
        cout << p;
        cout << '>';
    }
    else
    {
        DLList< T >::debug_printing(false);
        DLList<T> p = d.get_list();
        cout << p;
    }
    return cout;
}

template < typename T >
bool Deque<T>::verbose_deque = true; 

#endif

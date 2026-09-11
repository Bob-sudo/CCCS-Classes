#ifndef STACK_H
#define STACK_H

#include "SLList.h"

class UnderflowError // An UnderflowError object is thrown if
{};                  // you execute pop() on an empty stack.

template < typename T >
class Stack
{
  public:
    Stack()
    {}
    Stack(SLList<T> list)
        : list_(list)
    {}
    ~Stack()
    {
        clear();
    }
    
    SLList<T> get_list() const
    {
        return list_;
    }

    void push(const T& n)
    {
        list_.insert_head(n);
    }

    void pop()
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        list_.remove_head();
    }

    T& top()
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        return list_[0];
    }
    
    const T& top() const
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        return list_[0];
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
        return verbose_stack;
    }

    static void debug_printing(bool b)
    {
        verbose_stack = b;
    }
    
  private:
    SLList< T > list_;
    static bool verbose_stack;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const Stack<T> & s)
{
    if(s.get_verbose())
    {
        cout << "<Stack:";
        SLList<T> p = s.get_list();
        cout << p;
        cout << '>';
    }
    else
    {
        SLList< T >::debug_printing(false);
        SLList<T> p = s.get_list();
        cout << p;
    }
    return cout;
}

template < typename T >
bool Stack<T>::verbose_stack = true; 


#endif

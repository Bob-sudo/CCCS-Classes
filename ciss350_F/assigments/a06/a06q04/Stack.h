#ifndef STACK_H
#define STACK_H

// File: Stack.h

#include <iostream>
#include "SLList.h"
#include "SLNode.h"

class UnderflowError // An UnderflowError object is thrown if
{};                  // you execute pop() on an empty stack.

template < typename T >

class Stack
{
  public:
    Stack()
    {}
    
    void push(const T & key)
    {
        list_.insert_head(key);
    }
    
    void pop()
    {
        if(list_.is_empty())
        {
            throw UnderflowError();
        }
        else
        {
            list_.remove_head();
        }
    }
    
    T& top()
    {
        return list_.get_head();
    }
    
    const T& top() const
    {
        return list_.get_head();
    }

    int size() const
    {
        return list_.size();
    }

    bool is_empty() const
    {
        return list_.is_empty();
    }

    void clear()
    {
        list_.clear();
    }
    
    friend std::ostream & operator <<(std::ostream & cout, const Stack<T> & n)
    {
        cout << n.list_;
        return cout;
    }
  private:
    SLList< T > list_;
};

#endif

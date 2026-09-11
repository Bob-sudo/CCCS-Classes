// File: DLNode.h

#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

template < typename T >

class DLNode
{
  public:
  DLNode(const T & key, DLNode * prev=NULL, DLNode * next=NULL)
      : key_(key), next_(next), prev_(prev)
    {}
    T get_key() const
    {
        return key_;
    }
    T& get_key_ref()
    {
        return key_;
    }
    DLNode* get_next() const
    {
        return next_;
    }
    DLNode* get_prev() const
    {
        return prev_;
    }
    void set_next(DLNode* newNext)
    {
        this->next_ = newNext;
    }
    void set_prev(DLNode* newPrev)
    {
        this->prev_ = newPrev;
    }
    void set_key(T newKey)
    {
        this->key_ = newKey;
    }

    friend std::ostream & operator<<(std::ostream & cout, const DLNode<T>& n)
    {
        if (verbose)
        {
            cout << "<DLNode " << &n << " key: " << n.key_
                 << ", next: " << n.next_
                 << ", previous: " << n.prev_ << '>';
        }
        else
        {
            cout << n.key_;
        }
        return cout;
    }

    static void debug_printing(bool b)
    {
        verbose = b;
    }
  private:
    T key_;
    DLNode * prev_;
    DLNode * next_;
    static bool verbose;
};

template < typename T >
bool DLNode<T>::verbose = true;

#endif

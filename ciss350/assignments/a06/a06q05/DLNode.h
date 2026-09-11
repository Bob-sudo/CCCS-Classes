#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

template < typename T >
class DLNode
{
  public:
  DLNode(const T & key, DLNode<T> * prev=NULL, DLNode<T> * next=NULL)
      : key_(key), next_(next), prev_(prev)
    {}

    T get_key() const
    {
        return key_;
    }

    T & get_key()
    {
        return key_;
    }

    void set_key(T n)
    {
        key_ = n;
    }

    DLNode<T> * get_prev() const
    {
        return prev_;
    }
    
    DLNode<T> * get_next() const
    {
        return next_;
    }

    void set_next(DLNode<T> * n)
    {
        next_ = n;
    }
    
    void set_prev(DLNode<T> * n)
    {
        prev_ = n;
    }

    bool get_verbose() const
    {
        return verbose;
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
std::ostream & operator<<(std::ostream & cout, const DLNode< T > & n)
{
    if(n.get_verbose())
    {
        cout << "<DLNode " << &n
             << " key:" << n.get_key() << ','
             << " prev:" << n.get_prev() << ','
             << " next:" << n.get_next() << '>';
    }
    else
        cout << n.get_key();
    return cout;
}

template < typename T >
bool DLNode<T>::verbose = true;

#endif

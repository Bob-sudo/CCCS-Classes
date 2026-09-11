// File: SLNode.h

#ifndef SLNODE_H
#define SLNODE_H

#include <iostream>

template < typename T >
class SLNode
{
  public:
  SLNode(const T & key, SLNode * next=NULL)
      : key_(key), next_(next)
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
    
    SLNode * get_next() const
    {
        return next_;
    }

    void set_next(SLNode * n)
    {
        next_ = n;
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
    SLNode * next_;
    static bool verbose;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const SLNode< T > & n)
{
    if(n.get_verbose())
    {
        cout << "<SLNode " << &n
             << " key:" << n.get_key() << ','
             << " next:" << n.get_next() << '>';
    }
    else
        cout << n.get_key();
    return cout;
}

template < typename T >
bool SLNode<T>::verbose = true;

#endif

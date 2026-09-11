// File: SLNode.h

#ifndef SLNODE_H
#define SLNODE_H

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
    SLNode* get_next() const
    {
        return next_;
    }
    void set_key(T newKey)
    {
        this->key_ = newKey;
    }
    void set_next(SLNode * newNext)
    {
        this->next_ = newNext;
    }
    T& get_key_ref()
    {
        return key_;
    }
    const T& get_key_ref() const
    {
        return key_;
    }
    friend std::ostream & operator<<(std::ostream & cout, const SLNode<T> & n)
    {
        if (verbose)
        {
            cout << "<SLNode " << &n << ' '
                 << "key:" << n.key_ << ", "
                 << "next: " << n.next_ << '>';
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
    SLNode * next_;
    static bool verbose;
};

template < typename T >
bool SLNode<T>::verbose = true;

#endif

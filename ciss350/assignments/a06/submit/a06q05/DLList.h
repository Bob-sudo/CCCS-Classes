#ifndef DLLIST_H
#define DLLIST_H

#include "DLNode.h"

class IndexError             // An IndexError object is thrown if
{};                          // an invalid index value is used in
                             // a method/operator in the SLList
                             // class.

class ValueError             // A ValueError object is thrown if
{};                          // an invalid value is used in a
                             // method/operator in the SLList class.
                             // If the value is an index value, then
                             // the IndexError class is used instead.

template < typename T >
class DLList
{
  public:
    DLList()
        : head_sentinel_(new DLNode<T>(T())),
          tail_sentinel_(new DLNode<T>(T()))
    {
        head_sentinel_->set_next(tail_sentinel_);
        tail_sentinel_->set_prev(head_sentinel_);
    }

    DLList(const DLList<T>& other)
        : head_sentinel_(new DLNode<T>(T())),
          tail_sentinel_(new DLNode<T>(T()))
    {
        head_sentinel_->set_next(tail_sentinel_);
        tail_sentinel_->set_prev(head_sentinel_);
    
        DLNode<T> * q = other.head_sentinel_->get_next();;
        while(q != other.tail_sentinel_)
        {
            insert_tail(q->get_key());
            q = q->get_next();
        }
    }
    
    ~DLList()
    {
        clear();
        delete head_sentinel_;
        delete tail_sentinel_;
    }

    DLNode<T>* get_head_sentinel() const
    {
        return head_sentinel_;
    }
    
    DLNode<T>* get_tail_sentinel() const
    {
        return tail_sentinel_;
    }

    void insert_head(const T& key)
    {
        DLNode<T> * p = new DLNode<T>(key,
                                      head_sentinel_,
                                      head_sentinel_->get_next());
        head_sentinel_->get_next()->set_prev(p);
        head_sentinel_->set_next(p);
    }

    void insert_tail(const T& key)
    {
        DLNode<T> * p = new DLNode<T>(key,
                                      tail_sentinel_->get_prev(),
                                      tail_sentinel_);
        tail_sentinel_->get_prev()->set_next(p);
        tail_sentinel_->set_prev(p);
    }

    T remove_head()
    {
        if(head_sentinel_->get_next() == tail_sentinel_)
        {
            throw ValueError();
        }
        DLNode<T> * temp = head_sentinel_->get_next();
        T value = temp->get_key();
        
        head_sentinel_->set_next(temp->get_next());
        temp->get_next()->set_prev(head_sentinel_);
            
        delete temp;
        return value;
    }

    T remove_tail()
    {
        if(tail_sentinel_->get_prev() == head_sentinel_)
        {
            throw ValueError();
        }
        DLNode<T> * temp = tail_sentinel_->get_prev();
        T value = temp->get_key();
        
        tail_sentinel_->set_prev(temp->get_prev());
        temp->get_prev()->set_next(tail_sentinel_);
        
        delete temp;
        return value;
    }

    DLNode<T>* find(const T& key)
    {
        if(head_sentinel_->get_next() == tail_sentinel_)
        {
            throw ValueError();
        }
        DLNode<T> * temp = head_sentinel_->get_next();
        while(temp->get_key() != key && temp->get_next() != tail_sentinel_)
        {
            temp = temp->get_next();
        }
        return (temp->get_key() == key ? temp : NULL);
    }

    T remove(DLNode<T> * node)
    {
        if(node == head_sentinel_ || node == tail_sentinel_ || node == NULL)
        {
            throw ValueError();
        }
        
        T value = node->get_key();
        
        node->get_prev()->set_next(node->get_next());
        node->get_next()->set_prev(node->get_prev());
        
        delete node;
        return value;
    }

    void clear()
    {
        DLNode<T>* p = head_sentinel_->get_next();
        while(p != tail_sentinel_)
        {
            DLNode<T>* temp = p;
            p = p->get_next();
            delete temp;
        }
        head_sentinel_->set_next(tail_sentinel_);
        tail_sentinel_->set_prev(head_sentinel_);
    }

    T& operator[](int index)
    {
        int count = 0;
        DLNode<T> * temp = head_sentinel_->get_next();
        while(count < index && temp != tail_sentinel_)
        {
            temp = temp->get_next();
            count++;
        }

        if(temp == tail_sentinel_ || index < 0)
        {
            throw IndexError();
        }
        else
        {
            return temp->get_key();
        }
    }

    DLList<T>& operator=(const DLList & other)
    {
        if(this != &other)
        {
            clear();

            DLNode<T> * temp = other.head_sentinel_->get_next();
            while(temp != other.tail_sentinel_)
            {
                insert_tail(temp->get_key());
                temp = temp->get_next();
            }
        }
        return *this;
    }

    int size()
    {
        int count = 0;
        DLNode<T> * temp = head_sentinel_->get_next();
        while(temp != tail_sentinel_)
        {
            temp = temp->get_next();
            count++;
        }
        return count;
    }

    bool is_empty()
    {
        if(head_sentinel_->get_next() == tail_sentinel_)
            return true;
        else
            return false;
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
    DLNode<T>* head_sentinel_;
    DLNode<T>* tail_sentinel_;
    static bool verbose;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const DLList< T > & l)
{
    if(l.get_verbose())
    {
        cout << "<DLList " << &l << ' '
             << "head sentinel:" << l.get_head_sentinel() << ' '
             << "tail sentinel:" << l.get_tail_sentinel() << '\n';
        DLNode<T> * p = l.get_head_sentinel()->get_next();
        while(p != l.get_tail_sentinel())
        {
            cout << (*p) << '\n';
            p = p->get_next();
        }
        cout << '>';
    }
    else
    {
        
        if(l.get_head_sentinel() != NULL)
        {
            cout << '[';
            DLNode<T> * p = l.get_head_sentinel()->get_next();
            
            while(p != l.get_tail_sentinel())
            {
                cout << p->get_key();
                
                p = p->get_next();
                if(p != l.get_tail_sentinel())
                {
                    cout << ' ';
                }
            }
            cout << ']';
        }
    }
    return cout;
}

template < typename T >
bool DLList<T>::verbose = true;

#endif

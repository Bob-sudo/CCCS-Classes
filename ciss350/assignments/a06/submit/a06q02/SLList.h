// File: SLList.h
#ifndef SLLIST_H
#define SLLIST_H

#include "SLNode.h"

class IndexError // An IndexError object is thrown if
{};              // an invalid index value is used in
                 // a method/operator in the SLList
                 // class.

class ValueError // A ValueError object is thrown if
{};              // an invalid value is used in a
                 // method/operator in the SLList class.
                 // If the value is an index value, then
                 // the IndexError class is used instead.


template < typename T >
class SLList
{
  public:
  SLList()
      : phead_(NULL)
   {}
    
    ~SLList()
    {
        clear();
    }

  SLList(const SLList<T>& other)
      : phead_(NULL)
    {
        SLNode<T>* curr = other.phead_;
        while (curr != NULL)
        {
            insert_tail(curr->get_key());
            curr = curr->get_next();
        }
    }
    
    SLNode<T>* get_phead() const
    {
        return phead_;
    }
    
    void insert_head(const T & key)
    {
        SLNode<T> * q = new SLNode<T>(key, phead_);
        phead_ = q;
    }
    
    void insert_tail(const T & key)
    {
        SLNode<T> * q = new SLNode<T>(key);

        if(phead_ == NULL)
        {
            phead_ = q;
            return;
        }
        
        SLNode<T> * newNode = phead_;
        while(newNode->get_next() != NULL)
        {
            newNode = newNode->get_next();
        }
        newNode->set_next(q);
    }

    T remove_head()
    {
        if (phead_ == NULL)
        {
            throw ValueError();
        }
        
        SLNode<T> * temp = phead_;
        T value = temp->get_key();
        phead_ = phead_->get_next();
        
        delete temp;
        
        return value;
    }

    T remove_tail()
    {
        if (phead_ == NULL)
        {
            throw ValueError();
        }
        
        SLNode<T> * temp = phead_;
        SLNode<T> * prev = NULL;
        while(temp->get_next() != NULL)
        {
            prev = temp;
            temp = temp->get_next();
        }

        T value = temp->get_key();
        
        delete temp;
        prev->set_next(NULL);
        
        return value;
    }

    SLNode<T> * find(const T & key)
    {
        if(phead_ == NULL)
        {
            throw ValueError();
        }
        
        SLNode<T> * node = phead_;
        while(node->get_key() != key && node->get_next() != NULL)
        {
            node = node->get_next();
        }
        
        return (node->get_key() == key ? node : NULL);
    }
    
    T remove(const SLNode<T> * node)
    {
        if(phead_ == NULL || node == NULL)
        {
            throw ValueError();
        }
        
        if (node == phead_)
        {
            return remove_head();
        }

        SLNode<T> * prev = phead_;

        while (prev != NULL && prev->get_next() != node)
        {
            prev = prev->get_next();
        }

        if (prev == NULL || prev->get_next() == NULL)
        {
            throw ValueError();
        }

        SLNode<T>* target = prev->get_next();
        T value = target->get_key();
        prev->set_next(target->get_next());
        delete target;

        return value;
    }

    T remove(const T & key)
    {
        if(phead_ == NULL)
        {
            throw ValueError();
        }
        
        if (key == phead_->get_key())
        {
            return remove_head();
        }

        SLNode<T> * prev = phead_;

        while (prev != NULL &&
               prev->get_next() != NULL
               && prev->get_next()->get_key() != key)
        {
            prev = prev->get_next();
        }

        if (prev == NULL || prev->get_next() == NULL)
        {
            throw ValueError();
        }

        SLNode<T>* target = prev->get_next();
        T value = target->get_key();
        prev->set_next(target->get_next());
        delete target;

        return value;
    }

    void clear()
    {
        while (phead_ != NULL)
        {
            SLNode<T>* temp = phead_;
            phead_ = phead_->get_next();
            delete temp;
        }
    }

    SLList<T>& operator=(const SLList & other)
    {
        if(this != &other)
        {
            clear();

            SLNode<T> * temp = other.phead_;
            while(temp != NULL)
            {
                insert_tail(temp->get_key());
                temp = temp->get_next();
            }
        }
        return *this;
    }

    T& operator[](int index)
    {
        int count = 0;
        SLNode<T> * temp = phead_;
        while(count < index)
        {
            temp = temp->get_next();
            count++;
        }

        if(temp == NULL || index < 0)
        {
            throw IndexError();
        }
        else
        {
            return temp->get_key();
        }
    }

    int size()
    {
        int count = 0;
        SLNode<T> * temp = phead_;
        while(temp != NULL)
        {
            temp = temp->get_next();
            count++;
        }
        return count;
    }

    bool is_empty()
    {
        if(phead_ == NULL)
            return true;
        else
            return false;
    }

    bool get_verbose() const
    {
        return verbose_list;
    }

    static void debug_printing(bool b)
    {
        verbose_list = b;
    }
    
  private:
    SLNode < T > * phead_;
    static bool verbose_list;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const SLList<T> & l)
{
    if(l.get_verbose())
    {
        cout << '\n';
        cout << "<SLList phead:" << &l << '\n';
        SLNode<T> * p = l.get_phead();
        while (p != NULL)
        {
            std::cout << (*p) << '\n';
            p = p->get_next();
        }
        cout << '>';
    }
    else
    {
        SLNode<T> * p = l.get_phead();
        cout<< '[';
        while (p != NULL)
        {
            std::cout << p->get_key() << ' ';
            p = p->get_next();
        }
        cout << ']';
    }
    return cout;
}

template < typename T >
bool SLList<T>::verbose_list = true;

#endif

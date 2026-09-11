// File: SLList.h
#ifndef SLLIST_H
#define SLLIST_H

#include "SLNode.h"

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

    SLList<T>& operator=(const SLList<T>& other)
    {
        if (this != &other)
        {
            clear();

            SLNode<T>* curr = other.phead_;
            while (curr != NULL)
            {
                insert_tail(curr->get_key());
                curr = curr->get_next();
            }
        }
        return *this;
    }

    T& get_head()
    {
        if(phead_ == NULL)
        {
            throw ValueError();
        }
        return phead_->get_key_ref();
    }

    const T& get_head() const
    {
        if(phead_ == NULL)
        {
            throw ValueError();
        }
        return phead_->get_key_ref();
    }
    void insert_head(const T& key)
    {
        phead_ = new SLNode<T>(key, phead_);
    }
    void insert_tail(const T& n)
    {
        SLNode<T>* newNode = new SLNode<T>(n, NULL);

        if (phead_ == NULL)
        {
            phead_ = newNode;
            return;
        }

        SLNode<T>* last = phead_;
        
        while(last->get_next() != NULL)
        {
            last = last->get_next();
        }

        last->set_next(newNode);
    }

    T remove_head()
    {   
        SLNode<T>* temp = phead_;
        T value = temp->get_key();
        
        phead_ = phead_->get_next();
        
        delete temp;
        
        return value;
    }
    
    T remove_tail()
    {   
        SLNode<T>* curr = phead_;
        SLNode<T>* prev = NULL;

        while(curr->get_next() != NULL)
        {
            prev = curr;
            curr = curr->get_next();
        }
        
        T value = curr->get_key();

        delete curr;
        prev->set_next(NULL);

        return value;
    }

    SLNode<T>* find(const T& n)
    {
        SLNode<T>* target = phead_;

        while (target != NULL)
        {
            if(target->get_key() == n)
                return target;
            target = target->get_next();
        }

        return NULL;
    }

    T remove(const SLNode<T>* n)
    {
        if (phead_ == NULL || n == NULL)
        {
            throw ValueError();
        }

        if (phead_ == n)
        {
            T value = phead_->get_key();
            SLNode<T>* temp = phead_;
            phead_ = phead_->get_next();
            delete temp;
            return value;
        }

        SLNode<T>* prev = phead_;
        
        while (prev != NULL && prev->get_next() != n)
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

    
    T remove(const T& key)
    {
        if (phead_ == NULL)
        {
            throw ValueError();
        }

        if (phead_->get_key() == key)
        {    
            SLNode<T>* temp = phead_;
            T value = temp->get_key();
            phead_ = phead_->get_next();
            delete temp;
            return value;
        }

        SLNode<T>* prev = phead_;
        
        while (prev->get_next() != NULL && prev->get_next()->get_key() != key)
        {
            prev = prev->get_next();
        }

        if (prev->get_next() == NULL)
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
    
    friend std::ostream & operator<<(std::ostream & cout, const SLList<T> & n)
    {
        if (verbose_list)
        {
            SLNode<T>* p = n.phead_;
            cout << '\n';
            cout << "<SLList " << &n << ' '
                 << "phead:" << n.phead_ << '\n';
            while(p != NULL)
            {
                cout << (*p) <<'\n';
                p = p->get_next();
            }
            cout << '>';
        }
        else
        {
            SLNode<T>* p = n.phead_;
            cout << '[';
            
            while(p != NULL)
            {
                cout << (*p);
                p = p->get_next();
                
                if(p != NULL)
                {
                    cout << ", ";
                }
            }
            cout << ']';
            
            cout << '\n';
        }
        return cout;
    }

    T& operator[](int index)
    {
        if (index < 0 || phead_ == NULL)
        {
            throw IndexError();
        }

        SLNode<T>* curr = phead_;
        int i = 0;

        while (curr != NULL && i < index)
        {
            curr = curr->get_next();
            i++;
        }

        if(curr == NULL)
        {
            throw IndexError();
        }

        return curr->get_key_ref();
    }

    int size() const
    {
        int i = 0;
        SLNode<T>* temp = phead_;

        while (temp != NULL)
        {
            temp = temp->get_next();
            i++;
        }

        return i;
    }
    
    bool is_empty() const
    {
        return phead_ == NULL;
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
bool SLList<T>::verbose_list = true;

#endif

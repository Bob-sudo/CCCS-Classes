#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
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
        : head_sentinel_(NULL), tail_sentinel_(NULL)
    {}

    DLList(const DLList<T>& other)
        : head_sentinel_(NULL), tail_sentinel_(NULL)
    {
        DLNode<T>* curr = other.head_sentinel_;
        while (curr != NULL)
        {
            insert_tail(curr->get_key());
            curr = curr->get_next();
        }
    }

    ~DLList()
    {
        clear();
    }

    DLList<T>& operator=(const DLList<T>& other)
    {
        if (this != &other)
        {
            clear();

            DLNode<T>* curr = other.head_sentinel_;
            while (curr != NULL)
            {
                insert_tail(curr->get_key());
                curr = curr->get_next();
            }
        }
        return *this;
    }

    const T get_head() const
    {
        if(head_sentinel_ == NULL)
        {
            throw ValueError();
        }
        return head_sentinel_->get_key();
    }
    const T get_tail() const
    {
        if(tail_sentinel_ == NULL)
        {
            throw ValueError();
        }
        return tail_sentinel_->get_key();
    }

    T& get_head()
    {
        if(head_sentinel_ == NULL)
        {
            throw ValueError();
        }
        return head_sentinel_->get_key_ref();
    }
    T& get_tail()
    {
        if(tail_sentinel_ == NULL)
        {
            throw ValueError();
        }
        return tail_sentinel_->get_key_ref();
    }
    
    void insert_head(const T& n)
    {
        DLNode<T>* p = new DLNode<T>(n, NULL, NULL);
        if (head_sentinel_ == NULL)
        {
            head_sentinel_ = p;
            tail_sentinel_ = p;
        }
        else
        {
            p->set_next(head_sentinel_);          
            head_sentinel_->set_prev(p);
            head_sentinel_ = p;
        }
    }
    void insert_tail(const T& n)
    {
        DLNode<T> * p = new DLNode<T>(n, NULL, NULL);

        if (head_sentinel_ == NULL)
        {
            head_sentinel_ = p;
            tail_sentinel_ = p;
        }
        else
        { 
            p->set_prev(tail_sentinel_);
            tail_sentinel_->set_next(p);
            tail_sentinel_ = p;
        }
    }

    T remove_head()
    {
        if(head_sentinel_ == NULL)
        {
            throw ValueError();
        }
        
        DLNode<T>* temp = head_sentinel_;
        T value = temp->get_key();

        if(head_sentinel_ != tail_sentinel_)
        {
            head_sentinel_= head_sentinel_->get_next();
        }
        else
        {
            head_sentinel_ = NULL;
            tail_sentinel_ = NULL;
        }
        delete temp;
        return value;       
    }

    T remove_tail()
    {
        if(tail_sentinel_ == NULL)
        {
            throw ValueError();
        }
     
        DLNode<T>* temp = tail_sentinel_;
        T value = temp->get_key();

        if(tail_sentinel_ != head_sentinel_)
        {
            tail_sentinel_ = tail_sentinel_->get_prev();
        }
        else
        {
            head_sentinel_ = NULL;
            tail_sentinel_ = NULL;
        }
        
        delete temp;
        return value;
    }

    DLNode<T>* find(const T& n)
    {
        DLNode<T>* target = head_sentinel_;

        while (target != NULL)
        {
            if(target->get_key() == n)
                return target;
            target = target->get_next();
        }

        return NULL;
    }

    T remove (const DLNode<T>* n)
    {
        if(head_sentinel_ == NULL || n == NULL)
        {
            throw ValueError();
        }

        if (head_sentinel_ == n)
        {
            DLNode<T>* temp = head_sentinel_;
            T value = temp->get_key();
            head_sentinel_= head_sentinel_->get_next();
            head_sentinel_->set_prev(tail_sentinel_);
            tail_sentinel_->set_next(head_sentinel_);
            delete temp;
            return value;
        }

        DLNode<T>* prev = head_sentinel_;

        while(prev->get_next() != NULL)
        {
            prev = prev->get_next();
        }

        DLNode<T>* target = prev->get_next();
        T value = target->get_key();
        prev->set_next(target->get_next());
        delete target;

        return value;
    }

    void clear()
    {
        int i = 0;
        while(head_sentinel_ != NULL)
        {
            //std::cout << "REMOVE: " << remove_head() << '\n';
            remove_head();
        }
    }
    
    friend std::ostream & operator<<(std::ostream & cout, const DLList<T>& n)
    {
        
        if(verbose_list)
        {
            if (n.head_sentinel_ != NULL)
            {
                DLNode<T>* curr = n.head_sentinel_;
                cout << '\n';
                cout << "<DLList " << &n << ' '
                     << "head sentinel:" << n.head_sentinel_ << ' '
                     << "tail sentinel:" << n.tail_sentinel_ << '\n';
                while(curr != NULL)
                {
                    cout << (*curr) << '\n';
                    curr = curr->get_next();
                }
                cout << '>';
            }
        }
        else
        {
            cout << '[';
            if(n.head_sentinel_ != NULL)
            {
                DLNode<T>* curr = n.head_sentinel_;
                while(curr != n.tail_sentinel_)
                {
                    cout << curr->get_key();
                    curr = curr->get_next();
                    if(curr != NULL)
                    {
                        std::cout << ", ";
                    }
                }
                cout << curr->get_key();
            }
            cout << ']';
        }
        
        return cout;
    }

    T& operator[](T index)
    {
        if (index < 0 || head_sentinel_ == NULL)
        {
            throw IndexError();
        }
        DLNode<T>* curr = head_sentinel_;
        int count = 0;
        while(count < index)
        {
            curr = curr->get_next();
            count++;
        }
        if(curr == NULL)
        {
            throw IndexError();
        }
        return curr->get_key_ref();
    }
    int size() const
    {
        int count = 0;
        DLNode<T>* curr = head_sentinel_;
        while(curr != NULL)
        {
            curr = curr->get_next();
            count++;
        }
        return count;
    }
    
    bool is_empty() const
    {
        return head_sentinel_ == NULL;
    }

    static void debug_printing(bool b)
    {
        verbose_list = b;
    }
    
  private:
    DLNode<T>* head_sentinel_;
    DLNode<T>* tail_sentinel_;
    static bool verbose_list;
};

template < typename T >
bool DLList<T>::verbose_list = true;

#endif

#ifndef TREENODEV_H
#define TREENODEV_H

#include <iostream>
#include <vector>
#include "Data.h"

class ValueError
{};

template < typename T > class TreeNodev;

template < typename T >
bool is_root(const TreeNodev< T > * p)
{
    return (p->parent() == NULL);
}

template < typename T >
class TreeNodev
{
  public:
    TreeNodev() : parent_(NULL)
    {}
    
    TreeNodev(const T & key,
              TreeNodev * parent=NULL)
        : key_(key), parent_(parent)
    {}

    TreeNodev(const TreeNodev& other)
        : key_(other.key_), parent_(NULL)
    {
        for (size_t i = 0; i < other.child_.size(); i++)
        {
            if (other.child_[i] != NULL)
            {
                TreeNodev<T>* newChild = new TreeNodev<T>(*other.child_[i]);
                newChild->parent_ = this;
                child_.push_back(newChild);
            }
            else
            {
                child_.push_back(NULL);
            }
        }
    }

    ~TreeNodev()
    {
        for (size_t i = 0; i < child_.size(); i++)
        {
            delete child_[i];
        }
    }
    
    const TreeNodev * const parent() const
    {
        return parent_;
    }

    const T & get_key() const
    {
        return key_;
    }

    const std::vector<TreeNodev*>& get_children() const
    {
        return child_;
    }
    
    bool is_root() const
    {
        return ::is_root(this);
    }

    bool is_leaf() const
    {
        return child_.empty();
    }

    bool is_nonleaf() const
    {
        return !(child_.empty());
    }

    int height() const
    {
        if (is_leaf())
        {
            return 0;
        }

        int maxHeight = 0;

        for(size_t i = 0; i < child_.size(); ++i)
        {
            int childHeight = child_[i]->height();

            if (childHeight > maxHeight)
            {
                maxHeight = childHeight;
            }
        }

        return maxHeight + 1;
    }

    int depth() const
    {
        int d = 0;
        const TreeNodev<T>* curr = this;

        while(curr->parent() != NULL)
        {
            d++;
            curr = curr->parent();
        }

        return d;
    }

    int size() const
    {
        int total = 1;

        for (size_t i = 0; i < child_.size(); i++)
        {
            total += child_[i]->size();
        }

        return total;
    }

    // Navigation //

    TreeNodev* root()
    {
        TreeNodev* curr = this;
        while (curr->parent_ != NULL)
        {
            curr = curr->parent_;
        }
        return curr;
    }
    
    TreeNodev* next()
    {
        if(parent_ == NULL)
            return NULL;

        for(size_t i = 0; i < parent_->child_.size(); i++)
        {
            if(parent_->child_[i] == this)
            {
                if(i + 1 < parent_->child_.size())
                    return parent_->child_[i + 1];
                else
                    return NULL;
            }
        }
        
        return NULL;
    }
    
    TreeNodev* prev()
    {
        if(parent_ == NULL)
            return NULL;

        for(size_t i = 0; i < parent_->child_.size(); i++)
        {
            if(parent_->child_[i] == this)
            {
                if(i > 0)
                    return parent_->child_[i - 1];
                else
                    return NULL;
            }
        }
        
        return NULL;
    }

    // Children Access
    
    size_t num_children() const
    {
        return child_.size();
    }
    
    TreeNodev* first_child()
    {
        if (child_.empty()) return NULL;
        return child_[0];
    }
    
    TreeNodev* last_child()
    {
        if (child_.empty()) return NULL;
        return child_.back();
    }
    
    TreeNodev* child(size_t i)
    {
        if (i >= child_.size())
            return NULL;
        return child_[i];
    }
    
    // Insertion
    
    void insert(size_t i, const T& data)
    {
        if (i < child_.size() && child_[i] != NULL)
            throw ValueError();

        if (i >= child_.size())
            child_.resize(i + 1, NULL);

        TreeNodev* n = new TreeNodev(data, this);
        child_[i] = n;
    }
    
    void insert_parent(const T& data)
    {
        if(parent_ != NULL)
            throw ValueError();

        TreeNodev* n = new TreeNodev(data, NULL);
        n->child_.push_back(this);
        parent_ = n;
    }

    // Removal
    
    void remove(size_t i)
    {
        if (i >= child_.size() || child_[i] == NULL)
            return;

        delete child_[i];
        child_[i] = NULL;
    }

    // Operators //

    TreeNodev& operator=(const TreeNodev& other)
    {
        if(this == &other)
            return *this;

        for(size_t i = 0; i < child_.size(); i++)
        {
            delete child_[i];
        }

        child_.clear();
        key_ = other.key_;
        
        for (size_t i = 0; i < other.child_.size(); i++)
        {
            if(other.child_[i] != NULL)
            {
                TreeNodev<T>* newChild = new TreeNodev<T>(*other.child_[i]);
                newChild->parent_ = this;
                child_.push_back(newChild);
            }
            else
            {
                child_.push_back(NULL);
            }
        }
        
        return *this;
    }
    
    bool operator==(const TreeNodev& other) const
    {
        if(key_ != other.key_)
            return false;
        if(child_.size() != other.child_.size())
            return false;

        for (size_t i = 0; i < child_.size(); i++)
        {
            if (child_[i] == NULL && other.child_[i] == NULL)
                continue;

            if ((child_[i] == NULL) != (other.child_[i] == NULL))
                return false;

            if (*(child_[i]) != *(other.child_[i]))
                return false;
        }

        return true;
    }
    
    bool operator!=(const TreeNodev& other) const
    {
        return !(*this == other);
    }
    
  private:
    T key_;
    TreeNodev * parent_;
    std::vector< TreeNodev * > child_;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const TreeNodev< T > & t)
{
    cout << "<TreeNodev " << &t
         << " key:" << t.get_key()
         << ", parent:" << t.parent()
         << ",\n";
    cout << "child:\n";

    const std::vector<TreeNodev<T>*> & child = t.get_children();
    
    if(child.empty())
    {
        cout << ">\n";
        return cout;
    }
    else
    {
        for(int i = 0; i < child.size(); i++)
        {
            cout << child[i];
            cout << '\n';
        }
    }
    cout << '>';
    return cout;
}

#endif

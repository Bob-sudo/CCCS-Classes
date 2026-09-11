#ifndef TREENODEL_H
#define TREENODEL_H

#include <list>
#include <iostream>

template < typename T > class TreeNodel;

template < typename T >
bool is_root(const TreeNodel< T > * p)
{
    return (p->parent() == NULL);
}

template < typename T >
class TreeNodel
{
  public:
  TreeNodel() : parent_(NULL)
    {}
    
  TreeNodel(const T & key,
            TreeNodel * parent=NULL)
      : key_(key), parent_(parent)
    {}

    TreeNodel(const TreeNodel& other)
        : key_(other.key_), parent_(NULL)
    {
        for(auto it = other.child_.begin(); it != other.child_.end(); ++it)
        {
            if(*it != NULL)
            {
                TreeNodel<T>* newChild = new TreeNodel<T>(**it);
                newChild->parent_ = this;
                child_.push_back(newChild);
            }
            else
            {
                child_.push_back(NULL);
            }
        }
    }

    ~TreeNodel()
    {
        for (auto child : child_)
        {
            delete child;
        }
    }

    const TreeNodel * const parent() const
    {
        return parent_;
    }

    const T & get_key() const
    {
        return key_;
    }

    const std::list<TreeNodel*>& get_children() const
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

        for(auto it = child_.begin(); it != child_.end(); ++it)
        {
            int childHeight = (*it)->height();

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
        const TreeNodel<T>* curr = this;

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

        for (auto it = child_.begin(); it != child_.end(); ++it)
        {
            total += (*it)->size();
        }

        return total;
    }

    // Navigation

    TreeNodel* root()
    {
        TreeNodel* curr = this;
        while (curr->parent_ != NULL)
        {
            curr = curr->parent_;
        }
        return curr;
    }

    TreeNodel* next()
    {
        if(parent_ == NULL)
            return NULL;

        auto it = parent_->child_.begin();

        while(it != parent_->child_.end())
        {
            if(*it == this)
            {
                ++it;
                if(it != parent_->child_.end())
                    return *it;
                else
                    return NULL;
            }
            ++it;
        }
        
        return NULL;
    }

    TreeNodel* prev()
    {
        if(parent_ == NULL)
            return NULL;

        auto it = parent_->child_.begin();

        while(it != parent_->child_.end())
        {
            if(*it == this)
            {
                if(it == parent_->child_.begin())
                    return NULL;

                auto prevIt = it;
                --prevIt;
                return *prevIt;
            }
            ++it;
        }
        
        return NULL;
    }

    // Children Access

     size_t num_children() const
    {
        return child_.size();
    }
    
    TreeNodel* first_child()
    {
        if (child_.empty()) return NULL;
        return child_.front();
    }
    
    TreeNodel* last_child()
    {
        if (child_.empty()) return NULL;
        return child_.back();
    }
    
    TreeNodel* child(size_t i)
    {
        if (i >= child_.size())
            return NULL;

        auto it = child_.begin();
        size_t index = 0;

        while (it != child_.end())
        {
            if (index == i)
                return *it;

            ++it;
            ++index;
        }

        return NULL;
    }

    // Insertion
    
    void insert(size_t i, const T& data)
    {
        TreeNodel* newNode = new TreeNodel(data, this);
        
        auto it = child_.begin();
        size_t index = 0;

        while (it != child_.end() && index < i)
        {
            ++it;
            ++index;
        }

        if (index == child_.size())
        {
            child_.push_back(newNode);
            return;
        }

        child_.insert(it, newNode);
    }

    void insert_parent(const T& data)
    {
        TreeNodel* n = new TreeNodel(data, NULL);
        n->child_.push_back(this);
        parent_ = n;
    }

    // Removal
    
    void remove(size_t i)
    {
        if (i >= child_.size())
            return;

        auto it = child_.begin();
        int index = 0;

        while(index != i)
        {
            ++it;
            ++index;
        }

        delete *it;
        child_.erase(it);
    }

    // Operators

    TreeNodel& operator=(const TreeNodel& other)
    {
        if(this == &other)
            return *this;

        for(auto child : child_)
        {
            delete child;
        }

        child_.clear();
        key_ = other.key_;
        parent_ = NULL;
        
        for (auto child : other.child_)
        {
            if(child != NULL)
            {
                TreeNodel<T>* newChild = new TreeNodel<T>(*child);
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

    bool operator==(const TreeNodel& other) const
    {
        if(key_ != other.key_)
            return false;
        if(child_.size() != other.child_.size())
            return false;

        auto it1 = child_.begin();
        auto it2 = other.child_.begin();

        while(it1 != child_.end() && it2 != other.child_.end())
        {
            if (*it1 == NULL && *it2 == NULL)
            {
                ++it1;
                ++it2;
                continue;
            }

            if (*it1 == NULL || *it2 == NULL)
                return false;
            
            if(**it1 != **it2)
                return false;

            ++it1;
            ++it2;
        }

        return true;
    }

    bool operator!=(const TreeNodel& other) const
    {
        return !(*this == other);
    }
    
  private:
    T key_;
    TreeNodel * parent_;
    std::list< TreeNodel * > child_;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const TreeNodel< T > & t)
{
    cout << "<TreeNodel " << &t
         << " key:" << t.get_key()
         << ", parent:" << t.parent()
         << ",\n";
    cout << "child:\n";

    const std::list<TreeNodel<T>*> & child = t.get_children();
    
    if(child.empty())
    {
        cout << ">\n";
        return cout;
    }
    
    for (auto it = child.begin(); it != child.end(); ++it)
    {
       cout << *it << '\n';
    }
    
    cout << '>';
    return cout;
}

#endif

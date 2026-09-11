#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class ValueError
{};

template < typename T > class BinaryTree;

template < typename T >

class BinaryTree
{
  public:
    BinaryTree()
        : parent_(NULL), left_(NULL), right_(NULL)
    {}
    BinaryTree(const T & key, BinaryTree * parent = NULL,
               BinaryTree * left = NULL, BinaryTree * right = NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    
    BinaryTree(const BinaryTree& other)
        : key_(other.key_), parent_(NULL), left_(NULL), right_(NULL)
    {
        if (other.left_ != NULL)
        {
            left_ = new BinaryTree(*other.left_);
            left_->parent_ = this;
        }

        if (other.right_ != NULL)
        {
            right_ = new BinaryTree(*other.right_);
            right_->parent_ = this;
        }
    }
    
    ~BinaryTree()
    {
        delete left_;
        delete right_;
    }

    const T & get_key() const
    {
        return key_;
    }

    const BinaryTree * root()
    {
        BinaryTree* curr = this;
        while(curr->parent_ != NULL)
        {
            curr = curr->parent_;
        }
        return curr;
    }

    const BinaryTree * parent() const
    {
        return parent_;
    }

    const BinaryTree * left() const
    {
        return left_;
    }

    const BinaryTree * right() const
    {
        return right_;
    }

    BinaryTree* left()
    {
        return left_;
    }

    BinaryTree* right()
    {
        return right_;
    }

    int height() const
    {
        if(is_leaf())
            return 0;

        int leftHeight = -1;
        int rightHeight = -1;

        if(left_ != NULL)
            leftHeight = left_->height();

        if(right_ != NULL)
            rightHeight = right_->height();

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    int depth() const
    {
        int d = 0;
        const BinaryTree* curr = this;

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

        if(left_ != NULL)
            total += left_->size();
        if(right_ != NULL)
            total += right_->size();

        return total;
    }

    // Navigation

    BinaryTree<T>* next()
    {
        if (right_ != NULL)
            return right_->leftmost();

        BinaryTree<T>* curr = this;
        BinaryTree<T>* p = parent_;

        while (p != NULL && curr == p->right_)
        {
            curr = p;
            p = p->parent_;
        }

        return p;
    }

    BinaryTree<T>* prev()
    {
        if (left_ != NULL)
            return left_->rightmost();

        BinaryTree<T>* curr = this;
        BinaryTree<T>* p = parent_;

        while (p != NULL && curr == p->left_)
        {
            curr = p;
            p = p->parent_;
        }

        return p;
    }

    BinaryTree<T>* leftmost()
    {
        BinaryTree<T>* curr = this;

        while(curr->left_ != NULL)
        {
            curr = curr->left_;
        }

        return curr;
    }
    
    BinaryTree<T>* rightmost()
    {
        BinaryTree<T>* curr = this;

        while(curr->right_ != NULL)
        {
            curr = curr->right_;
        }

        return curr;
    }

    bool is_root() const
    {
        return parent_ == NULL;
    }

    bool is_leaf() const
    {
        return (left_ == NULL && right_ == NULL);
    }

    bool is_nonleaf() const
    {
        return !(is_leaf());
    }

    // Insert
    
    void insert_left(const T& data)
    {
        if (left_ != NULL)
        throw ValueError();

        left_ = new BinaryTree<T>(data, this, NULL, NULL);
    }
    
    void insert_right(const T& data)
    {
        if (right_ != NULL)
        throw ValueError();

        right_ = new BinaryTree<T>(data, this, NULL, NULL);
    }

    // Removal

    void remove_left()
    {
        if(left_ == NULL)
            return;

        delete left_;
        left_ = NULL;
        return;
    }
    
    void remove_right()
    {
        if(right_ == NULL)
            return;

        delete right_;
        right_ = NULL;
        return;
    }

    // Operators
    
    BinaryTree& operator=(const BinaryTree& other)
    {
        if(this == &other)
            return *this;

        delete left_;
        delete right_;

        left_ = NULL;
        right_ = NULL;

        key_ = other.key_;

        if(other.left_ != NULL)
        {
            left_ = new BinaryTree<T>(*other.left_);
            left_->parent_ = this;
        }

        if(other.right_ != NULL)
        {
            right_ = new BinaryTree<T>(*other.right_);
            right_->parent_ = this;
        }

        return *this;
    }

    bool operator==(const BinaryTree& other) const
    {
        if (key_ != other.key_)
            return false;

        // Left
        if (left_ == NULL && other.left_ != NULL)
            return false;
        if (left_ != NULL && other.left_ == NULL)
            return false;
        if (left_ != NULL && other.left_ != NULL)
            if (!(*left_ == *other.left_))
                return false;

        // Right
        if (right_ == NULL && other.right_ != NULL)
            return false;
        if (right_ != NULL && other.right_ == NULL)
            return false;
        if (right_ != NULL && other.right_ != NULL)
            if (!(*right_ == *other.right_))
                return false;

        return true;
    }

    bool operator!=(const BinaryTree& other) const
    {
        return !(*this == other);
    }
    
  private:
    T key_;
    BinaryTree * parent_;
    BinaryTree * left_;
    BinaryTree * right_;
};

template < typename T >
std::ostream & operator<<(std::ostream & cout, const BinaryTree< T > & t)
{
    cout << "<BinaryTree " << &t
         << " key:" << t.get_key()
         << ", parent:" << t.parent()
         << ",\n";
    cout << "left:" << t.left() << '\n'
         << "right:" << t.right() << '\n';
    cout << '>';
    return cout;
}

#endif

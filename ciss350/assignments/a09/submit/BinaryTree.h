#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

template < typename T >

class BinaryTree
{
  public:
    BinaryTree()
        : parent_(NULL), left_(NULL), right_(NULL)
    {}
    BinaryTree(const T & key, BinaryTree * parent,
               BinaryTree * left, BinaryTree * right)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    BinaryTree(const BinaryTree& other)
        : key_(other.key_), parent_(NULL), left_(NULL), right_(NULL)
    {
    }
    ~BinaryTree()
    {
        delete left_;
        delete right_;
    }

    T get_key() const
    {
        return key_;
    }
    
    BinaryTree* left()
    {
        return left_;
    }
    
    BinaryTree* right()
    {
        return right_;
    }
    
    BinaryTree* parent()
    {
        return parent_;
    }

    

    
  private:
    T key_;
    BinaryTree * parent_;
    BinaryTree * left_;
    BinaryTree * right_;
};

#endif

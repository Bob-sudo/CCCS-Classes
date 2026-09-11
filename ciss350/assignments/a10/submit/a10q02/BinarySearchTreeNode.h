// File: BinarySearchTreeNode.h
#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H

#include <iostream>

class BinarySearchTreeNode
{
  public:
  BinarySearchTreeNode(int key,
                       BinarySearchTreeNode * parent=NULL,
                       BinarySearchTreeNode * left=NULL,
                       BinarySearchTreeNode * right=NULL)
      : key_(key), parent_(parent), left_(left), right_(right)
    {}
    
    int key() const
    {
        return key_;
    }
    
    int & key()
    {
        return key_;
    }
    
    BinarySearchTreeNode * parent() const
    {
        return parent_;
    }
    
    BinarySearchTreeNode * & parent()
    {
        return parent_;
    }

    BinarySearchTreeNode * root()
    {
        BinarySearchTreeNode* curr = this;
        while(curr->parent_ != NULL)
        {
            curr = curr->parent_;
        }
        return curr;
    }
    
    const BinarySearchTreeNode * root() const
    {
        const BinarySearchTreeNode* curr = this;
        while(curr->parent_ != NULL)
        {
            curr = curr->parent_;
        }
        return curr;
    }
    
    BinarySearchTreeNode * left() const
    {
        return left_;
    }

    BinarySearchTreeNode * & left()
    {
        return left_;
    }
    
// Returns pointer to the leftmost node of the subtree with this
// node as root.

    BinarySearchTreeNode * leftmost()
    {
        BinarySearchTreeNode* curr = this;
        while(curr->left_ != NULL)
        {
            curr = curr->left_;
        }
        return curr;
    }
    
    const BinarySearchTreeNode * leftmost() const
    {
        const BinarySearchTreeNode* curr = this;
        while(curr->left_ != NULL)
        {
            curr = curr->left_;
        }
        return curr;
    }
    
    BinarySearchTreeNode * right() const
    {
        return right_;
    }
    
    BinarySearchTreeNode * & right()
    {
        return right_;
    }
    
// Returns pointer to the rightmost node of the subtree with this
// node as root.
    BinarySearchTreeNode * rightmost()
    {
        BinarySearchTreeNode* curr = this;
        while(curr->right_ != NULL)
        {
            curr = curr->right_;
        }
        return curr;
    }
    
    const BinarySearchTreeNode * rightmost() const
    {
        const BinarySearchTreeNode* curr = this;
        while(curr->right_ != NULL)
        {
            curr = curr->right_;
        }
        return curr;
    }
    
// Returns true if the node is a leaf node, i.e., the left
// and right are both NULL.
    bool is_leaf() const
    {
        return left_ == NULL && right_ == NULL;
    }
    
// Returns true if the node is not a leaf node
    bool is_nonleaf() const
    {
        return !is_leaf();
    }
    
// Returns true if the parent is NULL
    bool is_root() const
    {
        return parent_ == NULL;
    }

    bool operator==(const BinarySearchTreeNode & other) const
        {
            if (key_ != other.key_) return false;

            if (left_ == NULL && other.left_ != NULL) return false;
            if (left_ != NULL && other.left_ == NULL) return false;
            if (left_ != NULL && !(*left_ == *other.left_)) return false;

            if (right_ == NULL && other.right_ != NULL) return false;
            if (right_ != NULL && other.right_ == NULL) return false;
            if (right_ != NULL && !(*right_ == *other.right_)) return false;

            return true;
        }
    
  private:
    int key_;
    BinarySearchTreeNode * parent_;
    BinarySearchTreeNode * left_;
    BinarySearchTreeNode * right_;
};

std::ostream & operator<<(std::ostream &,
                          const BinarySearchTreeNode &);

void print_inorder(const BinarySearchTreeNode *);
void print_preorder(const BinarySearchTreeNode *);
void print_postorder(const BinarySearchTreeNode *);

bool insert(BinarySearchTreeNode * &, int);
bool remove(BinarySearchTreeNode * &, int);

#endif

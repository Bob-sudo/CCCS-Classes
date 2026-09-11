// File: BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include <queue>
#include <stack>
#include "BinarySearchTreeNode.h"
#include <iostream>

class ValueError{};

class BinarySearchTree
{
  public:
  BinarySearchTree()
      : root_(NULL)
    {}
    
// Put x[0], x[1], ..., x[size - 1] into the tree
    BinarySearchTree(int x[], int size)
    {
        root_ = NULL;
        for (int i = 0; i < size; i++)
            insert(x[i]);
    }
    
    BinarySearchTree(const BinarySearchTree & bst)
    {
        root_ = NULL;
        std::vector<int> v = bst.preorder();
        for (int x : v)
            insert(x);
    }
    
    ~BinarySearchTree()
    {
        clear();
    }
    
    BinarySearchTreeNode * root() const
    {
        return root_;
    }
    
    BinarySearchTree & operator=(const BinarySearchTree & bst)
    {
        if (this != &bst)
        {
            clear();
            std::vector<int> v = bst.inorder();
            for (int x : v)
                insert(x);
        }
        return *this;
    }
    
    BinarySearchTreeNode * get_root() const
    {
        return root_;
    }

    // clear 

    void clear_helper(BinarySearchTreeNode* node)
    {
        if (node == NULL) return;
        clear_helper(node->left());
        clear_helper(node->right());
        delete node;
    }
    
    void clear()
    {
        clear_helper(root_);
        root_ = NULL;
    }
    
// Returns true if the tree is empty
    bool is_empty() const
    {
        return root_ == NULL;
    }
    
// Returns the height of the tree. Note that the height of an
// empty tree is -1.
    int height(BinarySearchTreeNode* node) const
    {
        if (node == NULL) return -1;
        int left_h = height(node->left());
        int right_h = height(node->right());
        return 1 + (left_h > right_h ? left_h : right_h);
    }

    int height() const
    {
        return height(root_);
    }
    
// Returns the depth of the node pointer p parameter. This is the number
// of edges from the root to the node that p points to.
    int depth(BinarySearchTreeNode * p) const
    {
        int d = 0;

        while (p != NULL && p->parent() != NULL)
        {
            p = p->parent();
            d++;
        }

        return d;
    }
    
// Returns the number of nodes in this tree.
    int size(BinarySearchTreeNode* node) const
    {
        if (node == NULL) return 0;
        return 1 + size(node->left()) + size(node->right());
    }

    int size() const
    {
        return size(root_);
    }
    
// Returns a pointer to the node containing x. If x is not in the tree,
// NULL is returned.
    BinarySearchTreeNode * find(int x)
    {
        BinarySearchTreeNode* curr = root_;

        while(curr != NULL)
        {
            if(x < curr->key())
                curr = curr->left();
            else if(x > curr->key())
                curr = curr->right();
            else
                return curr;
        }
        
        return NULL;
    }
    
// Returns the minimum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int min() const
    {
        if (root_ == NULL) throw ValueError();
        return root_->leftmost()->key();
    }
    
// Returns the maximum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int max() const
    {
        if (root_ == NULL) throw ValueError();
        return root_->rightmost()->key();
    }
    
// Returns true if *this and t are the same trees, i.e., the
// values and structure of *this and t are the same.
    bool operator==(const BinarySearchTree & t) const
        {
            if (root_ == NULL && t.root_ == NULL) return true;
            if (root_ == NULL || t.root_ == NULL) return false;

            return (*root_ == *t.root_);
        }
    
// Inserts x into the tree. If x is already in the tree, a ValueError
// exception object is thrown.
    void insert(int x)
    {
        bool success = ::insert(root_, x);
        if (!success) throw ValueError();
    }
    
// Remove x from the tree. If x is not in the tree, a ValueError
// exception object is thrown.
    void remove(int x)
    {
        bool success = ::remove(root_, x);
        if (!success) throw ValueError();
    }
    
// Returns a vector of integers built by traversing the tree
// using inorder traversal
    void inorder(BinarySearchTreeNode* node, std::vector<int>& v) const
    {
        if (node == NULL) return;
        inorder(node->left(), v);
        v.push_back(node->key());
        inorder(node->right(), v);
    }
    
    std::vector< int > inorder() const
    {
        std::vector< int > ret;
        inorder(root_, ret);
        return ret;
    }
    
// Returns a vector of integers built by traversing the tree
// using preorder traversal
    void preorder(BinarySearchTreeNode* node, std::vector<int>& v) const
    {
        if (node == NULL) return;
        v.push_back(node->key());
        preorder(node->left(), v);
        preorder(node->right(), v);
    }
    
    std::vector< int > preorder() const
    {
        std::vector< int > ret;
        preorder(root_, ret);
        return ret;
    }
    
// Returns a vector of integers built by traversing the tree
// using postorder traversal
    void postorder(BinarySearchTreeNode* node, std::vector<int>& v) const
    {
        if (node == NULL) return;
        postorder(node->left(), v);
        postorder(node->right(), v);
        v.push_back(node->key());
    }
    
    std::vector< int > postorder() const
    {
        std::vector< int > ret;
        postorder(root_, ret);
        return ret;
    }
    
// Returns a vector of integers built by traversing the tree
// using breadth first traversal
    std::vector< int > breadthfirst() const
    {
        std::vector< int > ret;

        if(root_ == NULL) return ret;
        
        std::queue<BinarySearchTreeNode*> q;
        q.push(root_);

        while(!q.empty())
        {
            BinarySearchTreeNode* curr = q.front();
            q.pop();

            ret.push_back(curr->key());

            if (curr->left() != NULL)
                q.push(curr->left());

            if (curr->right() != NULL)
                q.push(curr->right());
        }
        return ret;
    }
    
// Return pointer to k-th ordered node
// [HINT: Use a traversal]
    BinarySearchTreeNode * select(int k)
    {
        std::vector<int> v = inorder();

        if (k < 0 || k >= v.size())
            return NULL;

        return find(v[k]);
    }
    
// Return vector of integers in tree with key values >= m and < M.
    std::vector< int > range(BinarySearchTreeNode* node, int m, int M)
    {
        std::vector< int > ret;
        std::stack<BinarySearchTreeNode*> stk;
        BinarySearchTreeNode* curr = node;

        while(curr != NULL || !stk.empty())
        {
            while(curr != NULL)
            {
                stk.push(curr);
                curr = curr->left();
            }

            curr = stk.top();
            stk.pop();

            int k = curr->key();

            if(k >= m && k < M)
                ret.push_back(k);

            if (k >= M)
                break;

            curr = curr->right();
        }
        
        return ret;
    }
    
  private:
    BinarySearchTreeNode * root_;
};

void print_inorder(const BinarySearchTree & bst);

void print_preorder(const BinarySearchTree & bst);

void print_postorder(const BinarySearchTree & bst);

#endif

#ifndef AVL_H
#define AVL_H

#include "BinarySearchTreeNode.h"
#include <vector>
#include <stack>
#include <queue>

class ValueError{};

int height(BinarySearchTreeNode* node);
BinarySearchTreeNode * avl_insert(BinarySearchTreeNode* node, int x);
BinarySearchTreeNode * avl_remove(BinarySearchTreeNode* node, int x);

class AVL
{
  public:
    AVL()
        : root_(NULL)
    {}
    
    AVL(int x[], int size)
    {
        root_ = NULL;
        for(int i = 0; i < size; i++)
            insert(x[i]);
    }
    
    AVL(const AVL & other)
    {
        root_ = NULL;
        std::vector<int> v = other.preorder();
        for(int x : v)
            insert(x);
    }
    
    ~AVL()
    {
        clear();
    }
    
    BinarySearchTreeNode * root() const
    {
        return root_;
    }

    // Clear

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

    bool is_empty() const
    {
        return root_ == NULL;
    }

    int height() const
    {
        return ::height(root_);
    }

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

    int size(BinarySearchTreeNode* node) const
    {
        if (node == NULL) return 0;
        return 1 + size(node->left()) + size(node->right());
    }

    int size() const
    {
        return size(root_);
    }

    BinarySearchTreeNode * find(int x) const
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

    // Min / Max
    int min() const
    {
        if (root_ == NULL) throw ValueError();
        return root_->leftmost()->key();
    }

    int max() const
    {
        if (root_ == NULL) throw ValueError();
        return root_->rightmost()->key();
    }

    // Operators

    AVL & operator=(const AVL & other)
    {
        if (this != &other)
        {
            clear();
            std::vector<int> v = other.inorder();
            for (int x : v)
                insert(x);
        }
        return *this;
    }

    bool operator==(const AVL & t) const
        {
            if (root_ == NULL && t.root_ == NULL) return true;
            if (root_ == NULL || t.root_ == NULL) return false;

            return (*root_ == *t.root_);
        }

    // insert remove
    
    void insert(int x)
    {
        root_ = ::avl_insert(root_, x);
    }

    
    void remove(int x)
    {
        root_ = ::avl_remove(root_, x);
    }
    
    // Inorder / Preorder / Postorder

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

    BinarySearchTreeNode * select(int k)
    {
        std::vector<int> v = inorder();

        if (k < 0 || k >= v.size())
            return NULL;

        return find(v[k]);
    }

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


BinarySearchTreeNode* rotate_left(BinarySearchTreeNode* x);
BinarySearchTreeNode* rotate_right(BinarySearchTreeNode* y);

int balance_factor(BinarySearchTreeNode* node);
BinarySearchTreeNode* balance(BinarySearchTreeNode* node);

void print_inorder(const AVL & t);

void print_preorder(const AVL & t);

void print_postorder(const AVL & t);

#endif

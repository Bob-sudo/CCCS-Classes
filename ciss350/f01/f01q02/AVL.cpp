#include "AVL.h"

BinarySearchTreeNode* rotate_left(BinarySearchTreeNode* x)
{
    BinarySearchTreeNode* y = x->right();
    BinarySearchTreeNode* T2 = y->left();

    y->left() = x;
    x->right() = T2;

    if (T2 != NULL) T2->parent() = x;

    y->parent() = x->parent();
    x->parent() = y;

    return y;
}

BinarySearchTreeNode* rotate_right(BinarySearchTreeNode* y)
{
    BinarySearchTreeNode* x = y->left();
    BinarySearchTreeNode* T2 = x->right();

    x->right() = y;
    y->left() = T2;

    if (T2 != NULL) T2->parent() = y;

    x->parent() = y->parent();
    y->parent() = x;

    return x;
}

int balance_factor(BinarySearchTreeNode* node)
{
    if (node == NULL) return 0;
    return height(node->left()) - height(node->right());
}

BinarySearchTreeNode* balance(BinarySearchTreeNode* node)
{
    int bf = balance_factor(node);
    
    // Left balance
    if(bf > 1)
    {
        if(balance_factor(node->left()) < 0)
            node->left() = rotate_left(node->left());

        return rotate_right(node);
    }
    
    // Right balance
    if(bf < -1)
    {
        if(balance_factor(node->right()) > 0)
            node->right() = rotate_right(node->right());

        return rotate_left(node);
    }

    return node;
}

BinarySearchTreeNode * avl_insert(BinarySearchTreeNode* node, int x)
{
    if(node == NULL)
        return new BinarySearchTreeNode(x);

    if(x < node->key())
    {
        node->left() = avl_insert(node->left(), x);
        node->left()->parent() = node;
    }
    else if(x > node->key())
    {
        node->right() = avl_insert(node->right(), x);
        node->right()->parent() = node;
    }
    else
    {
        throw ValueError();
    }

    return balance(node);
}

BinarySearchTreeNode * avl_remove(BinarySearchTreeNode* node, int x)
{
    if(node == NULL)
        return NULL;
    
    if(x < node->key())
    {
        node->left() = avl_remove(node->left(), x);
        if (node->left())
            node->left()->parent() = node;
    }
    
    else if(x > node->key())
    {
        node->right() = avl_remove(node->right(), x);
        if (node->right())
            node->right()->parent() = node;
    }

    else
    {
        if(node->is_leaf())
        {
            delete node;
            return NULL;
        }
        
        else if (node->left() == NULL)
        {
            BinarySearchTreeNode* temp = node->right();
            if (temp) temp->parent() = node->parent();
            delete node;
            return temp;
        }
        
        else if (node->right() == NULL)
        {
            BinarySearchTreeNode* temp = node->left();
            if (temp) temp->parent() = node->parent();
            delete node;
            return temp;
        }

        else
        {
            BinarySearchTreeNode* temp = node->right()->leftmost();
            node->key() = temp->key();
            
            node->right() = avl_remove(node->right(), temp->key());
            if (node->right())
                node->right()->parent() = node;
        }
    }

    return balance(node);
}

int height(BinarySearchTreeNode* node)
{
    if (node == NULL) return -1;
    int left_h = height(node->left());
    int right_h = height(node->right());
    return 1 + (left_h > right_h ? left_h : right_h);
}

void print_inorder(const AVL & t)
{
    print_inorder(t.root());
}

void print_preorder(const AVL & t)
{
    print_preorder(t.root());
}

void print_postorder(const AVL & t)
{
    print_postorder(t.root());
}



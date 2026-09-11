// File: BinarySearchTreeNode.cpp

#include "BinarySearchTreeNode.h"

std::ostream & operator<<(std::ostream & cout,
                          const BinarySearchTreeNode & node)
{
    cout << "<Node: " << &node
         << ", key:" << node.key()
         << ", parent:" << node.parent()
         << ", left:" << node.left()
         << ", right:" << node.right() << '>';
    return cout;
}

void print_inorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    print_inorder(node->left());
    std::cout << (*node) << '\n';
    print_inorder(node->right());
}

void print_preorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    std::cout << (*node) << '\n';
    print_preorder(node->left());
    print_preorder(node->right());
}
void print_postorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    print_postorder(node->left());
    print_postorder(node->right());
    std::cout << (*node) << '\n';
}

bool insert(BinarySearchTreeNode * & node, int x)
{
    if (node == NULL)
    {
        node = new BinarySearchTreeNode(x);
        return true;
    }

    if(x < node->key())
    {
        if(node->left() == NULL)
        {
            node->left() = new BinarySearchTreeNode(x, node);
            return true;
        }
        else
        {
            return insert(node->left(), x);
        }
    }
    else if (x > node->key())
    {
        if(node->right() == NULL)
        {
            node->right() = new BinarySearchTreeNode(x, node);
            return true;
        }
        else
        {
            return insert(node->right(), x);
        }
    }
    
    return false;
}

bool remove(BinarySearchTreeNode * & node, int x)
{
    if(node == NULL)
        return false;

    if(x < node->key())
        return remove(node->left(), x);
    if(x > node->key())
        return remove(node->right(), x);

    else
    {
        if(node->is_leaf())
        {
            delete node;
            node = NULL;
        }
        
        else if (node->left() == NULL)
        {
            BinarySearchTreeNode* temp = node;
            node = node->right();
            if (node != NULL) node->parent() = temp->parent();
            delete temp;
        }
        
        else if (node->right() == NULL)
        {
            BinarySearchTreeNode* temp = node;
            node = node->left();
            if (node != NULL) node->parent() = temp->parent();
            delete temp;
        }

        else
        {
            BinarySearchTreeNode* temp = node->right()->leftmost();
            node->key() = temp->key();
            return remove(node->right(), temp->key());
        }
        return true;
    }
}

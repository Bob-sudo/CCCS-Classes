#include <iostream>

/*
  
                   11

          3                  20

      7      9           1

                12
 */

class Node
{
public:
    Node(int key, Node * parent=NULL, Node * left=NULL, Node * right=NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    Node * parent_;
    Node * left_;
    Node * right_;
};

std::ostream & operator<<(std::ostream & cout, const Node & node)
{
    cout << "<Node " << &node << ' '
         << "key:" << node.key_ << ", "
         << "parent:" << node.parent_ << ", "
         << "left:" << node.left_ << ", "
         << "right:" << node.right_ << '>';
    return cout;
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int height(Node * proot)
{
    if(proot == NULL)
    {
        return -1;  
    }
    else
    {
        int left_height = height(proot->left_);
        int right_height = height(proot->right_);
        return max(left_height, right_height) + 1;
    }
}

int max(Node * proot)
{
    if (proot == NULL)
    {
        std::cout << "max ... base case\n";
        return -1;
    }
    else
    {
        std::cout << "max ... recursive case ... " << proot->key_ << '\n';
        int left_max = max(proot ->left_);
        std::cout << "max ... recursive case ... " << proot->key_
                  << " ... left max: " << left_max << '\n';
        int right_max = max(proot->right_);
        std::cout << "max ... recursive case ... " << proot->key_
                  << " ... right max: " << right_max << '\n';
        std::cout << "max ... recursive case ... " << proot->key_
                  << " ... return: " << max(proot->key_, left_max, right_max)
                  << '\n';
        return max(proot->key_, left_max, right_max);
    }
}

Node* find(Node * proot, int target)
{
    if(proot == NULL)
    {
        return NULL;
    }
    else
    {
        if (proot->key_ == target)
        {
            return proot;
        }
        else
        {
            Node * left = find(proot->left_, target);
            if (left != NULL)
            {
                return left;
            }
            else
            {
                return find(proot->right_, target);
            }
        }
    }
}

void copy(Node * p0, Node * p1)
{
    if(p0 == NULL)
    {
        return;
    }
    
    *p1 = new Node(p0->key_);
    copy(p0->left_, (*p1)->left_);
    copy(p0->right_, (*p1)->right_);
}


void preorder_print(Node * proot)
{
    if(proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        std::cout << proot->key_ << ' ';
        preorder_print(proot->left_);
        preorder_print(proot->right_);
    }
}

void inorder_print(Node * proot)
{
    if(proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        inorder_print(proot->left_);
        std::cout << proot->key_ << ' ';
        inorder_print(proot->right_);
    }
}

void postorder_print(Node * proot)
{
    if(proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        postorder_print(proot->left_);
        postorder_print(proot->right_);
        std::cout << proot->key_ << ' ';
    }
}

int main()
{
    Node * n11 = new Node(11);
    Node * n3 = new Node(3); n3->parent_ = n11; n11->left_ = n3;
    Node * n20 = new Node(20); n20->parent_ = n11; n11->right_ = n20;
    Node * n7 = new Node(7); n7->parent_ = n3; n3->left_ = n7;
    Node * n9 = new Node(9); n9->parent_ = n3; n3->right_ = n9;
    Node * n1 = new Node(1); n1->parent_ = n20; n20->left_ = n1;
    Node * n12 = new Node(12); n12->parent_ = n9; n9->right_ = n12;
    
    std::cout << (*n11) << '\n';
    std::cout << (*n3) << '\n';
    std::cout << (*n20) << '\n';
    std::cout << (*n7) << '\n';
    std::cout << (*n9) << '\n';
    std::cout << (*n1) << '\n';
    std::cout << (*n12) << '\n';

    Node * proot = n11;

    preorder_print(proot); std::cout << '\n';
    inorder_print(proot); std::cout << '\n';
    postorder_print(proot); std::cout << '\n';

    std::cout << height(proot) << '\n';

    std::cout << max(n3) << '\n';

    Node * temp = new Node(16);
    copy(n3, temp);
    std::cout << temp << '\n';
    
    return 0;
}

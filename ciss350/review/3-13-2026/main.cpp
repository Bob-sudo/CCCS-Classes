#include <iostream>
#include <stack>
#include <queue>

/*
                      10

                20           8

            4      30     2      12

                 6   3   1   5       7
 */


class Node
{
public:
    Node(int key, Node * parent = NULL, Node * left = NULL, Node * right = NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    Node * left_;
    Node * right_;
    Node * parent_;
};

std::ostream & operator<<(std::ostream & cout, const Node & n)
{
    cout << "<Node " << &n << ' '
         << "key:" << n.key_ << ' '
         << "parent:" << n.parent_ << ", "
         << "left:" << n.left_ << ", "
         << "right:" << n.right_ << '>';
    return cout;
}

void preorder_DFT_print(Node * p)
{
    if (p == NULL)
    {
        // case: EMPTY tree case
        std::cout << ' ';
    }
    else
    {
        // case: NON EMPTY tree case
        std::cout << p->key_ << ' ';
        preorder_DFT_print(p->left_);
        preorder_DFT_print(p->right_);
    }
}

void inorder_DFT_print(Node * p)
{
    if (p == NULL)
    {
        // case: EMPTY tree case
        std::cout << ' ';
    }
    else
    {
        // case: NON EMPTY tree case
        
        inorder_DFT_print(p->left_);
        std::cout << p->key_ << ' ';
        inorder_DFT_print(p->right_);
    }
}

void postorder_DFT_print(Node * p)
{
    if (p == NULL)
    {
        // case: EMPTY tree case
        std::cout << ' ';
    }
    else
    {
        // case: NON EMPTY tree case
        
        postorder_DFT_print(p->left_);
        postorder_DFT_print(p->right_);
        std::cout << p->key_ << ' ';
    }
}

void BFT_print(Node * p)
{
    std::queue< Node * > queue;
    queue.push(p);
    while(!queue.empty())
    {
        Node * p = queue.front();
        queue.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            std::cout << p->key_ << ' ';
            queue.push(p->left_);
            queue.push(p->right_);
        }
    }
}

void preorder_DFT_print_with_stack(Node * p)
{
    std::stack< Node * > stk;
    stk.push(p);
    while(!stk.empty())
    {
        Node * p = stk.top();
        stk.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            std::cout << p->key_ << ' ';
            stk.push(p->left_);
            stk.push(p->right_);
        }
        
    }
}

void inorder_DFT_print_with_stack(Node * p)
{
    std::stack< Node * > stk;
    stk.push(p);
    while(!stk.empty())
    {
        Node * p = stk.top();
        stk.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            stk.push(p->left_);
            std::cout << p->key_ << ' ';
            stk.push(p->right_);
        }
        
    }
}

void postorder_DFT_print_with_stack(Node * p)
{
    std::stack< Node * > stk;
    stk.push(p);
    while(!stk.empty())
    {
        Node * p = stk.top();
        stk.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            stk.push(p->left_);
            stk.push(p->right_);
            std::cout << p->key_ << ' ';
        }
        
    }
}

int max(int x, int y)
{
    return (x >= y ? x : y);
}

int height(Node * p)
{
    if (p == NULL)
    {
        // CASE: tree is empty
        std::cout << "height ... base case\n";
        return -1;
    }
    else
    {
        // CASE: tree is not empty
        std::cout << "height ... recursive case ... key:" << p->key_ << '\n';
        int left_height = height(p->left_);
        std::cout << "height ... recursive case ... key:" << p->key_ << " left_height:" << left_height << '\n';
        int right_height = height(p->right_);
        std::cout << "height ... recursive case ... key:" << p->key_ << " right_height:" << right_height << '\n';
        int ret = max(left_height, right_height) + 1;
        std::cout << "height ... recursive case ... key:" << p->key_ << " returning:" << ret << '\n';
        return ret;
    }
}

int main()
{
    Node * p10 = new Node(10);
    Node * p20 = new Node(20, p10);
    p10->left_ = p20;
    Node * p8 = new Node(8, p10);
    p10->right_ = p8;

    Node * p4 = new Node(4, p20);
    p20->left_ = p4;
    Node * p30 = new Node(30, p20);
    p20->right_ = p30;

    Node * p2 = new Node(2, p8);
    p8->left_ = p2;
    Node * p12 = new Node(12, p8);
    p8->right_ = p12;

    Node * p6 = new Node(6, p30);
    p30->left_ = p6;
    Node * p3 = new Node(3, p30);
    p30->right_ = p3;

    Node * p1 = new Node(1, p2);
    p2->left_ = p1;
    Node * p5 = new Node(5, p2);
    p2->right_ = p5;

    Node * p7 = new Node(7, p12);
    p12->right_ = p7;
    

    /*
    std::cout << *p10 << '\n';
    std::cout << *p20 << '\n';
    std::cout << *p8 << '\n';
    std::cout << *p4 << '\n';
    std::cout << *p30 << '\n';
    std::cout << *p2 << '\n';
    std::cout << *p12 << '\n';
    std::cout << *p6 << '\n';
    std::cout << *p3 << '\n';
    std::cout << *p1 << '\n';
    std::cout << *p5 << '\n';
    std::cout << *p7 << '\n';

    
      traversals
      -- depth first traversals (DFT)
         -- preorder DFT
         -- inorder DFT
         -- postorder DFT
      -- breadth first traversals (BFT)
      
     

    preorder_DFT_print(p10);
    std::cout << '\n';
    inorder_DFT_print(p10);
    std::cout << '\n';
    postorder_DFT_print(p10);
    std::cout << '\n';

    // ** STACKS ** \\

    std::stack< int > stk;
    std::cout << stk.size() << '\n';
    stk.push(3);
    std::cout << stk.top() << '\n';
    stk.push(42);
    std::cout << stk.top() << '\n';
    std::cout << stk.size() << '\n';
    stk.pop();
    std::cout << stk.top() << ' ' << stk.size() << ' ' << stk.empty() << '\n';
    stk.pop();
    std::cout << stk.size() << ' ' << stk.empty() << '\n';

    // ** QUEUES ** \\
    
    std::queue< int > queue;
    std::cout << queue.size() << ' ' << queue.empty() << '\n';
    queue.push(42);
    std::cout << queue.front() << ' ' << queue.back() << ' ' << queue.size()
              << '\n';
    queue.push(3);
    std::cout << queue.front() << ' ' << queue.back() << ' ' << queue.size()
              << '\n';
    queue.pop();
    std::cout << queue.front() << ' ' << queue.back() << ' ' << queue.size()
              << '\n';

    BFT_print(p10);
    */


    int h = height(p10);
    std::cout << "final: " << h << '\n';
    
    return 0;
}

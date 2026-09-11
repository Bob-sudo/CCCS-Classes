#include <iostream>

class DLNode
{
public:
    DLNode(int key, DLNode * prev = NULL, DLNode * next = NULL)
        : key_(key), prev_(prev), next_(next)
    {}
    int key_;
    DLNode * prev_;
    DLNode * next_;
};

class DLList
{
public:
    DLList()
        :
    {}
};

std::ostream & operator<<(std::ostream & cout, const DLNode & n)
{
    cout << "<DLNode: " << &n << ", "
         << "key:" << n.key_ << ", "
         << "prev:" << n.prev_ << ", "
         << "next:" << n.next_
         << '>';
    return cout;
}

int main()
{
    DLNode * p5 = new DLNode(5);
    std::cout << (*p5) << '\n';
    return 0;
}

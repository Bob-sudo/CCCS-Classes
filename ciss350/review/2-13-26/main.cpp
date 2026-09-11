#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next = NULL)
        : key_(key), next_(next)
    {}
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n
         << " key:" << n.key_ << ','
         << " next:" << n.next_ << '>';
    return cout;
}

class UnderflowError
{};

class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}

    int head() const
    {
        if (phead_ == NULL)
        {
            // ... throw an exception
            throw UnderflowError();
        }
        else
            return phead_->.key_;
    }
    
    void insert_head(int key)
    {
        phead_ = new SLNode(key, phead_);
    }

    void delete_head()
    {
        if(phead_ == NULL)
        {
            // keep quiet ... throw an exception
            throw UnderflowError();
        }
        else
        {
            SLNode * p = phead_;
            phead_ = phead_->next_;
            delete p;
        }
    }
    SLNode * phead_;
};

std::ostream & operator<<(std::ostream & cout, const SLList & list)
{
    cout << "<SLList " << &list << '\n';
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        std::cout << "    " << (*p) << '\n';
        p = p->next_;
    }
    cout << '>';
    return cout;
}

int main()
{
    // 5 -> 3 -> 1 -> 0
    // int x[] = {5, 3, 1, 0}
    SLNode * n5 = new SLNode(5);
    SLNode * n3 = new SLNode(3); n5->next_ = n3;
    SLNode * n1 = new SLNode(1); n3->next_ = n1;
    SLNode * n0 = new SLNode(0); n1->next_ = n0;
    std::cout << *n5 << '\n';
    std::cout << *n3 << '\n';
    std::cout << *n1 << '\n';
    std::cout << *n0 << '\n';

    SLNode * phead = n5;
    // print everything that phead points to
    while(phead != NULL)
    {
        std::cout << (*phead) << '\n';
        phead = phead->next_;
    }

    SLList list;
    std::cout << list << '\n';
    list.insert_head(42);
    std::cout << list << '\n';
    list.insert_head(1);
    std::cout << list << '\n';
    list.insert_head(3);
    std::cout << list << '\n';
    list.insert_head(5);
    std::cout << list << '\n';

    list.delete_head();
    std::cout << list << '\n';
    
    return 0;
}

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
    cout << "<SLNode " << &n << ' '
         << "key:" << n.key_ << ", "
         << "next: " << n.next_ << '>';
    return cout;
}

class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}

    void insert_head(int v);
    void delete_head();
    int head() const;

    SLNode* phead_;
};

std::ostream & operator<<(std::ostream & cout, const SLList & list)
{
    SLNode * p = list.phead_;

    cout << "<SLList " << &list << '\n';
    while (p != NULL)
    {
        cout << "    " << (*p) <<'\n';
        p = p->next_;
    }
    cout << '>';
        
    return cout;
}

void SLList::insert_head(int v)
{
    phead_ = new SLNode(v, phead_);
}

void SLList::delete_head()
{
    if(phead_ != NULL)
    {
        SLNode * p = phead_;
        phead_ = phead_->next_;
        delete p;
    }
}

/*
void print_list(SLNode * phead)
{
    while (phead != NULL)
    {
        std::cout << (*phead) << '\n';
        phead = phead -> next_;
    }
}
*/

int main()
{
    SLNode * n5 = new SLNode(5);
    SLNode * n3 = new SLNode(3); n5->next_ = n3;
    SLNode * n0 = new SLNode(0); n3->next_ = n0;
    SLNode * n1 = new SLNode(1); n0->next_ = n1;
    SLNode * phead = n5;
    
    std::cout << (*n5) << '\n';
    std::cout << (*n3) << '\n';
    std::cout << (*n0) << '\n';
    std::cout << (*n1) << '\n';

    delete n1;
    delete n0;
    delete n3;
    delete n5;

    
    SLList list;

    std::cout << list << '\n';
    
    list.insert_head(1);
    list.insert_head(0);
    list.insert_head(3);
    list.insert_head(5);
    
    list.delete_head();
    //list.head();
    
    return 0;
}

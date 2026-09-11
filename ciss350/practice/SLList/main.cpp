#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next)
        : key_(key), next_(next)
    {}
    
    int key() const
    {
        return key_;
    }
    
    SLNode * next() const
    {
        return next_;
    }

    void set_next(SLNode * n)
    {
        next_ = n;
    }
    
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, SLNode & node)
{
    cout << "<SLNode " << &node
         << ", key:" << node.key()
         << ", next:" << node.next()
         << '>';
    return cout;
}

void print(SLNode * p)
{
    /* while-loop print
    while (p != NULL)
    {
        std::cout << (*p) << std::endl;
        p = p->next();
    }
    */

    // Recursive print
    if (p != NULL)
    {
        std::cout << (*p) << '\n';
        print(p->next());
    }
}

void insert_head(SLNode ** phead, int i)
{
    if(*phead == NULL)
    {
        *phead = new SLNode(i, NULL);
    }
    else
    {
        *phead = new SLNode(i, *phead);
    }
}

/*
void insert_head(SLNode *& phead, int i)
{
    phead = new SLNode(i, phead);
}
*/

void insert_tail(SLNode ** phead, int i)
{
    if(*phead == NULL)
    {
        *phead = new SLNode(i, NULL);
        return;
    }
    
    if ((*phead)->next() == NULL)
    {
        SLNode * q = new SLNode(i, NULL);
        (*phead)->set_next(q);
    }
    else
    {
        insert_tail(&((*phead)->next_), i);
    }
}

void delete_head(SLNode ** phead)
{
    if(*phead == NULL)
        return;
    
    SLNode * temp = *phead;
    *phead = (*phead)->next();
    delete temp;
}

void delete_head(SLNode *& phead)
{
    if(phead == NULL)
        return;

    SLNode * temp = phead;
    phead = phead->next();
    delete temp;
}

void delete_tail(SLNode ** phead)
{
    if (*phead == NULL)
        return;

    if ((*phead)->next() == NULL)
    {
        SLNode * temp = new SLNode(i, NULL);
        (*phead)->set_next(q);
    }
    else
    {
        insert_tail(&((*phead)->next_), i);
    }
}

int main()
{
    SLNode n2(2, NULL);
    SLNode n6(6, NULL);
    SLNode n4(4, NULL);
    SLNode n5(5, NULL);

    n2.set_next(&n6);
    n6.set_next(&n4);
    n4.set_next(&n5);

    SLNode * phead = &n2;

    print(phead);

    std::cout << '\n' << "INSERT HEAD: " << '\n';

    phead = NULL;
    insert_head(&phead, 5);
    insert_head(&phead, 4);
    insert_head(&phead, 6);
    insert_head(&phead, 2);
    print(phead);

    std::cout << '\n' << "INSERT TAIL: " << '\n';

    insert_tail(&phead, 3);
    print(phead);

    std::cout << '\n' << "DELETE HEAD: " << '\n';
    delete_head(&phead);
    print(phead);

    std::cout << '\n' << "ALTERNATE DELETE HEAD: " << '\n';
    delete_head(phead);
    print(phead);
    
    return 0;
}

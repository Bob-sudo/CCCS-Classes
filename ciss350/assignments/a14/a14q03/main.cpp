#include "maxheap_value.h"
#include "maxpriorityqueue.h"

int main()
{
    MaxPriorityQueue<maxheap_value> q;

    q.insert(maxheap_value(5, "a"));
    q.insert(maxheap_value(7, "b"));
    q.insert(maxheap_value(9, "c"));

    std::cout << q << '\n';

    std::cout << "Max: " << q.max() << '\n';

    std::cout << "Removed: " << q.remove() << '\n';

    std::cout << "New Max: " << q.max() << '\n';

    std::cout << "Size: " << q.size() << '\n';

    std::cout << "Clearing queue:" << '\n';
    q.clear();

    std::cout << "Empty? " << q.is_empty() << '\n';

    q.insert(maxheap_value(1, "a"));
    q.insert(maxheap_value(2, "b"));
    q.insert(maxheap_value(3, "c"));
    q.insert(maxheap_value(4, "d"));
    q.insert(maxheap_value(5, "e"));
    q.insert(maxheap_value(6, "f"));
    q.insert(maxheap_value(7, "g"));
    q.insert(maxheap_value(8, "h"));

    MaxPriorityQueue<maxheap_value> q2(q);

    std::cout << "Copy Constructor: " << q2 << '\n';

    MaxPriorityQueue<maxheap_value> q3 = q;

    std::cout << "= Operator: " << q3 << '\n';
    
    return 0;
}

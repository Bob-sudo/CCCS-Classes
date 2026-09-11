#include "Queue.h"

int main()
{
    Queue< int > queue;
    queue.enqueue(5); // 5 is at the front
    queue.enqueue(6); // 5 is at the front and 6 is at the back
    std::cout << queue << '\n';
    
    Queue< int >::debug_printing(false);

    int x = queue.front(); // x = 5
    queue.front() = 4; // front of queue is now 4
    std::cout << x << '\n';
    std::cout << queue << '\n';
    
    int y = queue.back(); // y = 6
    queue.dequeue(); // queue has 1 value
    std::cout << y << '\n';
    std::cout << queue << '\n';
    
    int size = queue.size(); // size is 1
    queue.clear(); // queue is now empty
    std::cout << size << '\n';
    std::cout << queue << '\n';
    
    bool b = queue.is_empty(); // b is true <-- CORRECTION
    std::cout << b << '\n';
    
    queue.enqueue(1);
    queue.enqueue(1);
    queue.enqueue(1);
    std::cout << queue << '\n';
    queue.clear(); // queue is now empty
    std::cout << queue << '\n';
    
    return 0;
}

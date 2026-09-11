// File: test.cpp
// Name: Ethan Graham

#include <iostream>
#include "Queue.h"

int main()
{
    Queue< int > queue;
    queue.enqueue(5); // 5 is at the front
    queue.enqueue(6); // 5 is at the front and 6 is at the back

    DLList< int >::debug_printing(false);
    DLNode< int >::debug_printing(true);

    std::cout << queue;

    int x = queue.front();
    std::cout << "FRONT: " << x << '\n';
    
    queue.front() = 4;
    std::cout << queue;
    
    int y = queue.back();
    std::cout << "BACK: " << y << '\n';

    queue.dequeue();
    std::cout << "DEQUEUE: " << queue;

    int size = queue.size();
    std::cout << "SIZE: " << size << '\n';

    queue.clear();
    std::cout << "CLEAR: " << queue;

    bool b = queue.is_empty();
    std::cout << "IS EMPTY: " << b << '\n';

    queue.enqueue(1);
    queue.enqueue(1);
    queue.enqueue(1);
    
    size = queue.size();
    b = queue.is_empty();
    std::cout << queue;
    std::cout << "SIZE: " << size << '\n';
    std::cout << "IS EMPTY: " << b << '\n';

    queue.clear();
    std::cout << "CLEAR: " << queue;
    
    return 0;
}

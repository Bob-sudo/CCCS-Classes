// File: test.cpp
// Name: Ethan Graham

#include <iostream>
#include "Deque.h"

int main()
{
    Deque< int > deque;
    DLList< int >::debug_printing(false);
    DLNode< int >::debug_printing(true);
    
    deque.push_front(5);
    deque.push_back(6);
    std::cout << deque;

    int x = deque.front();
    std::cout << "FRONT: " << x << '\n';

    int y = deque.back();
    std::cout << "BACK: " << y << '\n';

    deque.back() = 7;
    std::cout << "NEW BACK: " << deque.back() << '\n';
    std::cout << deque;

    deque.pop_front();
    std::cout << "POP FRONT: " << deque;
    deque.pop_back();
    std::cout << "POP BACK: " << deque;

    int size = deque.size();
    std::cout << "SIZE: " << size << '\n';

    bool b = deque.is_empty();
    std::cout << "IS EMPTY: " << b << '\n';

    deque.push_front(1);
    deque.push_front(1);
    deque.push_front(1);

    size = deque.size();
    b = deque.is_empty();
    
    std::cout << deque;
    std::cout << "SIZE: " << size << '\n';
    std::cout << "IS EMPTY: " << b << '\n';

    deque.clear();
    std::cout<< "CLEAR: " << deque;
    return 0;
}

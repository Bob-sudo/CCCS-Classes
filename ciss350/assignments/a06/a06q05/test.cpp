#include "Deque.h"

int main()
{
    Deque< int > deque;
    deque.push_front(5);
    deque.push_back(6);

    std::cout << deque << '\n';

    Deque<int>::debug_printing(false);

    int x = deque.front(); // x = 5
    std::cout << x << '\n';
    deque.front() = 4;     // front of deque is now 4
    std::cout << deque << '\n';;
    
    int y = deque.back();  // y = 6
    std::cout << y << '\n';
    deque.back() = 7;      // back of deque is 7
    std::cout << deque << '\n';

    deque.pop_front(); // deque has now 1 value, i.e., 7
    deque.pop_back(); // deque is now empty

    std::cout << deque << '\n';

    int size = deque.size(); // size is zero
    std::cout << size << '\n';
    
    bool b = deque.is_empty(); // b is true
    std::cout << b << '\n';
    
    deque.push_front(1);
    deque.push_front(1);
    deque.push_front(1);
    size = deque.size(); // size is 3
    b = deque.is_empty(); // b is false
    std::cout << deque << '\n';
    std::cout << size << '\n';
    
    deque.clear(); // deque is now empty
    std::cout << deque << '\n';

    try
    {
        deque.pop_front();
    }
    catch(UnderflowError &)
    {
        std::cout << "UnderflowError caught" << '\n';
    }

    try
    {
        deque.pop_back();
    }
    catch(UnderflowError &)
    {
        std::cout << "UnderflowError caught" << '\n';
    }
    
    return 0;
}

// Name: Ethan Graham
// File: test.cpp

#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;
    
    SLList< int >::debug_printing(false);
    SLNode< int >::debug_printing(false);

    stack.push(5); // Top of stack is 5
    stack.push(6); // Top of stack is 6 (5 is below 6)
    stack.push(4); // Top of stack is 4 (6 is below 4)

    std::cout << stack;

    stack.pop();
    std::cout << stack;

    int x = stack.top(); 
    std::cout << "TOP:" << x << '\n'; // Should print 6

    stack.top() = 7;
    std::cout << stack; // Should print 7

    int size = stack.size();
    std::cout << "SIZE:" << size << '\n'; // Should print 2;

    bool b = stack.is_empty();
    std::cout << "IS EMPTY:" << b << '\n'; // Should print false

    stack.clear();

    b = stack.is_empty();
    std::cout << "IS EMPTY:" << b << '\n'; // Should print true
    size = stack.size();
    std::cout << "SIZE:" << size << '\n'; // Should Print 0

    try
    {
        stack.pop();
    }
    catch(UnderflowError &)
    {
        std::cout << "UnderflowError caught" << '\n';
    }
    
    
    return 0;
}

#include "Stack.h"

int main()
{
    Stack< int >::debug_printing(true);
    Stack< int > stack;
    stack.push(5); // Top of stack is 5
    stack.push(6); // Top of stack is 6 (5 is below 6)
    stack.push(4); // Top of stack is 4 (6 is below 4)
    std::cout << stack << '\n';

    Stack< int >::debug_printing(false);

    stack.pop(); // Top of stack is 6 (5 is below 6)
    std::cout << stack << '\n';

    int x = stack.top(); // x has value 6
    std::cout << x << '\n';

    stack.top() = 7; // Top of stack is 7 (5 is below 7)
    std::cout << stack << '\n';

    int size = stack.size(); // size has value 2
    std::cout << size << '\n';

    bool b = stack.is_empty();// b has value false
    std::cout << b << '\n';
    stack.clear(); // stack.size is 0
                   // Calling stack.pop() here will
                   // result in the throwing of an
                   // UnderflowError object
    b = stack.is_empty();
    std::cout << b << '\n';

    try
    {
        stack.pop();
    }
    catch (UnderflowError &)
    {
        std::cout << "UnderflowError caught" << std::endl;
    }

    return 0;
}

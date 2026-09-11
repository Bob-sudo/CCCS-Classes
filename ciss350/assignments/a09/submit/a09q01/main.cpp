#include <iostream>
#include "TreeNodev.h"

int main()
{
    TreeNodev< char > node('A');

    node.insert(0, 'B');
    node.insert(1, 'C');
    node.insert(2, 'D');

    std::cout << node << '\n';

    TreeNodev< char >* node1 = node.child(1);
    node1->insert(0, 'E');
    node1->insert(1, 'F');

    std::cout << (*node1) << '\n';

    // Testing basic functions
    
    std::cout << "node.is_root(): " << node.is_root() << '\n'; // prints 1
    std::cout << "node.child(0)->is_root(): "
              << node.child(0)->is_root() << '\n'; // prints 0
    
    std::cout << "node.is_leaf(): " << node.is_leaf() << '\n'; // prints 0
    std::cout << "node.child(0)->is_leaf(): "
              << node.child(0)->is_leaf() << '\n'; // prints 1

    std::cout << "node.child(1)->is_nonleaf(): "
              << node.child(1)->is_nonleaf() << '\n'; // prints 1

    // Testing Depth

    std::cout << '\n';
    std::cout << "node.depth(): " << node.depth() << '\n'; // prints 0
    
    std::cout << "node.child(1)->depth(): "
              << node.child(1)->depth() << '\n'; // prints 1
    
    std::cout << "node.child(1)->child(0)->depth(): "
              << node.child(1)->child(0)->depth() << '\n'; // prints 2

    // Testing Height

    std::cout << '\n';
    std::cout << "node.height(): " << node.height() << '\n'; // prints 2
    
    std::cout << "node.child(1)->height(): "
              << node.child(1)->height() << '\n'; // prints 1
    
    std::cout << "node.child(0)->height(): "
              << node.child(0)->height() << '\n'; // prints 0

    // Testing Size

    std::cout << '\n';
    std::cout << "node.size(): " << node.size() << '\n'; // prints 6
    
    std::cout << "node.child(1)->size(): "
              << node.child(1)->size() << '\n'; // prints 3
    
    std::cout << "node.child(0)->size(): "
              << node.child(0)->size() << '\n'; // prints 1

    // Parent/Root

    std::cout << '\n' << "Parent/Root" << '\n';
    std::cout << "Parent == node?: "
              << (node.child(1)->parent() == &node) << '\n'; // prints 1
    
    std::cout << "Root == node?: "
              << (node.child(1)->child(0)->root() == &node) << '\n'; // prints 1

    // Siblings

    TreeNodev<char>* node0 = node.child(0);     // B
    TreeNodev<char>* node1_ptr = node.child(1); // C
    TreeNodev<char>* node2 = node.child(2);     // D

    std::cout << '\n';
    std::cout << "(B->next() == C): "
              << (node0->next() == node1_ptr) << '\n'; // prints 1
    
    std::cout << "(C->prev() == B): "
              << (node1_ptr->prev() == node0) << '\n'; // prints 1
    
    std::cout << "(D->next() == NULL): "
              << (node2->next() == NULL) << '\n'; // prints 1
    
    std::cout << "(B->prev() == NULL): "
              << (node0->prev() == NULL) << '\n'; // prints 1

    // Child Access

    std::cout << '\n';
    std::cout << "Num Children: "
              << node.num_children() << '\n'; // prints 3

    std::cout << "First Child: "
              << node.first_child()->get_key() << '\n'; // Prints B
    
    std::cout << "Last Child: "
              << node.last_child()->get_key() << '\n'; // Prints D

    std::cout << "Child @ 1: "
              << node.child(1)->get_key() << '\n'; // Prints C
    
    std::cout << "Child @ 10: "
              << (node.child(10) == NULL) << '\n'; // Prints 1

    // Insert Exception
    
    std::cout << '\n';
    try
    {
        node.insert(1, 'X');
    }
    catch (ValueError&)
    {
        std::cout << "Insert exception caught" << '\n';
    }

    // Remove

    std::cout << '\n';
    node.remove(2); // remove D
    std::cout << node << '\n';
    std::cout << '\n';
    
    std::cout << "Num Children: "
              << node.num_children() << '\n'; // prints 3 (NULL slot)
    std::cout << "Child @ 2 == NULL: "
              << (node.child(2) == NULL) << '\n'; // prints 1

    // Copy Constructor

    std::cout << '\n' << "COPY CONSTRUCTOR" << '\n';
    TreeNodev<char> copyNode(node);

    std::cout << copyNode << '\n';
    std::cout << '\n' << node << '\n';

    std::cout << "Copy == Original: " << (copyNode == node) << '\n'; // Prints 1

    node.child(0)->insert(0, 'Z');

    std::cout << "node.child(0)->insert(0, 'Z')" << '\n';

    std::cout << "Copy == Original: " << (copyNode == node) << '\n'; // prints 0

    // Assignment operator

    TreeNodev<char> test('X');
    test = node;

    std::cout << '\n' << "Assignment Operator" << '\n';
    std::cout << "test == node:" << (test == node) << '\n'; // prints 1
    
    return 0;
}

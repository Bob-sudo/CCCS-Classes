#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree< char > node('A');

    node.insert_left('B');
    node.insert_right('C');

    std::cout << node << '\n';

    BinaryTree< char >* node1 = node.right();
    node1->insert_left('E');
    node1->insert_right('F');

    std::cout << *(node1) << '\n';

    // Testing basic functions
    
    std::cout << "node.is_root(): " << node.is_root() << '\n'; // prints 1
    std::cout << "node.left()->is_root(): "
              << node.left()->is_root() << '\n'; // prints 0
    
    std::cout << "node.is_leaf(): " << node.is_leaf() << '\n'; // prints 0
    std::cout << "node.left()->is_leaf(): "
              << node.left()->is_leaf() << '\n'; // prints 1

    std::cout << "node.right()->is_nonleaf(): "
              << node.right()->is_nonleaf() << '\n'; // prints 1

    // Testing Depth

    std::cout << '\n';
    std::cout << "node.depth(): " << node.depth() << '\n'; // prints 0
    
    std::cout << "node.right()->depth(): "
              << node.right()->depth() << '\n'; // prints 1

    // Testing Height

    std::cout << '\n';
    std::cout << "node.height(): " << node.height() << '\n'; // prints 1
    
    std::cout << "node.right()->height(): "
              << node.right()->height() << '\n'; // prints 0
    
    std::cout << "node.left()->height(): "
              << node.left()->height() << '\n'; // prints 0

    // Testing Size

    std::cout << '\n';
    std::cout << "node.size(): " << node.size() << '\n'; // prints 5
    
    std::cout << "node.right()->size(): "
              << node.right()->size() << '\n'; // prints 3
    
    std::cout << "node.left()->size(): "
              << node.left()->size() << '\n'; // prints 1

    // Parent/Root

    std::cout << '\n' << "Parent/Root" << '\n';
    std::cout << "Parent == node?: "
              << (node.right()->parent() == &node) << '\n'; // prints 1
    
    std::cout << "Root == node?: "
              << (node.right()->left()->root() == &node) << '\n'; // prints 1

    BinaryTree<char>* node0 = node.left();           // B
    BinaryTree<char>* node1_ptr = node.right();      // C
    BinaryTree<char>* node2 = node.right()->left();  // E

    std::cout << '\n';
    std::cout << "(E->next() == C): "
              << (node2->next() == node1_ptr) << '\n'; // prints 1
    
    std::cout << "(C->prev() == B): "
              << (node1_ptr->prev() == node0) << '\n'; // prints 0
    
    std::cout << "(E->next() == NULL): "
              << (node2->next() == NULL) << '\n'; // prints 0
    
    std::cout << "(B->prev() == NULL): "
              << (node0->prev() == NULL) << '\n'; // prints 1

    // Insert Exception
    
    try
    {
        node.insert_right('X');
    }
    catch (ValueError&)
    {
        std::cout << "Insert exception caught" << '\n';
    }

    // Copy Constructor

    std::cout << '\n' << "COPY CONSTRUCTOR" << '\n';
    BinaryTree<char> copyNode(node);

    std::cout << copyNode << '\n';
    std::cout << '\n' << node << '\n';

    std::cout << "Copy == Original: " << (copyNode == node) << '\n'; // Prints 1

    node.left()->insert_left('Z');

    std::cout << "node.left()->insert_left('Z')" << '\n';

    std::cout << "Copy == Original: " << (copyNode == node) << '\n'; // prints 0

    // Assignment operator

    BinaryTree<char> test('X');
    test = node;

    std::cout << '\n' << "Assignment Operator" << '\n';
    std::cout << "test == node:" << (test == node) << '\n'; // prints 1

    return 0;
}

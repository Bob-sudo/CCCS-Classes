#include "AVL.h"

int main()
{
    AVL a;
    std::cout << "Inorder/Insert:" << '\n' << '\n';
    a.insert(1); print_inorder(a); std::cout << '\n';
    a.insert(2); print_inorder(a); std::cout << '\n';
    a.insert(3); print_inorder(a); std::cout << '\n';
    a.insert(4); print_inorder(a); std::cout << '\n';
    a.insert(5); print_inorder(a); std::cout << '\n';
    a.insert(6); print_inorder(a); std::cout << '\n';
    a.insert(7); print_inorder(a); std::cout << '\n';

    // Copy Test
    AVL copy_a(a);
    std::cout << "Copy tree:" << '\n';
    print_inorder(copy_a); std::cout << '\n';

    // Removal test

    std::cout << "Testing Removal on copy:" << '\n';

    copy_a.remove(7); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(6); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(5); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(4); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(3); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(2); print_inorder(copy_a); std::cout << '\n';
    copy_a.remove(1); print_inorder(copy_a); std::cout << '\n';

    // Size
    
    std::cout << "Size a:" << '\n';
    std::cout << a.size() << '\n';
    std::cout << "Size copy a:" << '\n';
    std::cout << copy_a.size() << '\n';

    try
    {
        std::cout << "testing duplicate insert ... ";
        a.insert(7);
    }
    catch (ValueError & e)
    {
        std::cout << "pass" << '\n';
    }

    // Hieght / Min / Max
    std::cout << '\n';
    std::cout << "Height: " << a.height() << '\n';
    std::cout << "Min: " << a.min() << '\n';
    std::cout << "Max: " << a.max() << "\n\n";

    // Find
    std::cout << "Find 7: " << (*a.find(7)) << '\n';
    std::cout << "Find 8: " <<
        (a.find(8) != NULL ? "found" : "not found") << '\n';

    // Operators
    std::cout << '\n' << "Testing operator=:" << '\n';
    copy_a = a;
    print_inorder(copy_a); std::cout << '\n';
    std::cout << "Testing operator==:" << '\n';
    std::cout  << "copy_a == a?..." <<
        (copy_a == a ? "equal" : "not equal") << '\n';

    // Clear
    std::cout << '\n' << "Clearing Copy..." << '\n';
    copy_a.clear();
    std::cout  << "copy_a == a?..." <<
        (copy_a == a ? "equal" : "not equal") << '\n';
    std::cout << "Copy size: " << copy_a.size() << '\n';

    // Depth
    std::cout << '\n' << "Depth 3: " << a.depth(a.find(3)) << '\n';
    std::cout << "Depth 1: " << a.depth(a.find(1)) << '\n';
    std::cout << "Depth 4: " << a.depth(a.find(4)) << '\n';
    std::cout << "Depth 6: " << a.depth(a.find(6)) << '\n' << '\n';

     // Breadth first
    std::vector<int> bf = a.breadthfirst();

    std::cout << "Breadth-first:" << '\n';
    for (int x : bf)
        std::cout << x << " ";
    std::cout << '\n';
    
    // Range
    BinarySearchTreeNode * node = a.root();
    std::vector<int> v = a.range(node, 1, 5);
   
    std::cout << "Range (1, 5):" << '\n';
    for (int x : v)
        std::cout << x << " ";
    std::cout << '\n' << '\n';

    // Select
    for (int i = 0; i < a.size(); i++)
    {
        BinarySearchTreeNode* sel = a.select(i);
        if (sel)
            std::cout << "select(" << i << ") = " << sel->key() << '\n';
    }
    
    return 0;
}

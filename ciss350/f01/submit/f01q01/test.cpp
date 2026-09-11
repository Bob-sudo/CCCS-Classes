#include <iostream>
#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

int main()
{
    std::cout << "testing BinarySearchTreeNode ...\n";
    BinarySearchTreeNode * n = new BinarySearchTreeNode(5);
    print_inorder(n);
    
    std::cout << "\n\n";
    insert(n, 3);
    print_inorder(n);
    
    std::cout << "\n\n";
    insert(n, 0);
    print_inorder(n);
    
    std::cout << "\n\n";
    insert(n, 1);
    print_inorder(n);
    
    std::cout << "\n\n";
    insert(n, 4);
    print_inorder(n);
    
    std::cout << "\n\n";
    insert(n, 8);
    print_inorder(n);
    
    std::cout << "testing BinarySearchTree ... \n";
    BinarySearchTree bst;
    print_inorder(bst); std::cout << '\n';
    bst.insert(5); print_inorder(bst); std::cout << '\n';
    bst.insert(0); print_inorder(bst); std::cout << '\n';
    bst.insert(2); print_inorder(bst); std::cout << '\n';
    bst.insert(-2); print_inorder(bst); std::cout << '\n';
    bst.insert(10); print_inorder(bst); std::cout << '\n';
    bst.insert(8); print_inorder(bst); std::cout << '\n';
    bst.insert(9); print_inorder(bst); std::cout << '\n';
    bst.insert(7); print_inorder(bst); std::cout << '\n';

    std::cout << "PREORDER:" << '\n';
    print_preorder(bst); std::cout << '\n';

    std::cout << "POSTORDER:" << '\n';
    print_postorder(bst); std::cout << '\n';
    
    try
    {
        std::cout << "testing duplicate insert ... ";
        bst.insert(7);
    }
    catch (ValueError & e)
    {
        std::cout << "pass" << std::endl;
    }

    // Breadth first
    std::vector<int> bf = bst.breadthfirst();

    std::cout << '\n' << '\n' << "Breadth-first:" << '\n';
    for (int x : bf)
        std::cout << x << " ";
    std::cout << '\n';

    // Remove
    std::cout << '\n' << '\n';
    std::cout << "Remove(5):" << '\n';
    bst.remove(5);
    print_inorder(bst); std::cout << '\n';

    // Size / Height / Min / Max
    std::cout << "Size: " << bst.size() << '\n';
    std::cout << "Height: " << bst.height() << '\n';
    std::cout << "Min: " << bst.min() << '\n';
    std::cout << "Max: " << bst.max() << "\n\n";

    // Find
    std::cout << "Find 8: " << (*bst.find(8)) << '\n';
    std::cout << "Find 4: " <<
        (bst.find(4) != NULL ? "found" : "not found") << '\n';

    // Depth
    std::cout << '\n' << "Depth 10: " << bst.depth(bst.find(10)) << '\n';
    std::cout << "Depth -2: " << bst.depth(bst.find(-2)) << '\n' << '\n';

    // Range
    BinarySearchTreeNode * node = bst.root();
    std::vector<int> v = bst.range(node, 3, 9);
   
    std::cout << "Range (3, 9):" << '\n';
    for (int x : v)
        std::cout << x << " ";
    std::cout << '\n' << '\n';

    // Select
    for (int i = 0; i < bst.size(); i++)
    {
        BinarySearchTreeNode* sel = bst.select(i);
        if (sel)
            std::cout << "select(" << i << ") = " << sel->key() << '\n';
    }

    std::cout << '\n';

    // Copy Constructor
    BinarySearchTree copy_bst(bst);
    std::cout << "Copy == original: " << (copy_bst == bst) << '\n' << '\n';

    print_inorder(bst); std::cout << '\n';
    print_inorder(copy_bst); std::cout << '\n';

    // Clear
    copy_bst.clear();
    
    std::cout << "Clearing Copy..." << '\n';
    std::cout << (copy_bst.is_empty() ? "empty" : "not empty") << '\n';

    // == operator
    std::cout << "Removing (-2)..." << '\n';
    bst.remove(-2);
    std::cout << "Removing (9)..." << '\n';
    bst.remove(9);
    std::cout << "Copy == original: " << (copy_bst == bst) << '\n' << '\n';

    print_inorder(bst); std::cout << '\n';
    std::cout << "New BST size: " << bst.size() << '\n';
    
    return 0;
}

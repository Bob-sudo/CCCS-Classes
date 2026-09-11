// File: test.cpp
// Name: Ethan Graham

#include <iostream>
#include "DLList.h"

int main()
{
    DLNode<int> node(5);

    // debug printing
    DLNode< int >::debug_printing(false);
    std::cout << node << std::endl;
    DLNode< int >::debug_printing(true);

    std::cout << node << std::endl;
    node.set_key(6);
    std::cout << node.get_key() << std::endl;

    DLList< int >::debug_printing(false);
    DLNode< int >::debug_printing(false);
    

    DLList<int> list;
    std::cout << list << std::endl;

    list.insert_head(5);
    list.insert_head(6);
    list.insert_tail(7);
    list.insert_tail(8);
    std::cout << "FILLED" << '\n';
    std::cout << list << std::endl; // should print [6, 5, 7, 8]

    int x = list.remove_head();
    std::cout << list << std::endl; // [5, 7, 8]
    std::cout << x << std::endl; // 6

    
    x = list.remove_tail();
    std::cout << list << std::endl; // [5, 7]
    std::cout << x << std::endl; // 8

    

    DLNode<int> * p = list.find(5);
    std::cout << "FOUND P" << '\n';
    x = list.remove(p);
    std::cout << "REMOVED: " << x << '\n';
    std::cout << list << std::endl; // [7]
    std::cout << x << std::endl;
    
    try
    {
        list.remove(NULL);
    }
    catch (ValueError &)
    {
        std::cout << "ValueError caught" << std::endl;
    }
    
    list.clear();
    std::cout << "FINISHED CLEAR" << '\n';
    std::cout << list << std::endl; // []

    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    
    std::cout << list[0] << std::endl;
    std::cout << list[1] << std::endl;
    std::cout << list[2] << std::endl;

    
    try
    {
        list[3]; // should throw
    }
    catch (IndexError &)
    {
        std::cout << "IndexError caught" << std::endl;
    }
    
    std::cout << list.size() << std::endl; // 3
    std::cout << list.is_empty() << std::endl; // 0

    list.clear();
    std::cout << list.is_empty() << std::endl; // 1
    

    return 0;
}


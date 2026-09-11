// File: test.cpp
// Name: Ethan Graham

#include <iostream>
#include "SLNode.h"
#include "SLList.h"

int main()
{
    SLNode< int > node(5);
    std::cout << node << std::endl; // Prints the class of node, the
                                    // address of the node, the key_ and
                                    // the next_ pointer in this format:
                                    // <SLNode 0xbff9b4fc key:5, next:0>
                                    // where 0xbff9b4fc is the address of
                                    // this node, 5 is the value of key_,
                                    // 0 is the address in node.next_.
                                    // Different nodes will of course have
                                    // different values printed.
                                    // The format must however follow the
                                    // above.
    // The above format for printing is suitable for debugging your class.
    // Once your class is working you can turn off debug-printing and just
    // print the key_ in the node. This can be done as follows:
    SLNode< int >::debug_printing(false);
    std::cout << node << std::endl; // Prints 5 (and newline).
    SLNode< int >::debug_printing(true);// Turn on debug printing again.
    
    // The get_key(), set_key() and get_next(), set_next() of the node
    // does the obvious.
    std::cout << node.get_key() << std::endl; // Prints 5
    std::cout << node.get_next() << std::endl; // Prints 0
    node.set_key(6); // node.key_ is 6
    SLNode< int > node2(7);
    node.set_next(&node2); // node.next_ is &node2

    
    SLList< int > list;
    std::cout << list << std::endl;
    // Prints newline and then
    // <SLList 0x9788038 phead:0
    // >
    list.insert_head(5);
    std::cout << list << std::endl;
    // Prints newline and then
    // <SLList 0x9788038 phead:0x9788028
    // <SLNode 0x9788028 key:5, next:0>
    // >
    
    list.insert_head(6);
    std::cout << list << std::endl;
    // Prints newline and then
    // <SLList 0x9788038 phead:0x9788018 <-- CORRECTION
    // <SLNode 0x9788018 key:6, next:0x9788028> <-- CORRECTION
    // <SLNode 0x9788028 key:5, next:0> <-- CORRECTION
    // >
    
    
    
    // The above format for printing is suitable for debugging.
    // Once your SLList class is working, you can turn debug-printing
    // off.
    SLList< int >::debug_printing(false);
    SLNode< int >::debug_printing(false);
    
    list.insert_head(3);
    std::cout << list << std::endl; // Prints [3, 6, 5]
    list.insert_tail(3);
    std::cout << list << std::endl; // Prints [3, 6, 5, 3]
    list.insert_tail(2);
    std::cout << list << std::endl; // Prints [3, 6, 5, 3, 2]
    
    int x;

    x = list.remove_head();
    std::cout << list << std::endl; // Prints [6, 5, 3, 2]
    std::cout << x << std::endl; // Prints 3
    
    x = list.remove_tail();
    std::cout << list << std::endl; // Prints [6, 5, 3]
    std::cout << x << std::endl; // Prints 2
    
    SLNode< int > * p = list.find(5);// p points to the first node
                                     // with key_ = 5.
    x = list.remove(p);
    std::cout << list << std::endl; // Prints [6, 3]
    std::cout << x << std::endl; // Prints 5
    
    try
    {
        SLNode< int > * p;
        list.remove(p); // A ValueError exception object is
                        // thrown if the pointer argument is
                        // not valid.
    }
    catch (ValueError & e)
    {
        std::cout << "ValueError caught" << std::endl;
    }
    
    list.clear(); // list becomes empty.
    std::cout << list << std::endl; // Prints []
    
    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    list.insert_tail(8);
    std::cout << list << '\n';
    list.remove(list.find(5));
    std::cout << list << std::endl; // Prints [6, 7, 8]
    list.remove(list.find(8));
    std::cout << list << std::endl; // Prints [6, 7]
    list.clear();

    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    list.insert_tail(6);
    list.remove(6); // Remove first node whose key_ is 6.
    std::cout << list << std::endl; // Prints [5, 7, 6]
    
    try
    {
        list.remove(100); // A ValueError exception object is
                          // thrown if the key_ value to be
                          // removed is not found.
    }
    catch (ValueError & e)
    {
        std::cout << "ValueError caught" << std::endl;
    }
    list.clear();
    
    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    list.insert_tail(6);
    
    SLList< int > newlist(list);
    std::cout << newlist << std::endl; // Prints [5, 6, 7, 6]
    list.insert_tail(8);
    newlist = list;
    std::cout << newlist << std::endl; // Prints [5, 6, 7, 6, 8]
    
    list.clear();
    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    list.insert_tail(6);
    std::cout << list[0] << std::endl; // Prints 5, i.e., list[0] returns
                                       // the key_ in the first node of
                                       // list. Note that this should be
                                       // returned as a reference so that
                                       // it's possible to do this:
                                       // list[0] = 42;
    std::cout << list[1] << std::endl; // Prints 6
    std::cout << list[2] << std::endl; // Prints 7
    std::cout << list[3] << std::endl; // Prints 6
    try
    {
        list[4]; // This will cause an IndexError
                 // object to be thrown since list
                 // has only 4 nodes.
    }
    catch (IndexError & e)
    {
        std::cout << "IndexError caught" << std::endl;
    }
    try
    {
        list[-1]; // This will also cause an IndexError
                  // to be thrown since the index is < 0.
    }
    catch (IndexError & e)
    {
        std::cout << "IndexError caught" << std::endl;
    }
    list.clear();

    
    list.insert_tail(5);
    list.insert_tail(6);
    list.insert_tail(7);
    list.insert_tail(6);
    std::cout << list.size() << std::endl; // Prints 4.
    std::cout << list.is_empty() << std::endl; // Prints 0
    
    list.clear();
    std::cout << list.is_empty() << std::endl; // Prints 1
    // You can also compare lists. In other words if list1 and list2
    // are two SLList objects, then list1 == list2 is true exactly
    // when the values in list1 and list2 are the same and appear in
    // order, starting from the head.
    // Of course operator!= is just the "opposite" of operator==.
    
    // If list is an SLList object and p points to a node in list,
    // then calling list.insert_before(p, 5) will insert 5 (as a node)
    // in front of the node that p points to.
    // list.insert_after(p, 5) will insert 5 (as a node) behind the
    // node that p points to.
    
    // If list is an SLList object, then list.front() returns a reference
    // to the key_ member of the head node of list. This is similar to
    // list[0].
    // If list is an SLList object, then list.back() returns a reference
    // to the key member of the tail node of list.
    
    return 0;
}

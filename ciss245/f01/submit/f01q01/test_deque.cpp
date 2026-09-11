// File: test_deque.cpp
// Name: Ethan Graham

#include <iostream>
#include "Deque.h"

int main()
{

    // Integer testing
    std::cout << "Testing Deque< int >\n";
    Deque< int > dq;               // creates a dq of size 0 and capacity 5
    std::cout << dq << std::endl;  // prints []
    dq.insert_head(5);             // dq becomes [5]
    dq.insert_head(6);             // dq becomes [6, 5]
    dq.insert_tail(-1);            // dq becomes [6, 5, -1]
    std::cout << dq << std::endl;  // prints [6, 5, -1]
    std::cout << dq.get_size() << std::endl; // prints 3

    Deque< int > dq1(dq);          // Copy constructor: dq1 becomes [6, 5, -1]
    Deque< int > dq2;
    dq2 = dq;                      // dq2 becomes [6, 5, -1]
    dq = dq;                       // dq is still [6, 5, -1]

    int head = dq.remove_head();   // head = 6 and dq becomes [5, -1]
    int tail = dq.remove_tail();   // tail = -1 and dq becomes [5]

    dq.clear();                    // dq becomes []
    std::cout << dq.is_empty() << std::endl; // prints 1
    
    try
    {
        dq.remove_head();
    }
    catch (const UnderflowError & e)
    {
        std::cout << "underflow error!" << std::endl;
    }

    try
    {    
        while (1)
        {
            dq.insert_tail(1); // to cause memory allocation error
        }
    }
    catch (const OverflowError & e)
    {
        std::cout << "overflow error!" << std::endl;
    }

    dq.clear();

    // Double testing
    std::cout << "Testing Deque< double >\n";
    Deque< double > dq_double;
    
    std::cout << dq_double << std::endl;  
    dq_double.insert_head(5.5);             
    dq_double.insert_head(6.1);             
    dq_double.insert_tail(-1.2);           
    std::cout << dq_double << std::endl;  
    std::cout << dq_double.get_size() << std::endl;
    
    Deque< double > dq_double1(dq_double);          
    Deque< double > dq_double2;
    dq_double2 = dq_double;                      
    dq_double = dq_double;                       

    double head_d = dq_double.remove_head();   
    double tail_d = dq_double.remove_tail();   

    dq_double.clear();                    
    std::cout << dq_double.is_empty() << std::endl; 
    
    try
    {
        dq_double.remove_head();
    }
    catch (const UnderflowError & e)
    {
        std::cout << "underflow error!" << std::endl;
    }

    try
    {
        while (1)
        {
            dq.insert_tail(1.1); // to cause memory allocation error
        }
    }
    catch (const OverflowError & e)
    {
        std::cout << "overflow error!" << std::endl;
    }
    
    // Char testing
    std::cout << "Testing Deque< char >\n";
    Deque< char > dq_char;
    
    std::cout << dq_char << std::endl;  
    dq_char.insert_head('a');             
    dq_char.insert_head('b');             
    dq_char.insert_tail('c');           
    std::cout << dq_char << std::endl;  
    std::cout << dq_char.get_size() << std::endl;
    
    Deque< char > dq_char1(dq_char);          
    Deque< char > dq_char2;
    dq_char2 = dq_char;                      
    dq_char = dq_char;                       

    double head_c = dq_char.remove_head();   
    double tail_c = dq_char.remove_tail();   

    dq_char.clear();                    
    std::cout << dq_char.is_empty() << std::endl; 
    
    try
    {
        dq_char.remove_head();
    }
    catch (const UnderflowError & e)
    {
        std::cout << "underflow error!" << std::endl;
    }

    try
    {
        while (1)
        {
            dq.insert_tail('c'); // to cause memory allocation error
        }
    }
    catch (const OverflowError & e)
    {
        std::cout << "overflow error!" << std::endl;
    }
    
    return 0;
}

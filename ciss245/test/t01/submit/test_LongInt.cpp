// File: test_LongInt.cpp
// Name: Ethan Graham

#include <iostream>
#include "LongInt.h"

int main()
{
    LongInt H = get_LongInt("-13524");
    std::cout << H << '\n';
    
    LongInt I = get_LongInt("0");   
    std::cout << I << '\n'; // prints 0
    
    LongInt J = get_LongInt("1000");
    std::cout << J << '\n'; 
    
    LongInt K = get_LongInt("9876543210");
    std::cout << K << '\n'; // prints 9876543210
    
    LongInt M = get_LongInt("-9876543210");
    std::cout << M << '\n'; // prints -9876543210

    LongInt N = get_LongInt("246");
    LongInt O = get_LongInt("246");
    bool test0 = (N == O);
    std::cout << "(==) Operator test: " << test0 << '\n';

    LongInt P = get_LongInt("246");
    LongInt Q = get_LongInt("245");
    bool test1 = (P != Q);
    std::cout << "(!=) Operator test: " << test1 << '\n';

    LongInt R = get_LongInt("246");
    LongInt S = get_LongInt("247");
    bool test2 = (R < S);
    std::cout << "(<) Operator test: " << test2 << '\n';

    LongInt T = get_LongInt("246"); 
    LongInt U = get_LongInt("247");
    bool test3 = (T <= S);
    std::cout << "(<=) Operator test: " << test3 << '\n';

    LongInt V = get_LongInt("246");
    LongInt W = get_LongInt("247");
    bool test4 = (V > W);
    std::cout << "(>) Operator test: " << test4 << '\n';

    LongInt X = get_LongInt("3"); 
    LongInt Y = get_LongInt("324");
    bool test5 = (X >= Y);
    std::cout << "(>=) Operator test: " << test5 << '\n';

    // Test cases for addition
    std::cout << J + K << '\n';
    std::cout << J + 12345 << '\n';
    std::cout << 12345 + J << '\n';
    
    return 0;
}

// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include <limits>
#include "mystring.h"

const int MAX_BUF = 1024;

void test_str_cmp()
{
    char s[MAX_BUF];
    char t[MAX_BUF];

    std::cin.getline(s, MAX_BUF);
    std::cin.getline(t, MAX_BUF);

    std::cout << str_cmp(s, t) << std::endl;
}

void test_str_cpy()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    std::cin.getline(y, MAX_BUF);
    str_cpy(x, y);
    std::cout << x << std::endl;
    return;
}

void test_str_chr()
{
    char x[MAX_BUF];
    char c;
    std::cin.getline(x, MAX_BUF);
    std::cin >> c;
    std::cout << str_chr(x, c) << std::endl;
    return;
}

void test_str_str()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    std::cin.getline(x, MAX_BUF);
    std::cin.getline(y, MAX_BUF);
    std::cout << str_str(x, y) << std::endl;
    return;
}

void test_str_lower()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    std::cin.getline(y, MAX_BUF);
    str_lower(x, y);
    std::cout << x << std::endl;
    return;
}

void test_str_tok()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    char delimiters[MAX_BUF] = " ,.";
    std::cin.getline(y, MAX_BUF);
    bool b = str_tok(x, y, delimiters);
    std::cout << b << ' ' << x << ' ' << y << std::endl;
    return;
}

void test_chat_bot()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    char delimiters[MAX_BUF] = " ,.";
    std::cout << "Hi, what is your name?" << '\n';
    std::cin.getline(y, MAX_BUF);

    // Get rid of spaces behind
    str_rstrip(y);
    
    // If there is no space
    if(str_chr(y, ' ') == -1)
    {
        std::cout << "Hi " << y << ". How are you?" << '\n';      
    }
    else
    {
        while(str_chr(y, ' ') > -1) //Eliminate Spaces
        {  
            str_tok(x, y, delimiters);
        }
        std::cout << "Hi " << y << ". How are you?" << '\n';
    }

    y[MAX_BUF] = {0};

    std::cin.getline(y, MAX_BUF); // Take emotion

    // Get rid of spaces behind
    str_rstrip(y);
    
    // If there is no space
    if(str_chr(y, ' ') == -1)
    {        
        char sad[] = "sad";
        char depressed[] = "depressed";
        str_lower(y, y);
        if(str_str(y, sad) > -1 || str_str(y, depressed) > -1)
            std::cout << "I'm sorry to hear that. Why are you " <<  y << '?' << '\n';
        else
            std::cout << "I don't understand" << '\n';
    }
    else
    {
        char very[] = "very";
        bool adj = (str_str(y, very) > -1) ? true : false;
        
        while(str_chr(y, ' ') > -1) //Eliminate Spaces
        {  
            str_tok(x, y, delimiters);
        }
        
        char sad[] = "sad";
        char depressed[] = "depressed";
        
        
        str_lower(y, y); // Lowercase string
        if(str_str(y, sad) > -1 || str_str(y, depressed) > -1)
            std::cout << "I'm sorry to hear that. ";
        // Happy if()
                
        std::cout << "Why are you";
        if(adj)
            std::cout << " so ";
        else
            std::cout << ' '; 
        std::cout << y << '?' << '\n';
    }
    
}

int main()
{
    int i = 0;
    std::cin >> i;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (i)
    {
        case 0:
            test_str_cmp();
            break;
        case 1:
            test_str_cpy();
            break;
        case 2:
            test_str_chr();
            break;
        case 3:
            test_str_str();
            break;
        case 5:
            test_str_lower();
            break;
        case 6:
            test_str_tok();
            break;
        case 7:
            test_chat_bot();
            break;
    }
    
    return 0;
}

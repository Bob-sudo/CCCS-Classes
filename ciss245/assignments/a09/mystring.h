// File: mystring.h
// Name: Ethan Graham

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class mystring
{
  public:
  mystring(const char x[])
      : capacity_(1024), length_(0)
    {
        // Copy the relevant characters x[0], ... to s[0], ...
        // and set the length_ appropriately. For instance if x is "abc"
        // the length_ is set to 3.
        while (x[length_] != '\0' && length_ < capacity_)
        {
            s_[length_] = x[length_];
            length_++;
        }
        s_[length_] = '\0';
    }
    
    mystring(char c)
        : capacity_(1024), length_(1)
    {
        std::cout << "testing constructor" << '\n';
        // Copy c to s[0]. Set capacity_ and length_ accordingly.
        s_[0] = c;
        s_[1] = '\0';
    }
    
    mystring()  
        : capacity_(1024), length_(0)
    {
        s_[0] = '\0';
    }
    
    mystring(const mystring & x);
    
    bool operator==(const mystring &); 
    bool operator!=(const mystring &);
    
    bool empty() const;
    
    mystring & operator=(const mystring & x); 
    mystring & operator=(char c);
    
    void clear();
    
    char operator[](int) const;
    char & operator[](int);
    
    mystring & operator+=(const mystring &); 
    mystring & operator+=(char c);
    mystring operator+(const mystring &);
    mystring operator+(char);
    
    void resize(int i); 
    void resize(int i, char c);
    
    int find(char c, int start = 0); 
    int find(const mystring & s, int start = 0);
    
    mystring substr(int i, int len);

    int get_len() const;
    char get_arr(int) const;
    
  private:
    const int capacity_;
    char s_[1024];
    int length_;
};

std::ostream & operator<<(std::ostream &, const mystring &);
std::istream & operator>>(std::istream &, mystring &);

bool operator== (const char[], const mystring &);

#endif

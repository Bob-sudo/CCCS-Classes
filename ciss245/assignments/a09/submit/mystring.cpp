// File: mystring.cpp
// Name: Ethan Graham

#include <iostream>
#include "mystring.h"

mystring::mystring(const mystring & x)
    : capacity_(1024), length_(x.length_)
{
    std::cout << "in copy cnstr\n";
    for (int i = 0; i < x.length_; i++)
    {
        s_[i] = x.s_[i];
    }
    s_[x.length_] = '\0';
}

std::ostream & operator<<(std::ostream & cout, const mystring & x)
{
    int len = x.get_len();
    for(int i = 0; i < len; i++)
    {
        cout << x.get_arr(i);
    }

    return cout;
}

std::istream & operator>>(std::istream & cin, mystring & x)
{
    // Get a string from the user, say you store it in local character
    // array t of size 1024. (use cin and t.)
    // Copy t[i], ... to x.s[i] starting with i = 0;. Stop when t[i] is
    // '\0'. Set the length of x accordingly.
    // Finally, return the reference cin.
    //
    // To minimize code duplication, it's easier to do the following:
    // 1. Clear x (see the method mystring::clear())
    // 2. Perform += to add the string in t to x (i.e., to x.s).
    char t[1024];
    cin >> t;
    x.clear();
    x += t;
    
    return cin;
}

int mystring::get_len() const
{
    return length_;
}

char mystring::get_arr(int i) const
{
    return s_[i];
}

bool mystring::operator==(const mystring & x)
{
    if(length_ != x.length_) return false;
    for (int i = 0; i < length_; i++)
    {
        if (s_[i] != x.s_[i]) return false;
    }
                               
    return true;
}

bool mystring::operator!=(const mystring & x)
{
    return !(*this == x);
}
    
bool mystring::empty() const
{
    return length_ == 0;
}
    
mystring & mystring::operator=(const mystring & x)
{
    for (int i = 0; i < x.length_; i++)
    {
        s_[i] = x.s_[i];
    }
    s_[x.length_] = '\0';
    
    return (*this);
}

mystring & mystring::operator=(char c)
{
    length_ = 1;
    s_[0] = c;
    s_[1] = '\0';
    return (*this);
}
    
void mystring::clear()
{
    length_ = 0;
    s_[0] = '\0';
}
    
char mystring::operator[](int i) const
{
    return (i >= 0 && i < length_) ? s_[i] : '\0';
}

char & mystring::operator[](int i)
{
    return s_[i];
}

mystring & mystring::operator+=(const mystring & x)
{
    if (length_ + x.length_ < capacity_)
    {
        for (int i = 0; i < x.length_; i++)
        {
            s_[length_ + i] = x.s_[i];
        }
        length_ += x.length_;
        s_[length_] = '\0';
    }
    return (*this);
}

mystring & mystring::operator+=(char c)
{
    if (length_ + 1 < capacity_)
    {
        
        s_[length_] = c;
        length_++;
        s_[length_] = '\0';
    }
    return (*this);
}

mystring mystring::operator+(const mystring & x)
{
    return mystring(*this) += x;
}

mystring mystring::operator+(char c)
{
    return mystring(*this) += c;
}
    
void mystring::resize(int i)
{   
    length_ = i;
    s_[length_] = '\0';
}

void mystring::resize(int i, char c)
{
    if (i > length_ && i < capacity_)
    {
        for (int j = length_; j < i; j++)
        {
            s_[j] = c;
        }
    }
    resize(i);
}
    
int mystring::find(char c, int start)
{
    for (int i = start; i < length_; i++)
    {
        if (s_[i] == c) return i;
    }
    return -1;
}

int mystring::find(const mystring & s, int start)
{
    for (int i = start; i <= length_ - s.length_; i++)
    {
        bool found = true;
        for (int j = 0; j < s.length_; j++)
        {
            if (s_[i + j] != s.s_[j])
            {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}
    
mystring mystring::substr(int i, int len)
{
    mystring res;
    if (i >= 0 && i < length_)
    {
        int j;
        for (j = 0; j < len && (i + j) < length_; j++)
        {
            res.s_[j] = s_[i + j];
        }
        res.length_ = j;
        res.s_[res.length_] = '\0';
    }
    return res;
}

// File: LongInt.cpp
// Name: Ethan Graham

#include <iostream>
#include "LongInt.h"

std::ostream & operator<<(std::ostream & out, const LongInt & num)
{
    if (num.sign_ == -1) out << '-';

    for (int i = num.size_ - 1; i >= 0; i--)
    {
        out << num.x_[i];
    }

    return out;
}

bool operator==(const LongInt & num1, const LongInt & num2)
{
    if (num1.sign_ != num2.sign_) return false;
    if (num1.size_ != num2.size_) return false;
    
    for (int i = 0; i < num1.size_; i++)
    {
        if (num1.x_[i] != num2.x_[i]) return false;
    }

    return true;
}

bool operator!=(const LongInt & num1, const LongInt & num2)
{
    return (num1 == num2) ? false : true;
}

bool operator<(const LongInt & num1, const LongInt & num2)
{
    if (num1.sign_ > num2.sign_) return false;
    if (num1.size_ > num2.size_) return false;

    for (int i = 0; i < num1.size_; i++)
    {
        if (num1.x_[i] > num2.x_[i]) return false;
    }

    return (num1 == num2) ? false : true;
    return true;
}

bool operator<=(const LongInt & num1, const LongInt & num2)
{
    if (num1 == num2) return true;
    if (num1 < num2) return true;
    else return false;
}

bool operator>(const LongInt & num1, const LongInt & num2)
{
    if (num1.sign_ < num2.sign_) return false;
    if (num1.size_ < num2.size_) return false;

    for (int i = 0; i < num1.size_; i++)
    {
        if (num1.x_[i] < num2.x_[i]) return false;
    }

    return (num1 == num2) ? false : true;
    return true;
}

bool operator>=(const LongInt & num1, const LongInt & num2)
{
    if (num1 == num2) return true;
    if (num1 > num2) return true;
    else return false;
}

LongInt operator+(const LongInt & i, const LongInt & j)
{
    LongInt res;
    
    res.sign_ = i.sign_;
    res.size_ = (i.size_ >= j.size_) ? i.size_ + 1: j.size_ + 1;
    
    int carry = 0;
    int index_i = 0; 
    int index_j = 0;
    int index_res = 0;

    // Fill res
    for (int k = 0; k < res.size_; k++)
    {
        res.x_[k] = 0;
    }

    // Digit addition
    while (index_i < i.size_ || index_j < j.size_)
    {
        int sum = i.x_[index_i] + j.x_[index_j] + carry;
        res.x_[index_res] = sum % 10;
        carry = sum / 10;
        
        index_i++;
        index_j++;
        index_res++;
    }

    return res;
}

LongInt operator+(const LongInt & i, int j)
{
    LongInt temp;
    temp.sign_ = (j < 0) ? -1 : 1;
    temp.size_ = 0;
    j = (j < 0) ? j * -1 : j * 1; // get rid of sign in j

    while (j > 0)
    {
        temp.x_[temp.size_] = j % 10;
        j /= 10;
        temp.size_++;
    } 

    return i + temp;
}

LongInt operator+(int i, const LongInt & j)
{
    return j + i;
}

LongInt get_LongInt(const char s[])
{
    LongInt ret; // LongInt Return Value

    if (s[0] != '-')
    {
        ret.sign_ = 1; // Set sign
        
        // Get size of array      
        int count = 0;                                       
        for (int i = 0; i < 1000; i++)                       
        {                                                    
            if (s[i] == '\0') break;                         
            ++count;                                         
        }                                                    
        std::cout << "<count> == " <<  count << std::endl;                                       
        ret.size_ = count;                                                            
        // Assign character values to int values          
        for (int i = 0; i < ret.size_; i++)                      
        {                                                    
            ret.x_[i] = s[ret.size_ - 1 - i] - '0';
        }                                                    
                               
    }
    else
    {
        ret.sign_ = -1; // Set sign
        
        // Get size of array      
        int count = 0;                                       
        for (int i = 1; i < 1000; i++) // Start ahead of the '-' sign 
        {                                                    
            if (s[i] == '\0') break;                         
            ++count;                                         
        }                                                    
        std::cout << "<count> == " <<  count << std::endl;                                       
        ret.size_ = count;                                                            
        // Assign character values to int values             
        for (int i = 0; i < ret.size_; i++)                      
        {                                                    
            ret.x_[i] = s[ret.size_ - i] - '0';
        }                                   
    }

    return ret;  
}

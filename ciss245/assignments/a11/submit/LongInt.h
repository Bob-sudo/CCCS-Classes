// File: LongInt.h
// Name: Ethan Graham

#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>
#include <vector>
#include <cmath>

class LongInt
{
  public:
    LongInt();
    LongInt(int);
    LongInt(const char[]);
    LongInt(const LongInt&);

    LongInt& operator=(const char[]);

    // Helper Functions
    void rm_leading_zeros(); // Removes leading zeros
    bool absLessThan(const LongInt&) const; // Compares absolute sizes of #'s

    // Addition Operators
    LongInt& operator+=(const LongInt&);
    LongInt& operator+=(int);
    friend LongInt operator+(LongInt, const LongInt&);
    friend LongInt operator+(LongInt, int);
    friend LongInt operator+(int, LongInt);

    // Subtraction Operators
    LongInt& operator-=(const LongInt&);
    LongInt& operator-=(int);
    friend LongInt operator-(LongInt, const LongInt&);
    friend LongInt operator-(LongInt, int);
    friend LongInt operator-(int, LongInt);

    // Multiplication Operators
    LongInt& operator*=(const LongInt&);
    LongInt& operator*=(int);
    friend LongInt operator*(LongInt, const LongInt&);
    friend LongInt operator*(LongInt, int);
    friend LongInt operator*(int, LongInt);

    // Division Operators
    LongInt& operator/=(const LongInt&);
    LongInt& operator/=(int);
    friend LongInt operator/(LongInt, const LongInt&);
    friend LongInt operator/(LongInt, int);
    friend LongInt operator/(int, LongInt);
    
    // Modulos Operators
    LongInt& operator%=(const LongInt&);
    LongInt& operator%=(int);
    friend LongInt operator%(LongInt, const LongInt&);
    friend LongInt operator%(LongInt, int);
    friend LongInt operator%(int, LongInt);

    // Cout & Cin
    friend std::ostream& operator<<(std::ostream&, const LongInt&);
    friend std::istream& operator>>(std::istream&, LongInt&);

    // Comparison Operators
    // LongInt-LongInt
    friend bool operator==(const LongInt&, const LongInt&);
    friend bool operator!=(const LongInt&, const LongInt&);
    friend bool operator<(const LongInt&, const LongInt&);
    friend bool operator<=(const LongInt&, const LongInt&);
    friend bool operator>(const LongInt&, const LongInt&);
    friend bool operator>=(const LongInt&, const LongInt&);

    // LongInt-Int
    friend bool operator==(const LongInt&, int);
    friend bool operator!=(const LongInt&, int);
    friend bool operator<(const LongInt&, int);
    friend bool operator<=(const LongInt&, int);
    friend bool operator>(const LongInt&, int);
    friend bool operator>=(const LongInt&, int);

    // Int-LongInt
    friend bool operator==(int, const LongInt&);
    friend bool operator!=(int, const LongInt&);
    friend bool operator<(int, const LongInt&);
    friend bool operator<=(int, const LongInt&);
    friend bool operator>(int, const LongInt&);
    friend bool operator>=(int, const LongInt&);

    // ++ operator
    LongInt& operator++();   // ++a
    LongInt operator++(int); // a++

    // -- operator
    LongInt& operator--();   // --a
    LongInt operator--(int); // a--
private:
    std::vector< int > x;
    int sign;
};



#endif

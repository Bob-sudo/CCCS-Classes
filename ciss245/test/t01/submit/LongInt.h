// File: LongInt.h
// Name: Ethan Graham

#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>

struct LongInt
{
    int x_[1000];
    int size_;
    int sign_;
};

std::ostream & operator<<(std::ostream &, const LongInt &);
LongInt get_LongInt(const char s[]);
std::ostream & operator<<(std::ostream &, const LongInt &);
bool operator==(const LongInt &, const LongInt &);
bool operator!=(const LongInt &, const LongInt &);
bool operator<(const LongInt &, const LongInt &);
bool operator<=(const LongInt &, const LongInt &);
bool operator>(const LongInt &, const LongInt &);
bool operator>=(const LongInt &, const LongInt &);
LongInt operator+(const LongInt & i, const LongInt & j);
LongInt operator+(const LongInt & i, int j);
LongInt operator+(int i, const LongInt & j);
LongInt operator-(const LongInt & i, const LongInt & j);
LongInt operator-(const LongInt & i, int j);
LongInt operator-(int i, const LongInt & j);

#endif

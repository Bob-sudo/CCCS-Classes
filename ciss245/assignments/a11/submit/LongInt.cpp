// File: LongInt.cpp
// Name: Ethan Graham

#include "LongInt.h"

std::ostream& operator<<(std::ostream & cout, const LongInt & value)
{
    if(value.sign == -1)
    {
        std::cout << '-';
    }
    for (int i = value.x.size() - 1; i >= 0; --i)
    {
        cout << value.x[i];
    }

    return cout;
}

void LongInt::rm_leading_zeros()
{
    while(x.size() > 1 && x.back() == 0)
    {
        x.pop_back();
    }
    if (x.size() == 1 && x[0] == 0)
    {
        sign = 1;
    }
}

bool LongInt::absLessThan(const LongInt& other) const
{
    if (x.size() != other.x.size()) return x.size() < other.x.size();

    for (int i = x.size() - 1; i >= 0; --i)
    {
        if (x[i] != other.x[i]) return x[i] < other.x[i];
    }
    return false;
}

LongInt::LongInt()
{
    x.push_back(0);
    sign = 1;
}

LongInt::LongInt(int value)
{
    if (value == 0)
    {
        x.push_back(0);
        sign = 1;
    }
    else
    {
        sign = (value > 0) ? 1 : -1;
        int i = (value > 0) ? value : -value;
        while (i > 0)
        {
            x.push_back(i % 10);
            i /= 10;
        }
    }
}

LongInt::LongInt(const char str[])
{
    sign = 1;
    int len = 0;

    // Find the length
    while (str[len] != '\0')
    {
        len++;
    }

    int start = 0;

    // Take care of Sign
    if (str[0] == '-')
    {
        sign = -1;
        start = 1;
    }

    // Skip leading 0's
    while (start < len && str[start] == '0')
    {
        start++;
    }

    // Return if all values are 0
    if (start == len)
    {
        x.push_back(0);
        sign = 1;
        return;
    }

    // Put in digits
    for (int i = len - 1; i >= start; --i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            x.push_back(str[i] - '0');
        }
        else
        {
            x.clear();
            x.push_back(0);
            sign = 1;
            return;
        }
    }

    rm_leading_zeros();
}

LongInt::LongInt(const LongInt & other)
{
    x = other.x;
    sign = other.sign;
}

LongInt& LongInt::operator=(const char str[])
{
    *this = LongInt(str);
    return *this;
}

// Addition
LongInt& LongInt::operator+=(const LongInt & value)
{
    // If different signs
    if (sign != value.sign)
    {
        *this -= (value) * -1;
        return *this;
    }

    int carry = 0;
    int max_Size = (x.size() > value.x.size()) ? x.size() : value.x.size();
    
    x.resize(max_Size, 0);

    for (int i = 0; i < max_Size; ++i)
    {
        int digit  = (i < value.x.size()) ? value.x[i] : 0;
        x[i] += digit + carry;
        carry = x[i] / 10;
        x[i] %= 10;
    }

    if (carry >= 1)
    {
        x.push_back(carry);
    }

    rm_leading_zeros();
    return *this;
}

LongInt& LongInt::operator+=(int a)
{
    return *this += LongInt(a);
}

LongInt operator+(LongInt a, const LongInt & b)
{
    return a += b;
}

LongInt operator+(LongInt a, int b)
{
    return a += b;
}

LongInt operator+(int a, LongInt b)
{
    return LongInt(a) += b;
}

// Subtraction
LongInt& LongInt::operator-=(const LongInt & value)
{
    // If different signs
    if (sign != value.sign)
    {
        *this += (value) * -1;
        return *this;
    }

    // If |a| < |b|, flip signs, b - a
    if(absLessThan(value))
    {
        LongInt temp = value;
        temp -= *this;
        temp.sign = -temp.sign;
        *this = temp;
        return *this;
    }

    int borrow = 0;
    for (int i = 0; i < x.size(); ++i)
    {
        int digit = (i < value.x.size()) ? value.x[i] : 0;
        x[i] -= digit + borrow;

        if (x[i] < 0)
        {
            x[i] += 10;
            borrow = 1;
        } else
        {
            borrow = 0;
        }
    }

    rm_leading_zeros();
    return *this;   
}

LongInt& LongInt::operator-=(int a)
{
    return *this -= LongInt(a);
}

LongInt operator-(LongInt a, const LongInt & b)
{
    return a -= b;
}

LongInt operator-(LongInt a, int b)
{
    return a -= b;
}

LongInt operator-(int a, LongInt b)
{
    return LongInt(a) -= b;
}

// Multiplication
LongInt& LongInt::operator*=(const LongInt & value)
{
    LongInt product;
    product.x.resize(x.size() + value.x.size(), 0);
    product.sign = sign * value.sign;

    for (int i = 0; i < x.size(); i++)
    {
        int carry = 0;
        for (int j = 0; j < value.x.size(); j++)
        {
            int digit = (j < value.x.size()) ? value.x[j] : 0;
            product.x[i + j] += x[i] * digit + carry;
            carry = product.x[i + j] / 10;
            product.x[i + j] %= 10;
        }
    }
    
    product.rm_leading_zeros();
    *this = product;
    return *this;
}

LongInt& LongInt::operator*=(int a)
{
    return *this *= LongInt(a);
}

LongInt operator*(LongInt a, const LongInt & b)
{
    return a *= b;
}

LongInt operator*(LongInt a, int b)
{
    return a *= b;
}

LongInt operator*(int a, LongInt b)
{
    return LongInt(a) *= b;
}

// Division
LongInt& LongInt::operator/=(const LongInt & value)
{
    // If Division by 0
    

    LongInt dividend = *this;
    LongInt divisor = value;
    LongInt quotient;
    LongInt current;

    quotient.x.resize(dividend.x.size(), 0);

    for (int i = dividend.x.size() - 1; i >= 0; --i)
    {
        current.x.insert(current.x.begin(), dividend.x[i]);
        current.rm_leading_zeros();

        int count = 0;
        while (current >= divisor)
        {
            current -= divisor;
            ++count;
        }
        quotient.x[i] = count;
    }

    quotient.sign = sign * value.sign;
    quotient.rm_leading_zeros();
    *this = quotient;
    return *this;
}

LongInt& LongInt::operator/=(int a)
{
    return *this /= LongInt(a);
}

LongInt operator/(LongInt a, const LongInt & b)
{
    return a /= b;
}

LongInt operator/(LongInt a, int b)
{
    return a /= b;
}

LongInt operator/(int a, LongInt b)
{
    return LongInt(a) /= b;
}

LongInt& LongInt::operator%=(const LongInt & value)
{
    // if (value == 0)
    // {
    //     std::cout << "ERROR" << '\n';
    //     *this = 0;
    //     return *this;
    // }

    LongInt dividend = *this;
    LongInt divisor = value;
    LongInt current;

    for (int i = dividend.x.size() - 1; i >= 0; --i)
    {
        current.x.insert(current.x.begin(), dividend.x[i]);
        current.rm_leading_zeros();

        while (current >= divisor)
        {
            current -= divisor;
        }
    }

    current.sign = sign;
    current.rm_leading_zeros();
    *this = current;
    return *this;
}

LongInt& LongInt::operator%=(int a)
{
    return *this %= LongInt(a);
}

LongInt operator%(LongInt a, const LongInt & b)
{
    return a %= b;
}

LongInt operator%(LongInt a, int b)
{
    return a %= b;
}

LongInt operator%(int a, LongInt b)
{
    return LongInt(a) %= b;
}

// LongInt-LongInt Comparison
bool operator<(const LongInt & a, const LongInt & b)
{
    if (a.sign != b.sign)
    {
        return a.sign < b.sign;
    }

    bool less;
    if (a.x.size() != b.x.size())
    {
        less = a.x.size() < b.x.size();
    }
    else
    {
        less = false;
        for (int i = a.x.size() - 1; i >= 0; --i)
        {
            if (a.x[i] != b.x[i])
            {
                less = a.x[i] < b.x[i];
                break;
            }
        }
    }

    return a.sign == 1 ? less : !less && a != b;
}

bool operator==(const LongInt & a, const LongInt & b)
{
    return a.sign == b.sign && a.x == b.x;
}

bool operator!=(const LongInt & a, const LongInt & b)
{
    return !(a == b);
}

bool operator<=(const LongInt & a, const LongInt & b)
{
    return (a < b) || (a == b);
}

bool operator>(const LongInt & a, const LongInt & b)
{
    return !(a <= b);
}

bool operator>=(const LongInt & a, const LongInt & b)
{
    return !(a < b);
}

// LongInt-Int Comparison
bool operator==(const LongInt & a, int b)
{
    return a == LongInt(b);
}

bool operator!=(const LongInt & a, int b)
{
    return a != LongInt(b);
}

bool operator< (const LongInt & a, int b)
{
    return a <  LongInt(b);
}

bool operator<=(const LongInt & a, int b)
{
    return a <= LongInt(b);
}

bool operator> (const LongInt & a, int b)
{
    return a >  LongInt(b);
}

bool operator>=(const LongInt & a, int b)
{
    return a >= LongInt(b);
}

// Int-LongInt
bool operator==(int a, const LongInt & b)
{
    return LongInt(a) == b;
}

bool operator!=(int a, const LongInt & b)
{
    return LongInt(a) != b;
}

bool operator< (int a, const LongInt & b)
{
    return LongInt(a) <  b;
}

bool operator<=(int a, const LongInt & b)
{
    return LongInt(a) <= b;
}

bool operator> (int a, const LongInt & b)
{
    return LongInt(a) >  b;
}

bool operator>=(int a, const LongInt & b)
{
    return LongInt(a) >= b;
}

LongInt & LongInt::operator++()
{
    *this += 1;
    return *this;
}

LongInt LongInt::operator++(int)
{
    LongInt temp(*this);
    *this += 1;
    return temp;
}

LongInt & LongInt::operator--()
{
    *this -= 1;
    return *this;
}

LongInt LongInt::operator--(int)
{
    LongInt temp(*this);
    *this -= 1;
    return temp;
}

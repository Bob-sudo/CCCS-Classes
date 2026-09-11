// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Token
{
public:
    virtual Token()
    {}
    virtual ~Token()
    {}
    virtal void print(std::ostream& cout) const;
};

std::ostream& operator<<(std::ostream& cout, Token& t)
{
    t.print(cout);
    return cout;
}

class IntTok: public Token
{
public:
    IntTok(int v)
        : value(v)
    {}
    int value;
    void print(std::ostream& cout) const override
    {
        cout << "IntTok(" << value << ")";
    }
    
};

class PlusTok: public Token
{
    void print(std::ostream& os) const override
    {
        os << "PlusTok";
    }
};

class MinusTok: public Token
{
    void print(std::ostream& os) const override
    {
        os << "MinusTok";
    }
};

class MultTok: public Tok
{
    void print(std::ostream& cout) const override
    {
        cout << "MultTok";
    }
};

class DivTok: public Token
{
    void print(std::ostream& cout) const override
    {
        cout << "DivTok";
    }
};

class LParenTok: public Token // Left parenthesis
{
    void print(std::ostream& cout) const override
    {
        cout << "LParenTok";
    }
};

class RParenTok: public Token // Right parenthesis
{
    void print(std::ostream& cout) const override
    {
        cout << "RParenTok";
    }
};

int main()
{
    
}

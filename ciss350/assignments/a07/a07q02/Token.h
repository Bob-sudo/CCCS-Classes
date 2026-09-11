#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <vector>
#include <stack>

class Token
{
public:
    virtual void print(std::ostream & cout) const = 0;
    virtual ~Token()
    {}
};

class IntTok: public Token
{
public:
    IntTok(int v)
        : value(v)
    {}
    void print(std::ostream & cout) const
    {
        cout << "IntTok(" << value << ')';
    }
    int get_value() const
    {
        return value;
    }
private:
    int value;
};

class PlusTok: public Token
{
public:
    void print(std::ostream & cout) const
    {
        cout << "PlusTok";
    }
};

class MinusTok: public Token
{
public:
    void print(std::ostream & cout) const
    {
        cout << "MinusTok";
    }
};

class MultTok: public Token
{
public:
    void print(std::ostream & cout) const
    {
        cout << "MultTok";
    }
};

class DivTok: public Token
{
public:
    void print(std::ostream & cout) const
    {
        cout << "DivTok";
    }
};

std::ostream & operator<<(std::ostream & cout, const Token & tok)
{
    tok.print(cout);
    return cout;
}

std::ostream & operator<<(std::ostream & cout,
                          const std::vector< Token* > & toks)
{
    cout << '[';
    for(int i = 0; i < toks.size(); i++)
    {
        cout << *toks[i];
        if (i + 1 < toks.size())
        {
            cout << ", ";
        }
    }
    cout << ']';
    return cout;
}

#endif

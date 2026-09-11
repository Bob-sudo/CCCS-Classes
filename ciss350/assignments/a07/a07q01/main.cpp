#include <iostream>
#include <string>
#include <vector>

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

class LParenTok: public Token // Left parenthesis
{
public:
    void print(std::ostream & cout) const
    {
        cout << "LParenTok";
    }
};

class RParenTok: public Token // Right parenthesis
{
public:
    void print(std::ostream & cout) const
    {
        cout << "RParenTok";
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

void stringtotok(std::string s, std::vector< Token* > & t)
{    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        else if(isdigit(s[i]))
        {
            std::string num = "";

            while(i < s.size() && isdigit(s[i]))
            {
                num += s[i];
                i++;
            }

            t.push_back(new IntTok(std::stoi(num)));
            i--;
        }
        else
        {
            switch(s[i])
            {
                case '+':
                    t.push_back(new PlusTok());
                    break;

                case '-':
                    t.push_back(new MinusTok());
                    break;

                case '*':
                    t.push_back(new MultTok());
                    break;

                case '/':
                    t.push_back(new DivTok());
                    break;

                case '(':
                    t.push_back(new LParenTok());
                    break;

                case ')':
                    t.push_back(new RParenTok());
                    break;
            }
        }
    }
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::vector< Token* > toks;

    stringtotok(s, toks);
    std::cout << toks << '\n';
    
    return 0;
}

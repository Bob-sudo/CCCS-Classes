#include "Token.h"
#include <string>

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

            }
        }
    }
}

// RPN
void stack_eval(std::stack< int > & stk, const std::vector< Token* > & toks)
{
    for(int i = 0; i < toks.size(); i++)
    {
        if(dynamic_cast<IntTok*>(toks[i]) != nullptr)
        {
            IntTok * p = dynamic_cast<IntTok*>(toks[i]);
            stk.push(p->get_value());
        }
        else if(dynamic_cast<PlusTok*>(toks[i]) != nullptr)
        {
            if(stk.size() < 2)
            {
                std::cout << "ERROR" << '\n';
                return;
            }
            
            int a = stk.top();
            stk.pop();

            int b = stk.top();
            stk.pop();

            stk.push(b + a);
        }
        else if(dynamic_cast<MinusTok*>(toks[i]) != nullptr)
        {
            if(stk.size() < 2)
            {
                std::cout << "ERROR" << '\n';
                return;
            }
            
            int a = stk.top();
            stk.pop();

            int b = stk.top();
            stk.pop();

            stk.push(b - a);
        }
        else if(dynamic_cast<MultTok*>(toks[i]) != nullptr)
        {
            if(stk.size() < 2)
            {
                std::cout << "ERROR" << '\n';
                return;
            }
            
            int a = stk.top();
            stk.pop();

            int b = stk.top();
            stk.pop();

            stk.push(b * a);
        }
        else if(dynamic_cast<DivTok*>(toks[i]) != nullptr)
        {
            if(stk.size() < 2)
            {
                std::cout << "ERROR" << '\n';
                return;
            }
            
            int a = stk.top();
            stk.pop();

            int b = stk.top();
            stk.pop();

            stk.push(b / a);
        }
    }

    std::cout << stk.top() << '\n';
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::vector< Token* > toks;
    stringtotok(s, toks);

    std::stack< int > stk;
    stack_eval(stk, toks);
    
    return 0;
}

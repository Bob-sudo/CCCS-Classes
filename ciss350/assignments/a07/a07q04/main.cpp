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

int precedence(Token * tok)
{
    if(dynamic_cast<PlusTok*>(tok) != nullptr ||
       dynamic_cast<MinusTok*>(tok) != nullptr)
    {
        return 1;
    }

    if(dynamic_cast<MultTok*>(tok) != nullptr ||
       dynamic_cast<DivTok*>(tok) != nullptr)
    {
        return 2;
    }

    return 0;
}

void apply_top_operator(std::stack< int > & nums, std::stack< Token* > & ops)
{

    if(nums.size() < 2)
    {
        std::cout << "ERROR" << '\n';
        return;
    }

    if(ops.empty())
    {
        std::cout << "ERROR" << '\n';
        return;
    }
    
    int right = nums.top();
    nums.pop();
    int left = nums.top();
    nums.pop();

    Token* op = ops.top();
    ops.pop();
    
    if(dynamic_cast<PlusTok*>(op) != nullptr)
    {
        nums.push(right + left);
    }
    else if(dynamic_cast<MinusTok*>(op) != nullptr)
    {
        nums.push(left - right);
    }
    else if(dynamic_cast<MultTok*>(op) != nullptr)
    {
        nums.push(right * left);
    }
    else if(dynamic_cast<DivTok*>(op) != nullptr)
    {
        nums.push(left / right);
    }
}

// infix
void stack_eval(std::stack< int > & nums,
                std::stack< Token* > & ops,
                const std::vector< Token* > & toks)
{
    for(int i = 0; i < toks.size(); i++)
    {
        if(dynamic_cast<IntTok*>(toks[i]) != nullptr)
        {
            IntTok * p = dynamic_cast<IntTok*>(toks[i]);
            nums.push(p->get_value());
        }
        else if(dynamic_cast<LParenTok*>(toks[i]) != nullptr)
        {
            ops.push(toks[i]);
        }
        else if(dynamic_cast<RParenTok*>(toks[i]) != nullptr)
        {
            while(!ops.empty() &&
                  dynamic_cast<LParenTok*>(ops.top()) == nullptr)
            {
                apply_top_operator(nums, ops);
            }

            if(ops.empty())
            {
                std::cout << "ERROR" << '\n';
                return;
            }

            ops.pop();
        }
        else
        {
            while(!ops.empty() &&
                  precedence(ops.top()) >= precedence(toks[i]))
            {
                apply_top_operator(nums, ops);
            }
            ops.push(toks[i]);
        }
    }
    
    while(!ops.empty())
    {
        if(dynamic_cast<LParenTok*>(ops.top()) != nullptr)
        {
            std::cout << "ERROR" << '\n';
            return;
        }
        apply_top_operator(nums, ops);
    }

    if(nums.size() != 1)
    {
        std::cout << "ERROR" << '\n';
        return;
    }

    std::cout << nums.top() << '\n';
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::vector< Token* > toks;
    stringtotok(s, toks);

    std::stack< int > nums;
    std::stack< Token * > ops;
    stack_eval(nums, ops, toks);
    
    return 0;
}

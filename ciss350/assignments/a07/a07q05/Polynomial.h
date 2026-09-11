#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>
#include <string>
#include <iostream>

// A monomial is a term in a polynomial. For instance 5 * x ^ 3 is a
// monomial. For this term, we store (3, 5), i.e., the degree and the
// coefficient.

class Monomial
{
  public:
    Monomial(int d, int c)
        : degree(d), coefficient(c)
    {}
    int degree;
    int coefficient;

    bool operator==(const Monomial & other) const
        {
            return degree == other.degree &&
            coefficient == other.coefficient;
        }
};

class Polynomial
{
  public:
    Polynomial()
    {}
    Polynomial(int value)
    {
        Monomial m(0, value);
        p.push_back(m);
    }
    Polynomial(std::string s)
    {
        int i = 0;
        
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }
            
            int sign = 1;
            if(i < s.size() && s[i] == '+')
            {
                i++;
            }
            else if(i < s.size() && s[i] == '-')
            {
                sign = -1;
                i++;
            }

            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }

            if(i < s.size() && s[i] == '+')
            {
                i++;
            }
            else if(i < s.size() && s[i] == '-')
            {
                sign = -1;
                i++;
            }

            int coeff = 1;
            int deg = 0;

            if(i < s.size() && isdigit(s[i]))
            {
                std::string num = "";

                while(i < s.size() && isdigit(s[i]))
                {
                    num += s[i];
                    i++;
                }

                coeff = std::stoi(num);
            }

            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }
            if(i < s.size() && s[i] == '*')
            {
                i++;
            }
            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }

            if(i < s.size() && s[i] == 'x')
            {
                i++;
                deg = 1;

                if(i < s.size() && s[i] == '^')
                {
                    i++;
                    std::string pow = "";

                    while(i < s.size() && isdigit(s[i]))
                    {
                        pow += s[i];
                        i++;
                    }

                    deg = std::stoi(pow);
                }
            }
            else
                deg = 0;

            add_term(sign * coeff, deg);
        }  
    }

    Polynomial(const Polynomial & other)
    {
        p = other.get_list();
    }

    void add_term(int coeff, int deg)
    {
        if(coeff == 0)
        {
            return;
        }

        // find monomial with same degree
        for(auto q = p.begin(); q != p.end(); q++)
        {
            // if found, add coefficients
            if(q->degree == deg)
            {
                q->coefficient += coeff;

                if(q->coefficient == 0)
                {
                    p.erase(q);
                }
                return;
            }
        }

        // Otherwise, insert in correct degree position
        for(auto q = p.begin(); q != p.end(); ++q)
        {
            if(q->degree > deg)
            {
                Monomial m(deg, coeff);
                p.insert(q, m);
                return;
            }
        }

        Monomial m(deg, coeff);
        p.push_back(m);
    }

    std::list< Monomial > get_list() const
    {
        return p;
    }

    bool operator==(const Polynomial & other) const
        {
            return p == other.p;
        }
    
    bool operator==(const int & other) const
        {
            if(p.empty())
            {
                return other == 0;
            }
            
            if(p.size() == 1)
            {
                auto first = p.begin();

                return first->degree == 0 &&
                    first->coefficient == other;
            }
            return false;
        }

    bool operator!=(const Polynomial & other) const
        {
            return !(p == other.p);
        }

    bool operator!=(const int & other) const
        {
            if(p.empty())
            {
                return other != 0;
            }
            
            if(p.size() == 1)
            {
                auto first = p.begin();

                return first->degree != 0 &&
                    first->coefficient != other;
            }
            return true;
        }

    Polynomial operator=(const Polynomial & other)
    {
        if(this != &other)
        {
            p = other.p;
        }
        return *this;
    }

    Polynomial operator+(const Polynomial & other) const
    {
        Polynomial res(*this);
        
        std::list<Monomial> q = other.get_list();
        for(auto i = q.begin(); i != q.end() ; ++i)
        {
            res.add_term(i->coefficient, i->degree);
        }
        return res;
    }
    
    Polynomial operator+=(const Polynomial & other)
    {
        *this = *this + other;
        return *this;
    }

    Polynomial operator-(const Polynomial & other) const
    {
        Polynomial res(*this);
        
        std::list<Monomial> q = other.get_list();
        for(auto i = q.begin(); i != q.end() ; ++i)
        {
            res.add_term(-1 * i->coefficient, i->degree);
        }
        return res;
    }

    Polynomial operator-=(const Polynomial & other)
    {
        *this = *this - other;
        return *this;
    }

    Polynomial operator*(const Polynomial & other) const
    {
        Polynomial res;
        
        for(auto i = p.begin(); i != p.end() ; ++i)
        {
            for(auto j = other.p.begin(); j != other.p.end() ; ++j)
            {
                int new_coeff = i->coefficient * j->coefficient;
                int new_degree = i->degree + j->degree;

                res.add_term(new_coeff, new_degree);
            }
        }
        return res;
    }

    Polynomial operator*=(const Polynomial & other)
    {
        *this = *this * other;
        return *this;
    }
    
  private:
    std::list< Monomial > p; // The term with smallest degree is at the head.
};

std::ostream & operator<<(std::ostream & cout,
                          const Polynomial & poly)
{
    std::list< Monomial > q = poly.get_list();
    bool first = true;

    if(q.empty())
    {
        cout << 0;
        return cout;
    }
    
    for(auto i = --q.end(); ; --i)
    {
        if(!first)
        {
            if(i->coefficient >= 0)
                cout << " + ";
            else
                cout << " - ";
        }
        
        else if(i->coefficient < 0)
            cout << '-';
        
        if(i->degree == 0)
        {
            cout << abs(i->coefficient) << ' '; 
        }
        else if(i->degree == 1)
        {
            if(abs(i->coefficient) == 1)
                cout << "x";
            else
                cout << abs(i->coefficient) << "x";
        }
        else
        {
            if(abs(i->coefficient) == 1)
                cout << "x^" << i->degree;
            else
                cout << abs(i->coefficient) << "x^" << i->degree;
        }

        if(i == q.begin())
            break;

        first = false;
    }

    return cout;
}

bool operator==(const int & lhs, const Polynomial & rhs)
{
    return rhs == lhs;
}

bool operator!=(const int & lhs, const Polynomial & rhs)
{
    return rhs != lhs;
}

Polynomial operator+(const int & lhs, const Polynomial & rhs)
{
    return rhs + lhs;
}

Polynomial operator-(const int & lhs, const Polynomial & rhs)
{
    return rhs - lhs;
}

Polynomial operator*(const int & lhs, const Polynomial & rhs)
{
    return rhs * lhs;
}

#endif

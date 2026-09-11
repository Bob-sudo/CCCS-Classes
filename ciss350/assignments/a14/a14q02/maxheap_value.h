#ifndef MAXHEAP_VALUE_H
#define MAXHEAP_VALUE_H

#include <string>
#include <iostream>

class maxheap_value
{
  public:
    maxheap_value(int p = 0, std::string str = "")
        : priority(p), s(str)
    {}
    
    int get_priority() const
    {
        return priority;
    }
x
    std::string get_s() const
    {
        return s;
    }

    bool operator==(const maxheap_value& other) const
    {
        return priority == other.priority && s == other.s;
    }

    bool operator>(const maxheap_value& other) const
    {
        return priority > other.priority;
    }
    
  private:
    int priority;
    std::string s;
};

inline std::ostream & operator<<(std::ostream & cout, const maxheap_value & x)
{
    cout << '<' << x.get_priority() << ", " << x.get_s() << '>';
    return cout;
}

#endif

#ifndef SET_H
#define SET_H

#include "HashTable.h"

template < typename T >
class Set
{
  public:
    
    // Adds x to d is x is not in d.
    void insert(const T & x)
    {
        try
        {
            d.get(x);
        }
        catch(KeyError&)
        {
            d.set(x, 'a');
        }
    }
    
    // Removes x from d if x is in d. Otherwise KeyError is thrown.
    void remove(const T & x)
    {
        d.remove(x);
    }
    
    // Returns true if x is in d
    bool has_element(const T & x) const
    {
        try
        {
            const_cast<HT<T,char>&>(d).get(x);
            return true;
        }
        catch(KeyError&)
        {
            return false;
        }
    }
    
    // Returns true if each value in d is also in set.d
    bool issubset(const Set< T > & set) const
    {
        std::vector<T> keys = d.keys();

        for(int i = 0; i < keys.size(); ++i)
        {
            if(!set.has_element(keys[i]))
               return false;
        }
        return true;
    }
    
    // Same as issubset
    bool operator<=(const Set< T > & set) const
    {
        return issubset(set);
    }
    
    // Returns true if each value in set.d is also in d
    bool issuperset(const Set< T > & set) const
    {
        return set.issubset(*this);
    }
    
    // Same as issuperset
    bool operator>=(const Set< T > & set) const
    {
        return issuperset(set);
    }
    
    // Returns true if *this and set contains the same values
    bool operator==(const Set< T > & set) const
        {
            return issubset(set) && set.issubset(*this);
        }

    template < typename t >
    friend std::ostream & operator<<(std::ostream & cout, const Set< t > & set);
    
  private:
    HT< T, char > d;
};

// If set contains "a", "b", print as {a, b}
template < typename T >
std::ostream & operator<<(std::ostream & cout, const Set< T > & set)
{
    std::vector<T> keys = set.d.keys();

    cout << "{";
    for (int i = 0; i < keys.size(); i++)
    {
        if (i > 0) cout << ", ";
        cout << keys[i];
    }
    cout << "}";

    return cout;
}

#endif

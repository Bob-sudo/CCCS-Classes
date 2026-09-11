#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>

class Hashable
{
public:
    virtual unsigned int hash() const = 0;
};

class HashableString: public std::string, public Hashable
{
public:
    HashableString(const std::string & s)
        : std::string(s)
    {}
    
    unsigned int hash() const
    {
        unsigned int h = 0;
        unsigned int power = 1;
        for (unsigned int i = 0; i < length(); i++)
        {
            h += operator[](i) * power; power *= 10;
        }
        return h;
    }
};

template <typename Key, typename Value>
class HTRow
{
public:
    HTRow(const Key& key, Value value)
        : key_(key), value_(value)
    {}

    Key key() const
    {
        return key_;
    }

    Value value() const
    {
        return value_;
    }

    void set_value(Value value)
    {
        value_ = value;
    }
    
private:
    Key key_;
    Value value_;
};

class KeyError
{};

template <typename Key, typename Value>
class HT
{
public:
    HT(int size=10, double threshold=0.75)
    {
        table_ = std::vector<std::list<HTRow<Key, Value>>>(size);
        num_get_collisions_ = 0;
        num_gets_ = 0;
        threshold_ = threshold;
    }
    
    void set(Key key, Value value)
    {
        int index = key.hash() % table_.size();

        for(auto it = table_[index].begin(); it != table_[index].end(); ++it)
        {
            if(it->key() == key)
            {
                it->set_value(value);
                return;
            }
        }
        table_[index].push_back(HTRow(key, value));
    }
    
    Value get(const Key & key)
    {
        num_gets_++;
        int index = key.hash() % table_.size();

        for(auto it = table_[index].begin(); it != table_[index].end(); ++it)
        {
            if(it->key() == key)
            {
                if(num_gets_ > 0 &&
                   (double)num_get_collisions_ / num_gets_ > threshold_)
                {
                    resize(table_.size() * 2);
                }
                
                return it->value();
            }
            num_get_collisions_++;
        }

        if(num_gets_ > 0 &&
           (double)num_get_collisions_ / num_gets_ > threshold_)
        {
            resize(table_.size() * 2);
        }
        
        throw KeyError();
    }
    
    void remove(const Key & key)
    {
        int index = key.hash() % table_.size();

        for(auto it = table_[index].begin(); it != table_[index].end(); ++it)
        {
            if(it->key() == key)
            {
                table_[index].erase(it);
                return;
            }
        }
        throw KeyError();
    }
    
    void clear()
    {
        for(int i = 0; i < table_.size(); ++i)
        {
            table_[i].clear();
        }
    }
    
    std::vector<Key> keys() const
    {
        std::vector<Key> res;
        for(int i = 0; i < table_.size(); ++i)
        {
            for(auto it = table_[i].begin(); it != table_[i].end(); ++it)
            {
                res.push_back(it->key());
            }
        }
        return res;
    }
    
    void resize(int size)
    {
        std::vector<std::list<HTRow<Key, Value>>> old_table = table_;
        table_ = std::vector<std::list<HTRow<Key, Value>>>(size);

        for (int i = 0; i < old_table.size(); ++i)
        {
            for (auto it = old_table[i].begin(); it != old_table[i].end(); ++it)
            {
                int index = it->key().hash() % table_.size();
                table_[index].push_back(*it);
            }
        }

        num_gets_ = 0;
        num_get_collisions_ = 0;
    }

    template <typename K, typename V>
    friend std::ostream & operator<<(std::ostream&, const HT<K, V>&);
    
private:
    std::vector< std::list<HTRow<Key, Value>>> table_;
    
    int num_get_collisions_;
    int num_gets_;
    double threshold_;
};

template <typename Key, typename Value>
std::ostream & operator<<(std::ostream & cout, const HT<Key, Value> & d)
{
    cout << "{";
    bool first = true;

    for (int i = 0; i < d.table_.size(); ++i)
    {
        for (auto it = d.table_[i].begin(); it != d.table_[i].end(); ++it)
        {
            if (!first) cout << ", ";
            cout << it->key() << ":" << it->value();
            first = false;
        }
    }

    cout << "}";
    return cout;
}

#endif

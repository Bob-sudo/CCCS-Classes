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
    
    std::vector<Key> keys()
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

int main()
{
    HT<HashableString, double> d0;     // 10 linked lists (i.e. 10 buckets)
    
    d0.set(HashableString("John"), 5.2);
    d0.set(HashableString("Josh"), 5.5);
    d0.set(HashableString("Amy"), 6.0);
    d0.set(HashableString("Andrew"), 6.2);
    d0.set(HashableString("Anne"), 5.0);
    d0.set(HashableString("Ethan"), 5.9);
    std::cout << d0 << std::endl;

    // Testing get functions
    std::cout << "Anne value: " << d0.get(HashableString("Anne")) << '\n'; // prints 5
    std::cout << "Josh value: " << d0.get(HashableString("Josh")) << '\n'; // prints 5.5

    // testing set
    std::cout << "Setting Josh to 5.0" << '\n';
    d0.set(HashableString("Josh"), 5.0);
    std::cout << "Josh value: " << d0.get(HashableString("Josh")) << '\n'; // prints 5

    // KeyError
    std::cout << '\n' << "Trying to access Batman..." << '\n';
    try
    {
        d0.get(HashableString("Batman"));
    }
    catch (KeyError&)
    {
        std::cout << "KeyError caught" << '\n';
    }

    std::cout << '\n' << "Removing Anne..." << '\n';
    d0.remove(HashableString("Anne"));

    std::cout << "Trying to accesse Anne" << '\n';
    try
    {
        d0.get(HashableString("Anne"));
    }
    catch (KeyError&)
    {
        std::cout << "KeyError caught" << '\n';
    }

    std::cout << '\n' << "Removing Dawn..." << '\n';
    try
    {
        d0.remove(HashableString("Dawn"));
    }
    catch (KeyError&)
    {
        std::cout << "Remove error caught" << '\n';
    }

    // Collision testing
    std::cout << '\n' << "Creating d2" << '\n';
    HT<HashableString, double> d2(2);

    d2.set(HashableString("A"), 1);
    d2.set(HashableString("B"), 2);
    d2.set(HashableString("C"), 3);
    d2.set(HashableString("D"), 4);

    std::cout << d2.get(HashableString("A")) << '\n';         // prints 1
    std::cout << d2.get(HashableString("D")) << '\n' << '\n'; // prints 4

    std::vector<HashableString> keys = d2.keys();

    for (int i = 0; i < keys.size(); ++i)
    {
        std::cout << keys[i] << '\n';
    }

    std::cout << "Clearing d2" << '\n';
    d2.clear();

    try
    {
        d2.get(HashableString("A"));
    }
    catch (KeyError&)
    {
        std::cout << "Clear worked" << std::endl;
    }

    // Forcing resize trigger
    std::cout << '\n' << "Testing resize" << '\n';
    HT<HashableString, double> d3(2, 0.1); // low tolerance

    d3.set(HashableString("A"), 1);
    d3.set(HashableString("B"), 2);
    d3.set(HashableString("C"), 3);

    // Force lots of gets
    for (int i = 0; i < 20; i++)
    {
        try { d3.get(HashableString("A")); } catch(KeyError&) { std::cout << "Something is wrong"; }
        try { d3.get(HashableString("B")); } catch(KeyError&) { std::cout << "Something is wrong"; }
    }

    std::cout << d3.get(HashableString("A")) << '\n'; // prints 1
    std::cout << d3.get(HashableString("B")) << '\n'; // prints 2
    std::cout << d3.get(HashableString("C")) << '\n'; // prints 3

    HT<HashableString, double> d4(5);

    std::cout << "Stress Test" << '\n';

    for (int i = 0; i < 100; i++)
    {
        d4.set(HashableString("key" + std::to_string(i)), i * 1.0);
    }

    for (int i = 0; i < 100; i++)
    {
        std::cout << d4.get(HashableString("key" + std::to_string(i))) << '\n';
    }
    
    return 0;
}
    

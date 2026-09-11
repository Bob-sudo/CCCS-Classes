#include <iostream>
#include <vector>
#include <list>

//=============================================================================
// hash(std::string) -> unsigned int is a simple hash function for std::string
// objects.
//
// WARNING: Remmeber to mod by the size of your table!
//=============================================================================
unsigned int hash(const std::string & s)
{
    unsigned int h = 0;
    unsigned int power = 1;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        h += int(s[i]) * power;
        power *= 10;
    }
    return h;
}

//=============================================================================
// Each record in the hash table is a (key, value) pair of type (std::string,
// double).
//=============================================================================
class HTRow
{
public:
    HTRow(const std::string& key, double value)
        : key_(key), value_(value)
    {}

    std::string key() const
    {
        return key_;
    }

    double value() const
    {
        return value_;
    }

    void set_value(double value)
    {
        value_ = value;
    }
    
private:
    std::string key_;
    double value_;
};

//=============================================================================
// This exception class is used to throw an exception in the event that a key
// is not found in the hash table during a search or a remove.
//=============================================================================
class KeyError
{};


//=============================================================================
// Hashtable of (key, value) of type (std::string, double).
//
// When the percentage of get collisions is > threshold, the hashtable
// resizes by doubling its size. See num_gets_, num_gets_collisions_,
// and threshood_.
//
// The number of get() invocation is stored in _num_gets and the number
// of get collisions is stored in _num_get_collisions. The threshold for
// resize is stored in _threshold. A get collision is accessing a (key,
// value) pair that is not what you want. Therefore if you hash to a linked
// linked of three nodes and the node you really want is the last, then
// there are two collisions.
//=============================================================================
class HT
{
public:
    // The instance variable table is initialized to a vector of linked list
    // of HTRows objects. The size of the table is the given size.
    // When the percentage collision for get() operations is greater than
    // threshold, the table doubles its size.
    //
    // num_gets_ and num_get_collisions_ must be initialized to 0.
    // The default threshold is 0.75.
    HT(int size=10, double threshold=0.75)
    {
        table_ = std::vector<std::list<HTRow>>(size);
        num_get_collisions_ = 0;
        num_gets_ = 0;
        threshold_ = threshold;
    }
    
    // 1. Search for record with key_ matching key
    // 2. If the record is found, modify value_ to value
    // 3. If the record is not found, insert a new record
    void set(std::string key, double value)
    {
        int index = hash(key) % table_.size();

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
    
    // 1. Search for record with key_ matching key
    // 2. If the record is found, return the value
    // 3. If the record is not found, KeyError is thrown
    double get(const std::string & key)
    {
        num_gets_++;
        int index = hash(key) % table_.size();

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
    
    // 1. Removes record with key_ matching key
    // 2. If record is not found, KeyError is thrown
    void remove(const std::string & key)
    {
        int index = hash(key) % table_.size();

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
    
    // Clear all entries in all linked lists.
    void clear()
    {
        for(int i = 0; i < table_.size(); ++i)
        {
            table_[i].clear();
        }
    }
    
    // Returns a std::vector<std::string> of keys
    std::vector<std::string> keys()
    {
        std::vector<std::string> res;
        for(int i = 0; i < table_.size(); ++i)
        {
            for(auto it = table_[i].begin(); it != table_[i].end(); ++it)
            {
                res.push_back(it->key());
            }
        }
        return res;
    }
    
    // Resizes the hashtable
    void resize(int size)
    {
        // Resize the table (you need to recreate the hashtable structure.
        // Remember to reset num_gets_ and num_get_collisions_ to 0.
        std::vector<std::list<HTRow>> old_table = table_;
        table_ = std::vector<std::list<HTRow>>(size);

        for (int i = 0; i < old_table.size(); ++i)
        {
            for (auto it = old_table[i].begin(); it != old_table[i].end(); ++it)
            {
                int index = hash(it->key()) % table_.size();
                table_[index].push_back(*it);
            }
        }

        num_gets_ = 0;
        num_get_collisions_ = 0;
    }

    friend std::ostream & operator<<(std::ostream&, const HT&);
    
private:
    std::vector< std::list< HTRow > > table_;
    
    int num_get_collisions_; // Records number of collisions in get()
    int num_gets_;           // Records number of get()
    double threshold_;       // If num_get_collisions_/num_gets_ > threshold
                             // (when num_gets_ > 0) the table must resize
};

std::ostream & operator<<(std::ostream & cout, const HT & d)
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
    HT d0;     // 10 linked lists (i.e. 10 buckets)
    HT d1(20); // 20 linked lists (i.e. 20 buckets)
    
    d0.set("John", 5.2);
    d0.set("Josh", 5.5);
    d0.set("Amy", 6.0);
    d0.set("Andrew", 6.2);
    d0.set("Anne", 5.0);
    d0.set("Ethan", 5.9);
    std::cout << d0 << std::endl;

    // Testing get functions
    std::cout << "Anne value: " << d0.get("Anne") << '\n'; // prints 5
    std::cout << "Josh value: " << d0.get("Josh") << '\n'; // prints 5.5

    // testing set
    std::cout << "Setting Josh to 5.0" << '\n';
    d0.set("Josh", 5.0);
    std::cout << "Josh value: " << d0.get("Josh") << '\n'; // prints 5

    // KeyError
    std::cout << '\n' << "Trying to access Batman..." << '\n';
    try
    {
        d0.get("Batman");
    }
    catch (KeyError&)
    {
        std::cout << "KeyError caught" << '\n';
    }

    std::cout << '\n' << "Removing Anne..." << '\n';
    d0.remove("Anne");

    std::cout << "Trying to accesse Anne" << '\n';
    try
    {
        d0.get("Anne");
    }
    catch (KeyError&)
    {
        std::cout << "KeyError caught" << '\n';
    }

    std::cout << '\n' << "Removing Dawn..." << '\n';
    try
    {
        d0.remove("Dawn");
    }
    catch (KeyError&)
    {
        std::cout << "Remove error caught" << '\n';
    }

    // Collision testing
    std::cout << '\n' << "Creating d2" << '\n';
    HT d2(2);

    d2.set("A", 1);
    d2.set("B", 2);
    d2.set("C", 3);
    d2.set("D", 4);

    std::cout << d2.get("A") << '\n';         // prints 1
    std::cout << d2.get("D") << '\n' << '\n'; // prints 4

    std::vector<std::string> keys = d2.keys();

    for (int i = 0; i < keys.size(); ++i)
    {
        std::cout << keys[i] << '\n';
    }

    std::cout << "Clearing d2" << '\n';
    d2.clear();

    try
    {
        d2.get("A");
    }
    catch (KeyError&)
    {
        std::cout << "Clear worked" << std::endl;
    }

    // Forcing resize trigger
    std::cout << '\n' << "Testing resize" << '\n';
    HT d3(2, 0.1); // low tolerance

    d3.set("A", 1);
    d3.set("B", 2);
    d3.set("C", 3);

    // Force lots of gets
    for (int i = 0; i < 20; i++)
    {
        try { d3.get("A"); } catch(KeyError&) { std::cout << "Something is wrong"; }
        try { d3.get("B"); } catch(KeyError&) { std::cout << "Something is wrong"; }
    }

    std::cout << d3.get("A") << '\n'; // prints 1
    std::cout << d3.get("B") << '\n'; // prints 2
    std::cout << d3.get("C") << '\n'; // prints 3

    HT d4(5);

    std::cout << "Stress Test" << '\n';

    for (int i = 0; i < 100; i++)
    {
        d4.set("key" + std::to_string(i), i * 1.0);
    }

    for (int i = 0; i < 100; i++)
    {
        std::cout << d4.get("key" + std::to_string(i)) << '\n';
    }
    
    return 0;
}

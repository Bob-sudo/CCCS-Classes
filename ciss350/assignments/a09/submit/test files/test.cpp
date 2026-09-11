#include <iostream>
#include <list>
#include <vector>
//-----------------------------------------------------------------------------
// An iterator is like a pointer. STL container classes can give you
// iterators. The point of iterator objects is to allow you to traverse
// the container using operator()++ and access the value by de-referencing.
//
// To get an iterator that points to the first value in the container, you do
// this:
//
//    std::list< int >::iterator p = list.begin();
//
// In the code below, because there's a template parameter, C++ will ask you
// to put "typename" before the declaration. So you have to do this:
//
//    typename std::list< int >::iterator p = list.begin();
//
// Make sure you remove "typename" below and compile the code to see the
// error message.
//
// You can compare your iterator p against the "end-of-list" doing this:
//
//    p != list.end()
//
// (You can think of list.end() as returning the pointer value just beyond
// the last value in the container.)
//
// The following therefore allows you to traverse the std::list, xs, printing
// its values:
//
//    for (typename std::list< int >::iterator p = xs.begin();
//        p != xs.end();
//        p++)
//    {
//        std::cout << (*p) << ' ';
//    }
//
// If the list xs is constant, then you need to use a constant iterator
// (which cannot modify the value that it points to):
//
//    for (typename std::list< int >::const_iterator p = xs.begin();
//        p != xs.end();
//        p++)
//    {
//        std::cout << (*p) << ' ';
//    }
//
// Make sure you change the iterator below to a non-constant iterator,
// compile your code and see the error message returned by the compiler.
//
// The loop in the template operator below is very standard when working
// with STL containers. Make sure you study it carefully.
//
// The code to print the values in a std::vector class is exactly the same.
// So if v is a std::vector<int> object, this prints the values in v:
//
//    for (typename std::vector< int >::const_iterator p = v.begin();
//        p != v.end();
//        p++)
//    {
//        std::cout << (*p) << ' ';
//    }
//-----------------------------------------------------------------------------
template <typename T >
std::ostream & operator<<(std::ostream & cout, const std::list< T > & list)
{
    for (typename std::list< T >::const_iterator p = list.begin();
         p != list.end();
         p++)
    {
        cout << (*p) << ' ';
    }
    return cout;
}

int main()
{
    std::list< int > list;
    
    list.push_back(5);
    std::cout << list << std::endl;
    
    list.push_back(3);
    std::cout << list << std::endl;
    
    list.push_back(7);
    std::cout << list << std::endl;
    
    list.push_front(0);
    std::cout << list << std::endl;
    
    list.push_front(3);
    std::cout << list << std::endl;
    std::cout << "front: " << list.front() << std::endl;
    std::cout << "back: " << list.back() << std::endl;
    
    list.front() = -999;
    list.back() = 999;
    std::cout << list << std::endl;
    
    std::cout << "size: " << list.size() << '\n';
    std::cout << "empty?: " << list.empty() << '\n';
    
    list.pop_front();
    std::cout << list << std::endl;
    
    list.pop_back();
    std::cout << list << std::endl;
    std::cout << list << std::endl;
    
    list.clear();
    std::cout << list.size() << std::endl;
    
    return 0;
}

#include "Set.h"

int main()
{
    Set<HashableString> s1;
    Set<HashableString> s2;

    s1.insert(HashableString("A"));
    s1.insert(HashableString("B"));
    s1.insert(HashableString("C"));
    std::cout << "S1: " << s1 << '\n';

    s2.insert(HashableString("A"));
    s2.insert(HashableString("B"));
    s2.insert(HashableString("C"));
    std::cout << "S2: " << s2 << '\n';

    std::cout << (s1 <= s2) << '\n'; // true
    std::cout << (s2 >= s1) << '\n'; // true
    std::cout << (s1 == s2) << '\n'; // true

    s1.remove(HashableString("A"));
    std::cout << "S1.remove(A)..." << '\n';
    std::cout << s1 << '\n';

    std::cout << (s1 <= s2) << '\n'; // true
    std::cout << (s2 >= s1) << '\n'; // true
    std::cout << (s1 == s2) << '\n'; // false

    std::cout << s1.has_element(HashableString("A")) << '\n';      // false
    std::cout << s1.has_element(HashableString("C")) << '\n'; // true
    
    return 0;
}

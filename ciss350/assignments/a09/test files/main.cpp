#include <iostream>
#include <fstream>

int main()
{
    std::ifstream f;
    f.open("output.txt");
    std::string s;
    char t[100];
    int i;
    double d;
    bool b;
    f >> s;
    std::cout << s << '\n';
    f >> t;
    std::cout << t << '\n';
    f >> i;;
    std::cout << i << '\n';
    f >> d;
    std::cout << d << '\n';
    f >> b;
    std::cout << b << '\n';
    f.close();
    
    return 0;
}

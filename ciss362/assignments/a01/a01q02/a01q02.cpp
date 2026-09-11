#include <iostream>
#include <vector>
#include <string>

std::vector<int> stringtovec(std::string s)
{
    std::vector<int> num;
    int n = s.length();

    for(int i = 0; i < n; ++i)
    {
        if(s[i] != ' ')
            num.push_back(s[i] - 48);
    }

    return num;
}

std::vector< int > Delta(std::vector< int > X)
{
    return X;
}

int main()
{
    std::string n;
    
    std::getline(std::cin, n);

    std::vector<int> X = stringtovec(n);

    for(int i = 0; i < X.size(); i++)
    {
        std::cout << X[i] << ' ';
    }
    std::cout << '\n';
}

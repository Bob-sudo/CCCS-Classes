//File: a06q05.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    double xa, xb, h1, w1, xc, xd, w2, h2;
    std::cin >> xa >> xb >> w1 >> h1 >> xc  >> xd >> w2 >> h2;
    bool overlap = false;

    h1 += xb;
    w1 += xa;
    h2 += xd;
    w2 += xc;
    
    if(xa >= xc && xa <= w2|| w1 >= xc && w1 <= w2)
    {
        if(h1 >= xd && h1 <= h2 || xb >= xd && xb <= h2)
        {
            overlap = true;
        }
    }

    std::cout << overlap << '\n';

    return 0;
}

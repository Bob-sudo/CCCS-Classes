//File: a08q05.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{   
    for(int j = 276951438; j < 1000000000; j++)
    {
        bool is_magic_num = false;
        
        int a = j /  100000000,
            b = (j / 10000000) % 10,
            c = (j / 1000000) % 10,
            d = (j / 100000) % 10,
            e = (j / 10000) % 10,
            f = (j / 1000) % 10,
            g = (j / 100) % 10,
            h = (j/ 10) % 10,
            i = j % 10;

        if(a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i)
        {
            if(b != c && b != d && b != e && b != f && b != g && b != h && b != i)
            {
                if(c != d && c != e && c != f && c != g && c != h && c != i)
                {
                    if(d != e && d != f && d != g && d != h && d != i)
                    {
                        if(e != f && e != g && e != h && e != i)
                        {
                            if(f != g && f != h && f != i)
                            {
                                if(g != h && g != i)
                                {
                                    if(h != i)
                                    {
                                        if(a + b + c == 15 && d + e + f == 15 && g + h + i == 15)
                                        {
                                            if(a + d + g == 15 && b + e + h == 15 && c + f + i == 15)
                                            {
                                                if(a + e + i == 15 && c + e + g == 15)
                                                {
                                                    std::cout << "+-+-+-+" << '\n'
                                                              << '|' << a << '|' << b << '|' << c << '|' << '\n'
                                                              << "+-+-+-+" << '\n'
                                                              << '|' << d << '|' << e << '|' << f << '|' << '\n'
                                                              << "+-+-+-+" << '\n'
                                                              << '|' << g << '|' << h << '|' << i << '|' << '\n'
                                                              << "+-+-+-+" << '\n';
                                                }
                                            }
                                        }  
                                    }
                                }
                            }
                        }
                            
                    }
                }
            }  
        }
    }       
    return 0; 
}

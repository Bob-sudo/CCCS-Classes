#include <iostream>
#include "date.h"

int main()
{
    Date random;
    Date today(2025, 2, 20); // calls Date::Date(int,int,int)
    Date yesterday = Date(2025, 2, 19);
    Date * nextyear = new Date(2026, 2, 20);

    Date clone_today(today);
    std::cout << "today:" << today << '\n';
    std::cout << "clone_today:" << clone_today << '\n';
    
    // Date lastmonth(); <<<< DONT DO THIS!!!
    //today.init(2025, 2, 20);
    //today.print();
    // prefer
    std::cout << today << '\n';
    // basically same as
    // operator<<(std::cout, today) << '\n';
    
    //yesterday.init(2025, 2, 19);
    //yesterday.print();
    std::cout << yesterday << '\n';
    
    std::cout << "inc today's yr by 1 ...\n";
    today.add_y(1);
    //today.print();
    std::cout << today << '\n';
    //std::cout << today.yyyy_ << '\n';

    std::cout << "inc yesterday's m and d by 2 and 3 ...\n";
    yesterday.add_m(2);
    yesterday.add_d(3);
    //yesterday.print();
    std::cout << yesterday << '\n';
    
    today.add_m_d(5, 6);
    //today.print();
    std::cout << today << '\n';
    
    if (today.equal(yesterday))
    {
        std::cout << "equal\n";
    }
    else
    {
        std::cout << "not equal\n";
    }
    if (today == yesterday) // today.operator==(yesterday)
    {
        std::cout << "equal\n";
    }
    else
    {
        std::cout << "not equal\n";
    }

    std::cout << &yesterday << '\n';
    Date nextmonth(2026, 2, 24);
    nextmonth = yesterday = today;
    // same as
    // yesterday.operator=(today);
    std::cout << yesterday << '\n';
    std::cout << nextmonth << '\n';

    // int i, j, k;
    // i = j = k = 42;
    // std::cout << i << ' ' << j << ' ' << k << '\n';
    return 0;
}

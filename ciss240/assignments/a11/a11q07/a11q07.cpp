//File: a11q08.cpp
//Name: Ethan Graham

#include <iostream>
#include <iomanip>

int main()
{
    const int SIZE = 100; 
    int intArr[SIZE] = {0};
    double doubleArr[SIZE] = {0.0};
    int arrSize = 0; // Current size of arrays

    while (arrSize < SIZE)
    {
        int integerValue;
        double doubleValue;

        std::cin >> integerValue;
        if (integerValue == -1)
        {
            break;
        }

        std::cin >> doubleValue;
        intArr[arrSize] = integerValue;
        doubleArr[arrSize] = doubleValue;
        arrSize++;
    }

    //Bubble Sort
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (doubleArr[j] > doubleArr[j + 1])
            {

                double tempD = doubleArr[j];
                doubleArr[j] = doubleArr[j + 1];
                doubleArr[j + 1] = tempD;

                int tempI = intArr[j];
                intArr[j] = intArr[j + 1];
                intArr[j + 1] = tempI;
            }
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        std::cout << intArr[i] << " " << doubleArr[i] << "\n";
    }

    return 0;
}

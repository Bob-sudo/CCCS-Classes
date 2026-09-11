//File: a11q01.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    const int size = 10;
    int arr[size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, index, value;


    while(index != -1)
    {
       std::cout << "index and new value: ";
       std::cin >> index;

       if(index == -1)
       {
           break;
       }
       
       std::cin >> value;
       
       arr[index] = value;

       std::cout << "array: ";
       for(int i = 0; i < size; i++)
       {
           std::cout << arr[i] << ' ';
       }
       std::cout << '\n';
 
    }
    
    return 0;    
}

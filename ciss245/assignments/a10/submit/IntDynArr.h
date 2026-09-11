#ifndef INTDYNARR_H
#define INTDYNARR_H
#include <iostream>


class IntDynArr
{
  public: 
    IntDynArr(int capacity0 = 5);
    IntDynArr(int size0, int a[]);
    IntDynArr(const IntDynArr&);
    ~IntDynArr();
    int get_size() const;
    int get_capacity() const;
    bool operator==(const IntDynArr & arr) const;
    bool operator!=(const IntDynArr & arr) const;
    IntDynArr & operator=(const IntDynArr & arr);
    friend std::ostream & operator<<(std::ostream &, const IntDynArr & a);
    friend std::istream & operator>>(std::istream &, IntDynArr & a);
    void resize(const int size0);
    int operator[](int i) const; 
    int & operator[](int i);
    IntDynArr & operator+=(const IntDynArr & a);
    IntDynArr operator+(const IntDynArr & a) const;
    IntDynArr & insert(int index, int val);
    IntDynArr & remove(int index);
    IntDynArr subarray(int index, int length = -1);
    void print() const; 
  private:
    int * x;    
    int size;
    int capacity;
};

#endif 

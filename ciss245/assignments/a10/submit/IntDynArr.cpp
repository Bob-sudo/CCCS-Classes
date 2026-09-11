#include "IntDynArr.h"
#include <iostream>

IntDynArr::IntDynArr(int capacity0)
{
    if (capacity0 < 1) capacity0 = 1;
    capacity = capacity0;
    size = 0;
    x = new int[capacity];
}

IntDynArr::IntDynArr(int size0, int a[])
{
    if (size0 < 0) size0 = 0;
    size = size0;
    capacity = size0;
    x = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        x[i] = a[i];
    }
}

IntDynArr::IntDynArr(const IntDynArr & other)
{
    size = other.size;
    capacity = other.capacity;
    x = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        x[i] = other.x[i];
    }
}

IntDynArr::~IntDynArr()
{
    delete[] x;
}

int IntDynArr::get_size() const { return size; }
int IntDynArr::get_capacity() const { return capacity; }

bool IntDynArr::operator==(const IntDynArr& arr) const
{
    if (size != arr.size) return false;
    for (int i = 0; i < size; i++)
    {
        if (x[i] != arr.x[i]) return false;
    }
    return true;
}

bool IntDynArr::operator!=(const IntDynArr& arr) const
{
    return !(*this == arr);
}

IntDynArr & IntDynArr::operator=(const IntDynArr & arr)
{
    if (this == &arr) return *this;

    delete[]x;
    size = arr.size;
    capacity = arr.capacity;
    x = new int[capacity];

    for(int i = 0; i < size; i++)
    {
        x[i] = arr.x[i];
    }
    return *this;
}

std::ostream & operator<<(std::ostream& cout, const IntDynArr& a)
{
    cout << "[";
    for (int i = 0; i < a.size; i++)
    {
        cout << a.x[i];
        if (i != a.size - 1) cout << ", ";
    }
    cout << "]";
    return cout;
}

std::istream & operator>>(std::istream& cin, IntDynArr& a)
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.x[i];
    }
    return cin;
}

void IntDynArr::resize(const int size0)
{
    if (size0 < 0) return;

    if (size0 <= capacity)
    {
        size = size0;
        return;
    }

    int newCap = (2 * capacity > size0) ? 2 * capacity : size0;
    if (newCap < 1) newCap = 1;

    int* newX = new int[newCap];
    for (int i = 0; i < size; i++)
    {
        newX[i] = x[i];
    }
    delete[] x;
    x = newX;
    capacity = newCap;
    size = size0;
}

int IntDynArr::operator[](int i ) const
{
    if (i < 0 || i >= size)
    {
        std::cout << "Index out of bounds\n";
        return x[0]; // fallback
    }
    return x[i];
}

int& IntDynArr::operator[](int i)
{
    if (i < 0 || i >= size)
    {
        std::cout << "Index out of bounds\n";
        return x[0]; // fallback
    }
    return x[i];
}

IntDynArr& IntDynArr::operator+=(const IntDynArr& a)
{
    int oldSize = size;
    resize(size + a.size);
    for (int i = 0; i < a.size; i++)
    {
        x[oldSize + i] = a.x[i];
    }
    return *this;
}

IntDynArr IntDynArr::operator+(const IntDynArr& a) const
{
    IntDynArr result(size + a.size);
    for (int i = 0; i < size; i++)
    {
        result.x[i] = x[i];
    }
    for (int i = 0; i < a.size; i++)
    {
        result.x[size + i] = a.x[i];
    }
    result.size = size + a.size;
    return result;
}

IntDynArr& IntDynArr::insert(int index, int val)
{
    if (index < 0 || index > size)
    {
        std::cout << "Insert index out of range\n";
        return *this;
    }

    if (size >= capacity) resize(size + 1);
    else size++;

    for (int i = size - 1; i > index; i--)
    {
        x[i] = x[i - 1];
    }
    x[index] = val;
    return *this;
}

IntDynArr& IntDynArr::remove(int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Remove index out of range" << '\n';
        return *this;
    }

    for (int i = index; i < size - 1; i++)
    {
        x[i] = x[i + 1];
    }
    size--;
    return *this;
}

IntDynArr IntDynArr::subarray(int index, int length)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Subarray start index out of range\n";
        return IntDynArr();
    }

    if (length == -1 || index + length > size) length = size - index;

    IntDynArr result(length);
    for (int i = 0; i < length; i++)
    {
        result.x[i] = x[index + i];
    }
    result.size = length;
    return result;
}

void IntDynArr::print() const
{
    std::cout << *this << std::endl;
}

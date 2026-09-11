#ifndef INTMAXHEAP_H
#define INTMAXHEAP_H

#include <iostream>
#include <vector>

class IntMaxHeap
{
  public:
    void maxheap_insert(int);
    int maxheap_delete(); // extract root
    
    void maxheap_heapify_up(int);
    void maxheap_heapify_down(int);

    int maxheap_max() const;

    int size() const;
    void resize(int);

    void maxheap_build();

    void maxheap_heapsort();

    int& operator[](int);
    const int& operator[](int) const;

    friend std::ostream& operator<<(std::ostream& cout, const IntMaxHeap& h)
    {
        cout << '[';
        for(int i = 0; i < h.size(); i++)
        {
            cout << h.heap[i];
            if(i != h.size() - 1)
                cout << ", ";
        }
        cout << ']';
        return cout;
    }
    
  private:
    std::vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
};

#endif

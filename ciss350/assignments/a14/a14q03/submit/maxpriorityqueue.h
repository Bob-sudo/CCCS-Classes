#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include "maxheap.h"
#include "maxheap_value.h"
#include <vector>
#include <iostream>

template <typename T>
class MaxPriorityQueue
{
  public:
    MaxPriorityQueue()
    {}

    MaxPriorityQueue(const MaxPriorityQueue& other)
    {
        heap = other.heap;
    }

    void insert(const T& value)
    {
        maxheap_insert(heap, value);
    }

    T remove()
    {
        if(heap.empty())
            throw T();

        return maxheap_delete(heap);
    }

    T& max()
    {
        if(heap.empty())
            throw T();

        return heap[0];
    }

    const T& max() const
    {
        if(heap.empty())
            throw T();

        return heap[0];
    }

    void clear()
    {
        heap.clear();
    }

    int size() const
    {
        return heap.size();
    }

    bool is_empty() const
    {
        return heap.empty();
    }

    MaxPriorityQueue& operator=(const MaxPriorityQueue& other)
    {
        if(this != &other) heap = other.heap;
        return *this;
    }

    bool operator==(const MaxPriorityQueue& other) const
    {
        return heap == other.heap;
    }
    
    friend std::ostream & operator<<(std::ostream & cout,
                                     const MaxPriorityQueue & x)
    {
        for(int i = 0; i < x.heap.size(); i++)
        {
            cout << x.heap[i] << ' ';
        }
        return cout;
    }

  private:
    std::vector<T> heap;
};

#endif

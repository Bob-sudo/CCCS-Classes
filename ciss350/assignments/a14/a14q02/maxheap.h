#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <algorithm>

template < typename T >
int parent(int i)
{
    return (i - 1) / 2;
}

template < typename T >
int left(int i)
{
    return 2 * i + 1;
}

template < typename T >
int right(int i)
{
    return 2 * i + 2;
}

template < typename T >
void maxheap_insert(std::vector<T>& heap, const T& x)
{
    heap.push_back(x);
    maxheap_heapify_up(heap, heap.size() - 1);
}

template < typename T >
T maxheap_delete(std::vector<T>& heap)
{
    if(heap.empty()) throw T();
    
    T ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    if(!heap.empty())
        maxheap_heapify_down(heap, 0);

    return ret;
}

template < typename T >
void maxheap_heapify_up(std::vector<T>& heap, int i)
{
    
    while(i > 0 && heap[i] > heap[parent<T>(i)])
    {
        std::swap(heap[i], heap[parent<T>(i)]);
        i = parent<T>(i);
    }
}

template < typename T >
void maxheap_heapify_down(std::vector<T>& heap, int i)
{
    int largest = i;
    int l = left<T>(i);
    int r = right<T>(i);
    
    if(l < heap.size() && heap[l] > heap[largest])
        largest = l;
    if(r < heap.size() && heap[r] > heap[largest])
        largest = r;

    if(largest != i)
    {
        std::swap(heap[i], heap[largest]);
        maxheap_heapify_down(heap, largest);
    }
}

template < typename T >
T maxheap_max(const std::vector<T>& heap)
{
    return heap.empty() ? T() : heap[0];
}

template < typename T >
void resize(std::vector<T>& heap, int i)
{
    heap.resize(i);
}

template < typename T >
void maxheap_build(std::vector<T>& heap)
{
    for(int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        maxheap_heapify_down(heap, i);
    }
}

template < typename T >
void maxheap_heapsort(std::vector<T>& heap)
{
    maxheap_build(heap);

    for(int i = heap.size() - 1; i > 0; i--)
    {
        std::swap(heap[0], heap[i]);

        int size = i;
        int index = 0;
        while(1)
        {
            int largest = index;
            int l = left<T>(index);
            int r = right<T>(index);
    
            if(l < size && heap[l] > heap[largest])
                largest = l;
            if(r < size && heap[r] > heap[largest])
                largest = r;

            if(largest == index)
                break;

            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }
}

#endif

#include "intmaxheap.h"
#include <algorithm>

void IntMaxHeap::maxheap_insert(int i)
{
    heap.push_back(i);
    maxheap_heapify_up(heap.size() - 1);
}

int IntMaxHeap::maxheap_delete()
{
    if(heap.empty()) return -1;
    
    int ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    if(!heap.empty())
        maxheap_heapify_down(0);

    return ret;
}

void IntMaxHeap::maxheap_heapify_up(int i)
{
    while(i > 0 && heap[i] > heap[parent(i)])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void IntMaxHeap::maxheap_heapify_down(int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);
    
    if(l < heap.size() && heap[l] > heap[largest])
        largest = l;
    if(r < heap.size() && heap[r] > heap[largest])
        largest = r;

    if(largest != i)
    {
        std::swap(heap[i], heap[largest]);
        maxheap_heapify_down(largest);
    }
}

int IntMaxHeap::maxheap_max() const
{
    return heap.empty() ? -1 : heap[0];
}

int IntMaxHeap::size() const
{
    return heap.size();
}

void IntMaxHeap::resize(int i)
{
    heap.resize(i);
}

void IntMaxHeap::maxheap_build()
{
    for(int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        maxheap_heapify_down(i);
    }
}

void IntMaxHeap::maxheap_heapsort()
{
    maxheap_build();

    for(int i = heap.size() - 1; i > 0; i--)
    {
        std::swap(heap[0], heap[i]);

        int size = i;
        int index = 0;
        while(1)
        {
            int largest = index;
            int l = left(index);
            int r = right(index);
    
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

int& IntMaxHeap::operator[](int index)
{
    return heap[index];
}

const int& IntMaxHeap::operator[](int index) const
{
    return heap[index];
}

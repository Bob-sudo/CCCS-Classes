#include <iostream>
#include "intmaxheap.h"

int main()
{
    IntMaxHeap heap;
    heap.maxheap_insert(5);
    heap.maxheap_insert(7);
    heap.maxheap_insert(9);

    std::cout << heap << '\n';

    int a = heap.maxheap_delete();

    std::cout << "Root Extracted: " << a << '\n';
    std::cout << "Heap: " << heap << '\n';

    int x = heap.maxheap_max();

    std::cout << "MaxHeap Max: " << x << '\n';

    heap[0] = 1;
    std::cout << heap << '\n';
    std::cout << "Heapify down..." << '\n';
    heap.maxheap_heapify_down(0);
    std::cout << heap << '\n';

    heap[1] = 10;
    std::cout << heap << '\n';
    std::cout << "Heapify up..." << '\n';
    heap.maxheap_heapify_up(1);
    std::cout << heap << '\n';

    
    heap.resize(5);
    heap[0] = 5;
    heap[1] = 7;
    heap[2] = 8;
    heap[3] = 10;
    heap[4] = 2;
    std::cout << '\n' << "Heap: " << heap << '\n';
    std::cout << "Rebuilding heap:" << '\n';
    heap.maxheap_build();
    std::cout << "Heap: " << heap << '\n';

    heap.resize(5);
    heap[0] = 2;
    heap[1] = 6;
    heap[2] = 8;
    heap[3] = 10;
    heap[4] = 5;

    std::cout << '\n' << "Rebuilding and performing heapsort..." << '\n';
    heap.maxheap_heapsort(); // [2, 5, 6, 8, 10]
    std::cout << heap << std::endl; // prints "[2, 5, 6, 8, 10]"
    
    return 0;
}

#include "maxheap.h"
#include "maxheap_value.h"

int main()
{
    maxheap_value x;
    std::vector< maxheap_value > heap;
    maxheap_insert(heap, maxheap_value(5, "a")); // [<5, "a">]
    maxheap_insert(heap, maxheap_value(7, "b")); // [<7, "b">, <5, "a">]
    maxheap_insert(heap, maxheap_value(9, "c")); // [<9, "c">, <5, "a">, <7, "b">]
    
    for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';
    
    maxheap_value a = maxheap_delete(heap); // [<7, "b">, <5, "a">]
                                            // a = <9, "c">

    std::cout << a << '\n';
    for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';
    
    x = maxheap_max(heap);
    std::cout << x << '\n';
    
    heap[0] = maxheap_value(1, "d"); // [<1, "d">, <5, "a">]
    maxheap_heapify_down(heap, 0); // [<5, "a">, <1, "d">]
    heap[1] = maxheap_value(10, "e"); // [<5, "a">, <10, "e">]
    maxheap_heapify_up(heap, 1); // [<10, "e">, <5, "a">]

    for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';

    heap.resize(5);

    heap[0] = maxheap_value(5, "a");
    heap[1] = maxheap_value(7, "b");
    heap[2] = maxheap_value(8, "c");
    heap[3] = maxheap_value(10, "d");
    heap[4] = maxheap_value(2, "e");

    std::cout << "Rebuilding heap: " << '\n';
    maxheap_build(heap);

    for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Heap sort:" << '\n';

    heap.resize(5);

    heap[0] = maxheap_value(7, "a");
    heap[1] = maxheap_value(6, "b");
    heap[2] = maxheap_value(8, "c");
    heap[3] = maxheap_value(10, "d");
    heap[4] = maxheap_value(5, "e");
    
    std::cout << "Unsorted:";
     for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';

    maxheap_heapsort(heap);
    std::cout << "Sorted:";
     for(int i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i] << ' ';
    }
    std::cout << '\n';   
    
    return 0;
}

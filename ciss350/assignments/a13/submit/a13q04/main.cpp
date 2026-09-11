#include "Set.h"
#include "BinarySearchTree.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

int main(int argc, char * argv[])
{
    srand((unsigned int) time(NULL));
    const int N = std::stoi(argv[1]);

    BinarySearchTree bst;
    Set<HashableString> s;

    // SET

    for (int i = 0; i < N; i++)
    {
        s.insert(HashableString("key" + std::to_string(i)));
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        int find = rand() % N;
        s.has_element(HashableString("key" + std::to_string(find)));
    }

    auto end = std::chrono::high_resolution_clock::now();

    double time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Set time: " << time << '\n';

    // BST

    for (int i = 0; i < N; i++)
    {
        bst.insert(i);
    }

    auto start2 = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 1000; i++)
    {
        int find = rand() % N;
        bst.find(find);
    }

    auto end2 = std::chrono::high_resolution_clock::now();

    double time2 = std::chrono::duration<double, std::milli>(end2 - start2).count();
    std::cout << "BST time: " << time2 << '\n';
}

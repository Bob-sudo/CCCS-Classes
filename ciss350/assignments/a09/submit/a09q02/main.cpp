#include "TreeNodev.h"
#include <iostream>
#include <string>

bool is_magic_square(const std::vector<int>& p, int n)
{
    int magic_sum = n * (n * n + 1) / 2;

    // Rows
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += p[i*n + j];
        }
        if (sum != magic_sum)
            return false;
    }

    // Column
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += p[i + j*n];
        }
        if (sum != magic_sum)
            return false;
    }

    // Diagonal
    int diag_sum = 0;
    for (int i = 0; i < n; i++)
        diag_sum += p[i*n + i];

    if (diag_sum != magic_sum)
        return false;

    // other diagonal
    diag_sum = 0;
    for (int i = 0; i < n; i++)
        diag_sum += p[i*n + (n-1-i)];

    if (diag_sum != magic_sum)
        return false;

    return true;
}

void print(const std::vector<int>& p, int n)
{
    std::cout << '\n' << "Magic Square:" << '\n';

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << p[i*n + j] << ' ';
        }
        std::cout << '\n';
    }
}

void build(TreeNodev<Data>* node, long long & count, int n)
{
    Data temp = node->get_key();

    if(temp.available.empty())
    {
        count++;
        
        if(is_magic_square(temp.permutation, n))
        {
            print(temp.permutation, n);
        }
        return;
    }

    for(size_t i = 0; i < temp.available.size(); i++)
    {
        Data next;

        next.permutation = temp.permutation;
        next.permutation.push_back(temp.available[i]);

        next.available = temp.available;
        next.available.erase(next.available.begin() + i);

        node->insert(node->num_children(), next);
        TreeNodev<Data>* child = node->child(node->num_children() - 1);

        build(child, count, n);
    }
}



int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    long long count = 0;
    
    Data start;
    start.permutation = {};

    for(int i = 1; i <= n * n; i++)
    {
        start.available.push_back(i);
    }

    TreeNodev<Data> root(start);

    build(&root, count, n);

    std::cout << "Number of Permutations: " << count << '\n';

    return 0;
}

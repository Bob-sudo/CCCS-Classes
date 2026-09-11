#include <vector>
#include <iostream>

bool isSafe(int node, int c, const std::vector<int>& color,
            const std::vector<std::vector<int>>& graph)
{
    for (int neighbor : graph[node])
    {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

bool colorNode(int node, std::vector<int>& color,
               int maxColors,
               const std::vector<std::vector<int>>& graph)
{
    if(node == graph.size())
        return true;

    for (int c = 0; c < maxColors; c++)
    {
        if (isSafe(node, c, color, graph))
        {
            color[node] = c;

            if (colorNode(node + 1, color, maxColors, graph))
                return true;

            color[node] = -1; // backtrack
        }
    }
    
    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);

    while (true)
    {
        int u;
        std::cin >> u;
        if (u == -1) break;

        int v;
        std::cin >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<int> color(n, -1);

    for (int maxColors = 1; maxColors <= n; maxColors++)
    {
        for(int i = 0; i < n; i++)
            color[i] = -1;

        if (colorNode(0, color, maxColors, graph))
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << i << ":" << color[i];
                if (i < n - 1) std::cout << " ";
            }
            std::cout << '\n';

            break; // found minimum coloring
        }
    }
    
    return 0;
}

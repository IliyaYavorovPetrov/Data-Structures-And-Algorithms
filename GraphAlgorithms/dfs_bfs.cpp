#include <bits/stdc++.h>

// WORST: O(V + E)
void dfs(std::unordered_map<int, std::vector<int>> &adj, std::unordered_map<int, bool> &visited, int curr)
{
    printf("%d\n", curr);
    visited[curr] = true;

    for (auto &&neighbour : adj[curr])
    {
        if (!visited[neighbour])
        {
            dfs(adj, visited, neighbour);
        }
    }
}

// WORST: O(V + E)
void bfs(std::unordered_map<int, std::vector<int>> &adj, int curr)
{
    std::unordered_map<int, bool> visited;
    std::list<int> nextToProcess;

    visited[curr] = true;
    nextToProcess.push_back(curr);

    while (!nextToProcess.empty())
    {
        curr = nextToProcess.front();
        printf("%d\n", curr);
        nextToProcess.pop_front();

        for (auto &&neighbour : adj[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                nextToProcess.push_back(neighbour);
            }
        }
    }
}

int main() 
{
    // DFS
    {
        std::unordered_map<int, bool> visited;
        std::unordered_map<int, std::vector<int>> adj;

        // If graph is undirected will add to both directions in adj.
        // This is true for all graph algorithms below.
        auto add = [&adj](int a, int b)
        {
            adj[a].push_back(b);
            // adj[b].push_back(a);
        };

        add(0, 1);
        add(0, 2);
        add(1, 2);
        add(2, 0);
        add(2, 3);
        add(3, 3);

        printf("DFS\n");
        dfs(adj, visited, 2);
    }

    // BFS
    {
        std::unordered_map<int, std::vector<int>> adj;

        auto add = [&adj](int a, int b)
        {
            adj[a].push_back(b);
        };

        add(0, 1);
        add(0, 2);
        add(1, 2);
        add(2, 0);
        add(2, 3);
        add(3, 3);

        printf("BFS\n");
        bfs(adj, 2);
    }
}
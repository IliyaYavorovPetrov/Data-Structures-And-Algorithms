#include <bits/stdc++.h>

// WORST: O(E*LOGV)
// FIND SHORTEST PATH IN UNWEIGHTED GRAPH
std::unordered_map<int, int> bfs(std::unordered_map<int, std::vector<int>> &adj, int curr)
{
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> distance;

    // GET PATH
    std::unordered_map<int, std::list<int>> paths;

    for (auto elem : adj)
    {
        visited[elem.first] = false;
        distance[elem.first] = INT_MAX;

        // GET PATH
        paths[elem.first] = std::list<int>();
    }

    distance[curr] = 0;
    std::queue<int> next;
    next.push(curr);

    while (!next.empty())
    {
        auto temp = next.front();
        next.pop();

        if (visited[temp])
        {
            continue;
        }
        visited[temp] = true;

        for (auto x : adj[temp])
        {
            int neighbour = x;
            int dist = distance[temp] + 1;
            if (distance[neighbour] > dist)
            {
                distance[neighbour] = dist;
                next.push(neighbour);

                // GET PATH
                if (!paths[neighbour].empty())
                {
                    paths[neighbour].clear();
                    paths[neighbour] = paths[temp];
                }
            }
            // GET PATH
            if (!visited[neighbour])
            {
                paths[neighbour].push_back(temp);
            }
        }
    }

    return distance;
}

// (Dijikstra) Custom Compare Priority Queue
class Compare
{
public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b)
    {
        if (a.second < b.second)
        {
            return false;
        }

        return true;
    }
};

// WORST: O(E*LOGV)
// FIND SHORTEST PATH IN WEIGHTED GRAPH
std::unordered_map<int, int> dijikstra(std::unordered_map<int, std::vector<std::pair<int, int>>> &adj, int curr)
{
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> distance;

    // GET PATH
    std::unordered_map<int, std::list<int>> paths;

    for (auto elem : adj)
    {
        visited[elem.first] = false;
        distance[elem.first] = INT_MAX;

        // GET PATH
        paths[elem.first] = std::list<int>();
    }

    distance[curr] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> next;
    next.push({curr, 0});

    while (!next.empty())
    {
        auto temp = next.top();
        next.pop();

        if (visited[temp.first])
        {
            continue;
        }
        visited[temp.first] = true;

        for (auto x : adj[temp.first])
        {
            int neighbour = x.first;
            int dist = distance[temp.first] + x.second;
            if (distance[neighbour] > dist)
            {
                distance[neighbour] = dist;
                next.push(x);

                // GET PATH
                if (!paths[neighbour].empty())
                {
                    paths[neighbour].clear();
                    paths[neighbour] = paths[neighbour];
                }
            }
            // GET PATH
            if (!visited[neighbour])
            {
                paths[neighbour].push_back(temp.first);
            }
        }
    }

    return distance;
}

int main()
{
    // BFS
    {
        std::unordered_map<int, std::vector<int>> adj;
        adj[0].push_back(1);
        adj[1].push_back(0);
        adj[0].push_back(3);
        adj[3].push_back(0);
        adj[1].push_back(2);
        adj[2].push_back(1);
        adj[1].push_back(3);
        adj[3].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(2);

        auto result = bfs(adj, 0);
        printf("BFS\n");
        for (auto x : result)
        {
            printf("%d: %d\n", x.first, x.second);
        }
    }

    // Dijkstra
    {
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        adj[1].push_back({2, 24});
        adj[2].push_back({1, 24});
        adj[1].push_back({4, 20});
        adj[4].push_back({1, 20});
        adj[3].push_back({1, 3});
        adj[1].push_back({3, 3});
        adj[4].push_back({3, 12});
        adj[3].push_back({4, 12});

        auto result = dijikstra(adj, 1);
        printf("Dijkstra\n");
        for (auto x : result)
        {
            printf("%d: %d\n", x.first, x.second);
        }
    }

    return 0;
}
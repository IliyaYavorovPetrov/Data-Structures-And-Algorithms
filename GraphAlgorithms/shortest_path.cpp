#include <bits/stdc++.h>

typedef std::unordered_map<int, std::vector<int>> adj_bfs;
typedef std::unordered_map<int, bool> m_vis_bfs;
typedef std::unordered_map<int, int> m_dist_bfs;
typedef std::unordered_map<int, std::list<int>> m_paths_bfs;
typedef std::unordered_map<int, std::pair<int, std::list<int>>> output_bfs;

// WORST: O(E*LOGV)
// FIND SHORTEST PATH IN UNWEIGHTED GRAPH
output_bfs bfs(adj_bfs adj, int curr)
{
    if (adj.empty())
    {
        return output_bfs();
    }

    m_vis_bfs visited;
    m_dist_bfs distance;
    m_paths_bfs path;
    for (auto x : adj)
    {
        auto from = x.first;
        auto to = x.second;

        visited[from] = false;
        distance[from] = INT_MAX;
        path[from] = std::list<int>();
    }

    distance[curr] = 0;
    path[curr].push_back(curr);
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
            auto neighbour = x;
            int dist = distance[temp] + 1;
            if (distance[neighbour] > dist)
            {
                distance[neighbour] = dist;
                next.push(neighbour);

                path[neighbour] = path[temp];
                path[neighbour].push_back(neighbour);
            }
        }
    }

    output_bfs output;
    for (auto x : adj)
    {
        auto node = x.first;
        output[node] = {distance[node], path[node]};
    }

    return output;
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

typedef std::unordered_map<int, std::vector<std::pair<int, int>>> adj_dij;
typedef std::unordered_map<int, bool> m_vis_dij;
typedef std::unordered_map<int, int> m_dist_dij;
typedef std::unordered_map<int, std::list<std::pair<int, int>>> m_paths_dij;
typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> frontier_dij;
typedef std::unordered_map<int, std::pair<int, std::list<std::pair<int, int>>>> output_dij;

// WORST: O(E*LOGV)
// FIND SHORTEST PATH IN WEIGHTED GRAPH
output_dij dijkstra(adj_dij adj, int curr)
{
    if (adj.empty())
    {
        return output_dij();
    }

    m_vis_dij visited;
    m_dist_dij distance;
    m_paths_dij path;
    for (auto x : adj)
    {
        auto from = x.first;
        auto to = x.second;

        visited[from] = false;
        distance[from] = INT_MAX;
        path[from] = std::list<std::pair<int, int>>();
    }

    distance[curr] = 0;
    path[curr].push_back({curr, 0});
    frontier_dij next;
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
            auto neighbour = x.first;
            auto dist = distance[temp.first] + x.second;
            if (distance[neighbour] > dist)
            {
                distance[neighbour] = dist;
                next.push({neighbour, dist});

                path[neighbour] = path[temp.first];
                path[neighbour].push_back({neighbour, dist});
            }
        }
    }

    output_dij output;
    for (auto x : adj)
    {
        auto node = x.first;
        output[node] = {distance[node], path[node]};
    }

    return output;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // BFS
    {
        adj_bfs adj;
        auto add = [&adj](int a, int b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        };
        add(3, 17);
        add(3, 42);
        add(3, 81);
        add(17, 42);
        add(42, 11);
        add(42, 57);
        add(42, 81);
        add(11, 57);
        add(11, 23);
        add(57, 81);
        add(57, 47);
        add(57, 0);
        add(57, 23);
        add(0, 23);

        int start = 3;
        auto result = bfs(adj, start);
        printf("BFS\n");
        printf("start: %d\n", start);
        for (auto x : result)
        {
            printf("to: %d  distance: %d path: ", x.first, x.second.first);
            for (auto y : x.second.second)
            {
                printf("%d ", y);
            }
            printf("\n");
        }
    }

    // Dikstra
    {
        adj_dij adj;
        auto add = [&adj](int a, int b, int c)
        {
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        };
        add(3, 17, 47);
        add(3, 42, 3);
        add(3, 81, 100);
        add(17, 42, 8);
        add(42, 11, 18);
        add(42, 57, 34);
        add(42, 81, 57);
        add(11, 57, 12);
        add(11, 23, 35);
        add(57, 81, 17);
        add(57, 47, 15);
        add(57, 0, 24);
        add(57, 23, 6);
        add(0, 23, 2);

        int start = 3;
        auto result = dijkstra(adj, start);
        printf("Dikstra\n");
        printf("start: %d\n", start);
        for (auto x : result)
        {
            printf("to: %d  distance: %d path: ", x.first, x.second.first);
            for (auto y : x.second.second)
            {
                printf("%d ", y.first);
            }
            printf("\n");
        }
    }

    return 0;
}
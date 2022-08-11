#include <bits/stdc++.h>

// (Prim) Custom Compare Priority Queue
class Compare
{
public:
    bool operator()(std::tuple<int, int, int> a, std::tuple<int, int, int> b)
    {
        if (std::get<2>(a) < std::get<2>(b))
        {
            return false;
        }

        return true;
    }
};

typedef std::unordered_map<int, std::vector<std::pair<int, int>>> adj_prim;
typedef std::unordered_map<int, bool> m_vis_prim;
typedef std::unordered_map<int, int> m_dist_prim;
typedef std::list<std::tuple<int, int, int>> l_path_prim;
typedef std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, Compare> frontier_prim;
typedef std::list<std::tuple<int, int, int>> output_prim;

int start = 3;
int dummy = -1;

output_prim prim(adj_prim adj)
{
    if (adj.empty())
    {
        return output_prim();
    }

    m_vis_prim visited;
    m_dist_prim distance;
    l_path_prim path;
    for (auto x : adj)
    {
        auto from = x.first;
        auto to = x.second;

        visited[from] = false;
        distance[from] = INT_MAX;
    }

    // We should start from somewhere, can pick random element from adj
    distance[start] = 0;
    frontier_prim next;

    // Start from a node that has no parents
    next.push({dummy, start, 0});

    while (!next.empty())
    {
        auto temp = next.top();
        next.pop();

        auto from = std::get<0>(temp);
        auto to = std::get<1>(temp);
        auto weight = std::get<2>(temp);

        if (visited[to])
        {
            continue;
        }
        visited[to] = true;

        if (from != dummy)
        {
            path.push_back({from, to, weight});
        }

        for (auto x : adj[to])
        {
            next.push({to, x.first, x.second});
        }
    }

    return path;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Prim
    {
        adj_prim adj;
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

        auto result = prim(adj);
        printf("Prim\n");
        printf("start: %d\n", start);
        int min_cost = 0;
        for (auto x : result)
        {
            min_cost += std::get<2>(x);
            printf("from: %d to: %d distance: %d\n", std::get<0>(x), std::get<1>(x), std::get<2>(x));
        }
        printf("min cost to build mst: %d\n", min_cost);
    }

    return 0;
}
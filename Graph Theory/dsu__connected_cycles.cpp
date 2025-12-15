// https://codeforces.com/contest/977/problem/E
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
struct DSU {
    int parent[N], rank_[N], group_size[N], components;

    void dsu_initialize(int n) // O(n)
    {
        components = n;
        for (int i = 0; i <= n; i++) parent[i] = i, rank_[i] = 0, group_size[i] = 1;
    }

    int dsu_find(int node) // O(alpha(n))
    {
        if (parent[node] == node) return node;
        return parent[node] = dsu_find(parent[node]);
    }

    bool dsu_same(int u, int v) // O(alpha(n))
    {
        return dsu_find(u) == dsu_find(v);
    }

    int dsu_get_size(int node) // O(alpha(n))
    {
        int leader = dsu_find(node);
        return group_size[leader];
    }

    int dsu_num_components() // O(1)
    {
        return components;
    }

    int dsu_merge(int u, int v) // O(alpha(n))
    {
        int leader_u = dsu_find(u), leader_v = dsu_find(v);
        if (leader_u == leader_v) return -1;
        components--;

        if (rank_[leader_u] > rank_[leader_v]) swap(leader_u, leader_v);
        parent[leader_u] = leader_v;
        group_size[leader_v] += group_size[leader_u];

        if (rank_[leader_u] == rank_[leader_v]) rank_[leader_v]++;
        return leader_v;
    }
};

vector<int> adj[N];

int main() 
{
    int n, e;
    cin >> n >> e;

    DSU dsu;
    dsu.dsu_initialize(n);

    while (e--) 
    {
        int u, v;
        cin >> u >> v;
        dsu.dsu_merge(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, vector<int>> leaders;
    for (int i = 1; i <= n; i++) 
    {
        int leader = dsu.dsu_find(i);
        leaders[leader].push_back(i);
    }

    int cntCycle = 0;
    for (auto [leader, nodes] : leaders) 
    {
        bool isCycle = true;
        for (auto node : nodes) 
        {
            if (adj[node].size() != 2) 
            {
                isCycle = false;
                break;
            }
        }
        if (nodes.size() <= 2) isCycle = false;
        if (isCycle) cntCycle++;
    }

    cout << cntCycle << '\n';
    return 0;
}
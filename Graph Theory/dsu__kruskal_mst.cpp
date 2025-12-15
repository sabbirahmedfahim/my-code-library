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

struct Edge 
{
    int u, v, w; 
    Edge(int u, int v, int w) 
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int main() 
{
    int n, e; 
    cin >> n >> e;

    DSU dsu;
    dsu.dsu_initialize(n);

    vector<Edge> edgeList;
    while (e--) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int totalCost = 0;
    for (Edge ed : edgeList) 
    {
        if (!dsu.dsu_same(ed.u, ed.v)) 
        {
            dsu.dsu_merge(ed.u, ed.v);
            totalCost += ed.w;
        }
    }

    cout << totalCost;
    return 0;
}
/*
Input:
5 7
0 1 2
0 2 3
0 3 3
3 4 6
2 4 4
2 1 7
1 4 5

Expected Output:
12
*/
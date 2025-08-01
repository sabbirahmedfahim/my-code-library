#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;
const int N = 1e5 + 5;
int parent[N], group_size[N]; // union by size/rank is faster than normal union

void dsu_initialize(int n) 
{
    for (int i = 0; i < n; i++) parent[i] = -1, group_size[i] = 1;
}

int dsu_find(int node) 
{
    if(parent[node] == -1) return node;
    return parent[node] = dsu_find(parent[node]); // path compression
}

void dsu_union_by_size(int node1, int node2) 
{
    int leaderA = dsu_find(node1), leaderB = dsu_find(node2);
    if(leaderA == leaderB) return;
    if(group_size[leaderA] > group_size[leaderB])
        parent[leaderB] = leaderA, group_size[leaderA] += group_size[leaderB]; 
    else
        parent[leaderA] = leaderB, group_size[leaderB] += group_size[leaderA];
}

class Edge 
{
public:
    int u, v, w; 
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int main() 
{
    int n, e; cin >> n >> e;
    dsu_initialize(n); 
    vector<Edge> edgeList;
    while (e--) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), cmp); 
    int totalCost = 0; // store costs
    for (Edge ed : edgeList) 
    {
        int leaderU = dsu_find(ed.u), leaderV = dsu_find(ed.v);
        if(leaderU != leaderV) {
            dsu_union_by_size(ed.u, ed.v);
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
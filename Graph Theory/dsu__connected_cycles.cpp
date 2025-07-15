// https://codeforces.com/contest/977/problem/E
#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
using namespace std;
const int N = 2e5 + 5;
int parent[N];
vector<int> adj[N];
void dsu_initialize(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
    }
}
int dsu_find(int node)
{
    if(parent[node] == -1) return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader; // path compression
    return leader;
}
void dsu_union(int node1, int node2) 
{
    int leaderA = dsu_find(node1); 
    int leaderB = dsu_find(node2); 
    if(leaderA != leaderB) parent[leaderA] = leaderB; 
}
int main()
{
    int n, e; cin >> n >> e;
    dsu_initialize(n); 
    
    int cntCycle = 0;
    while (e--)
    {
        int u, v; cin >> u >> v;

        dsu_union(u, v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, vector<int> > leaders;
    for (int i = 1; i <= n; i++)
    {
        int leader = dsu_find(i);
        leaders[leader].push_back(i);
    }
    
    for(auto [leader, nodes] : leaders)
    {
        bool isCycle = true;
        for(auto data : nodes)
        {
            if(adj[data].size() != 2) 
            {
                isCycle = false; break;
            }
        }
        if(nodes.size() <= 2) isCycle = false;

        if(isCycle) cntCycle++;
    }
    
    cout << cntCycle << nl; 

    return 0;
}
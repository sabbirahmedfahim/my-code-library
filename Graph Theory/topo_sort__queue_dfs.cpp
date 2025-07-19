// https://cses.fi/problemset/task/1679/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
void topoSortBFS(int n, vector<vector<int>> &adjList) /* kahn's algorithm */
{
    queue<int> nodes;
    // priority_queue<int> nodes; // picks largest node first
    vector<int> inDeg(n + 1, 0);
    vector<int> res;
    
    for (int i = 1; i <= n; i++) 
    {
        for (auto e : adjList[i]) inDeg[e]++;
    }
    
    for (int i = 1; i <= n; i++) 
    {
        if (inDeg[i] == 0) nodes.push(i);
    }
    
    while (!nodes.empty()) 
    {
        int curr = nodes.front();
        res.push_back(curr);
        nodes.pop();
        for (int i : adjList[curr]) 
        {
            inDeg[i]--;
            if (inDeg[i] == 0) nodes.push(i);
        }
    }

    /* If Topological Sort does not exist then the vector size will be less than the number of vertices */ 
    if (res.size() < n)
        cout << "IMPOSSIBLE" << endl;
    else 
    {
        print(res);
    }
}
void topoSortDFS(int n, const vector<vector<int>> &adjList) /* DFS Version */
{
    vector<int> vis(n + 1, 0);
    vector<int> res;

    function<bool(int)> dfs = [&](int node) -> bool 
    {
        if (vis[node] == 1) return false;  // cycle found
        if (vis[node] == 2) return true;

        vis[node] = 1;
        for (int nxt : adjList[node]) 
        {
            if (!dfs(nxt)) return false;
        }
        vis[node] = 2;
        res.push_back(node);
        return true;
    };

    for (int i = 1; i <= n; i++) 
    {
        if (vis[i] == 0) 
        {
            if (!dfs(i)) 
            {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }

    reverse(all(res));
    print(res);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, e; cin >> n >> e;
    vector<vector<int>> adjList(n + 1);
    while (e--)
    {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
    }

    topoSortBFS(n, adjList);
    // topoSortDFS(n, adjList);
 
    return 0;
}
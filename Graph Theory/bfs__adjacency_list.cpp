// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
vector<int> adjList[N];
bool vis[N];
// int level[N]; /* level == distance == cost */  
// int parent[N]; 
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    // level[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int child : adjList[node]) // node == parent of child
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                // level[child] = level[node] + 1; /* level == distance == cost */  
                // parent[child] = node;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    // int src, des;
    // cin >> src >> des;
    
    memset(vis, false, sizeof(vis));
    // memset(level, -1, sizeof(level));
    // memset(parent, -1, sizeof(parent));

    vector<int> roadRequired;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            roadRequired.push_back(i);
            bfs(i);
        }
    }
    
    cout << roadRequired.size() - 1 << '\n';
    if(roadRequired.size() > 1)
    {
        for (int i = 0; i < roadRequired.size() - 1; i++)
        {
            cout << roadRequired[i] << " " << roadRequired[i + 1] << '\n';
        }
    }

    // bfs(src);

    /* PATH PRINTING */
    // int temp = des;
    // vector<int> path;
    // while (temp != -1)
    // {
    //     path.push_back(temp);
    //     temp = parent[temp];
    // }
    // reverse(path.begin(), path.end());
    // for (int val : path)
    // {
    //     cout << val << " ";
    // }

    return 0;
}
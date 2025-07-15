// https://codeforces.com/contest/20/problem/C
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const ll N = 1E5 + 5, inf = 1E18;
vector<pair<int,int> > adjList[N];
ll dis[N];
ll parent[N];
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto child : adjList[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(dis[node] + childCost < dis[childNode])
            {
                dis[childNode] = dis[node] + childCost;
                parent[childNode] = node;
                
                pq.push({dis[childNode], childNode});
            }
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, e; cin >> n >> e;
    while (e--)
    {
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    memset(parent, -1, sizeof(parent));

    dijkstra(1);
    
    if(dis[n] == inf)
    {
        cout << -1 << nl; return 0;
    }

    int tmp = n;
    vector<int> path;
    while (tmp != -1)
    {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    reverse(all(path));
    print(path);

    return 0;
}
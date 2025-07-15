// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E5 + 5;
vector<int> adjList[N];
bool vis[N];    
void dfs(int src)
{
    vis[src] = true;
    
    for (int child : adjList[src])
    {
        if(!vis[child]) 
        {
            dfs(child);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, e; cin>> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a); 
    }
    memset(vis, false, sizeof(vis)); 
 
    vector<int> roadsRequired;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            roadsRequired.push_back(i);
            dfs(i);
        }
    }
    
    cout << roadsRequired.size() - 1 << endl;
    if(roadsRequired.size() > 1)        
    {
        for (int i = 0; i < roadsRequired.size()-1; i++)
        {
            cout << roadsRequired[i] << " " << roadsRequired[i + 1] << endl;
        }
    }
 
    return 0;
}
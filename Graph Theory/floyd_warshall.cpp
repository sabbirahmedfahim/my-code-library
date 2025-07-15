// https://cses.fi/problemset/task/1672/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll inf = 1e18;
int main()
{
    int n, e, q;
    cin >> n >> e >> q;
    ll adj[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = inf;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > c) adj[a][b] = c;
        if (adj[b][a] > c) adj[b][a] = c; // if the graph is undirected
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }


    /* Uncomment the block below if the graph may contain negative edge weights and you want to check for 
    negative weight cycles. If any adj[i][i] < 0, it means a negative cycle exists that can affect shortest paths. */
    // bool flag = false;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (adj[i][i] < 0)
    //     {
    //         cout << "Cycle detected";
    //         flag = true;
    //         break;
    //     }
    // }
 
    // while (!flag && q--)
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (adj[x][y] == inf) cout << -1 << endl;
        else cout << adj[x][y] << endl;
    }
 
    return 0;
}

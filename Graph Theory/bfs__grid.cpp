// https://codeforces.com/gym/105819/problem/C
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E3 + 5;
int mat[N][N]; // adjust data type ***
int n, m;
bool vis[N][N];
int dist[N][N];
vector<pair<int, int> > d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool is_valid(int ci, int cj)
{
    return (ci < n && ci >= 0 && cj < m && cj >= 0);
}
int cnt = 0;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y)
{
    return get<0> (x) > get<0> (y);
}
void bfs(int si, int sj) 
{
    cnt++;
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    // dist[si][sj] = 0;
    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            // careful with mixed-type comparisons (e.g., char vs int)
            if(is_valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] < mat[par.first][par.second]) 
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                // dist[ci][cj] = dist[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    cin >> n >> m;

    vector<tuple<int, int, int>> val_idx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            val_idx.push_back({mat[i][j], i, j});
        }
    }

    memset(vis, false, sizeof(vis));
    // memset(dist, -1, sizeof(dist));

    sort(all(val_idx), cmp);
    for (int i = 0; i < val_idx.size(); i++)
    {
        auto [data, x, y] = val_idx[i];
        if(!vis[x][y]) bfs(x, y);
    }

    cout << cnt << nl;
 
    return 0;
}
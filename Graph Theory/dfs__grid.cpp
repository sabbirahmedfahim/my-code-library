// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E3 + 5;
char mat[N][N]; // change data type ***
bool vis[N][N];
int n, m;
int si, sj, di, dj;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool is_valid(int ci, int cj)
{
    return (ci < n && ci >= 0 && cj < m && cj >= 0);
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;  
        int cj = sj + d[i].second; 
 
        if (is_valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != '#') // change data type ***
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j]; 
        }
    }
    memset(vis, false, sizeof(vis));
 
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == '.' && !vis[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
 
    cout << cnt << endl;
 
    return 0;
}
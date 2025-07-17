/*
Given an initial array and multiple range increment queries,
efficiently apply all increments and output the final updated array.
*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }

    vector<int> diffArray(n + 2, 0);

    while (q--)
    {
        int l, r, data;
        cin >> l >> r >> data;
        diffArray[l] += data;
        diffArray[r + 1] -= data;
    }
    
    int curr = 0;
    for (int i = 1; i <= n; i++) 
    {
        curr += diffArray[i];
        diffArray[i] = curr;
    }

    for (int i = 1; i <= n; i++) 
    {
        cout << a[i] + diffArray[i] << " ";
    }
    cout << nl;

    return 0;
}
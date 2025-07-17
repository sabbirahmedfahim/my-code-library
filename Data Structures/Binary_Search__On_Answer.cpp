// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    sort(all(a));

    auto canWePlace = [&](ll dist)
    {
        int currDist = a[0], totCows = 1;
        for (int i = 1; i < n; i++)
        {
            if(a[i] - currDist >= dist)
            {
                totCows++, currDist = a[i];
            }
            if(totCows == k) return true;
        }
        return false;
    };

    int lo = 1, hi = 1E9, res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(canWePlace(mid)) 
        {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << res << nl;

    return 0;
}
// https://codeforces.com/contest/550/problem/B
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, mnp, mxp, diff; cin >> n >> mnp >> mxp >> diff;
    vector<int> v(n); for(auto &e : v) cin >> e;

    int res = 0;

    for(int bit = 0; bit < (1<<n); bit++)
    {
        int mnDifficulty = 1E6+5, mxDifficulty = 0, problemCount = 0, totDifficulty = 0;
        for(int k = 0; k < n; k++)
        {
            //if((bit >> k) & 1) cout << 1 << " ";
            //else cout << 0 << " ";
            if((bit >> k) & 1)
            {
                totDifficulty += v[k];
                mnDifficulty = min(mnDifficulty, v[k]); mxDifficulty = max(mxDifficulty, v[k]); problemCount++;
            }
        }
        if(problemCount >= 2 && totDifficulty >= mnp && totDifficulty <= mxp && mxDifficulty-mnDifficulty >= diff) res++;
    }

    cout << res << nl;

    return 0;
}
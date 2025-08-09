#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int MOD = 1e9 + 7;

// mod + normal both 
ll Pow(ll a, ll b) // O(log b)
{ 
    // a %= MOD;
    // if (a < 0) a += MOD;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a;
            // ans = (ans * a) % MOD;
        }
        a = a * a;
        // a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // code here

    return 0;
}
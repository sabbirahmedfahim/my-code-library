#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int MOD = 1e9 + 7;

ll Pow(ll a, ll b) // O(log b)
{
    ll ans = 1 % MOD;
    a %= MOD;
    if (a < 0) a += MOD;
    while (b) 
    {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

// faster and more accurate than built-in pow() for integers
ll powInt(ll a, ll b) // O(log b)
{
    ll ans = 1;
    while (b) 
    {
        if (b & 1) ans *= a;
        a *= a;
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
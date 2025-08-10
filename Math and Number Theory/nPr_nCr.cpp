#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
ll nCr(ll n, ll r) // O(r * log(n))
{
    ll p = 1, k = 1, m;
    if (n - r < r) r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n, k *= r;
            m = __gcd(p, k);
            p /= m, k /= m;
            n--, r--;
        }
    }
    else p = 1;
    return p;
}
ll fact(ll n)
{
    if(n <= 1) return 1;
    return n * fact(n - 1);
}
ll nPr(ll n, ll r) // O(n)
{
    return fact(n) / fact(n - r);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    

    return 0;
}
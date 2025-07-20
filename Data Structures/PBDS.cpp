// https://codeforces.com/contest/61/problem/E
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*
if (x >= 0 && x < (int)o_mulset.size()) // → k-th smallest element (0-based)
{
   cout << *o_mulset.find_by_order(x) << nl; 
} 
cout << o_mulset.order_of_key(x) << nl; // → count of elements strictly < x
*/
using namespace std;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal for multiset

int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin>>e;

    pbds<int> o_mulset, curr; 
    /* Unique Values, Don't need a Map */
    for(auto e : a) o_mulset.insert(e); 

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int l = curr.size() - curr.order_of_key(a[i] + 1);
        int r = o_mulset.order_of_key(a[i]) - curr.order_of_key(a[i]);

        if(min(l, r) > 0) cnt += 1ll * l * r;
        // cout << a[i] << " " << cnt << nl;

        curr.insert(a[i]);
    }
    
    cout << cnt << nl;

    return 0;
}
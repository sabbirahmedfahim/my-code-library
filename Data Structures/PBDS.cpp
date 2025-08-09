// https://cses.fi/problemset/task/1076/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal for multiset

int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    pbds<int> o_mulset;
    for (int l = 0, r = 0; r < n; r++)
    {
        o_mulset.insert(a[r]);
        if(r - l + 1 == k)
        {
            cout << *o_mulset.find_by_order((k-1)/2) << " ";

            // since we can delete elements from multiset even if it contains duplicates, don't need a pair in the case
            o_mulset.erase(o_mulset.find_by_order(o_mulset.order_of_key(a[l++])));
        }
    }
    cout << nl;

    return 0;
}
/* Basic Operations
if (x >= 0 && x < (int)o_mulset.size()) // → k-th smallest element (0-based)
{
   cout << *o_mulset.find_by_order(x) << nl; 
} 
cout << o_mulset.order_of_key(x) << nl; // → count of elements strictly < x
*/
/* 
ordered multiset allows duplicates and we can erase them, but it's first occurance, but
Use pbds<pair<int, int>> to store {value, index} pairs where needed
*/
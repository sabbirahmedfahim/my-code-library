#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define nl '\n'
#define all(c) c.begin(), c.end()
#define print(c) for (auto e : c) cout << e << " "; cout << nl;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() 
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    ordered_set<int> os = {4, 2, 9, 1, 3}; 
    os.insert(6); os.erase(2);
    cout << *os.find_by_order(2) << nl << os.order_of_key(4) << nl << "os: "; print(os);

    ordered_multiset<int> oms; for (int x : vector<int>{4,2,9,4,1,3}) 
    oms.insert(x); // do not supports erase
    cout << oms.order_of_key(4) << nl << *oms.find_by_order(3) << nl;
    auto it = oms.find_by_order(oms.order_of_key(4)); if (it != oms.end()) oms.erase(it);
    cout << "oms: "; print(oms);

    return 0;
}
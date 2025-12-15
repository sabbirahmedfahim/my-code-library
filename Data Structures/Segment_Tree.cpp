#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 3e5 + 9;

struct ST 
{
    ll t[4 * N];

    auto merge(auto &l, auto &r) // Change this function
    { 
        return l + r;
    }
    void build(int node, int st, int en, vector<ll> &a) // O(N)
    { 
        if (st == en) 
        {
            t[node] = a[st]; 
            return;
        }
        int mid = (st + en) >> 1;
        build(node << 1, st, mid, a);         // node << 1     --> 2 * node
        build(node << 1 | 1, mid + 1, en, a); // node << 1 | 1 --> 2 * node + 1
        // Merging left and right portion
        t[node] = merge(t[node << 1], t[node << 1 | 1]);
        return;
    }
    void update(int node, int st, int en, int idx, ll data) // O(log n)
    {
        if (st == en) 
        {
            t[node] = data;
            return;
        }
        int mid = (st + en) >> 1;
        if (idx <= mid) update(node << 1, st, mid, idx, data);
        else update(node << 1 | 1, mid + 1, en, idx, data);
        // Merging left and right portion
        t[node] = merge(t[node << 1], t[node << 1 | 1]);
        return;
    }
    ll query(int node, int st, int en, int l, int r) // O(log n)
    { 
        if (st > r || en < l) // No overlapping and out of range
        { 
            return 0; // <== careful 
            /*
            XOR,OR-> return 0; AND-> return ~0LL;
            min-> return LLONG_MAX; max-> return LLONG_MIN;
            */
        }
        if (l <= st && en <= r) // Complete overlapped (l-r in range)
        { 
            return t[node];
        }
        
        // Partial overlapping
        int mid = (st + en) >> 1;
        auto Left = query(node << 1, st, mid, l, r);
        auto Right = query(node << 1 | 1, mid + 1, en, l, r);
        return merge(Left, Right);
    }
} st;

void solve() 
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1); // 1-based index
    for (int i = 1; i <= n; i++) cin >> a[i];

    st.build(1, 1, n, a); // Creating Segment tree
    while (q--) 
    {
        int type; cin >> type;
        if (type == 1) 
        {
            int idx; ll data; cin >> idx >> data;
            st.update(1, 1, n, idx, data);
        }
        else 
        {
            int l, r; cin >> l >> r; 
            cout << st.query(1, 1, n, l, r) << endl;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
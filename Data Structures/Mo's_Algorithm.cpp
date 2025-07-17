/* 
Efficiently perform multiple range sum queries on a static array 
using Mo's Algorithm (offline query optimization).
*/ 
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E5 + 7;
int blockSize; 
class Q
{
    public:
    int l, r, idx;
};
Q q[N];
bool cmp(Q &q1, Q &q2) // faster 
{ 
    if (q1.l / blockSize != q2.l / blockSize) return (q1.l == q2.l ? q1.r <= q2.r : q1.l < q2.l);
    return (q1.l / blockSize & 1) ? (q1.r < q2.r) : (q1.r > q2.r);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;

    blockSize = sqrtl(n) + 1;
    int queries; cin >> queries;

    for (int i = 0; i < queries; i++) // offline queries
    {
        int l, r; cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    
    sort(q, q + queries, cmp); // O(q * log(q))
    vector<int> res(queries);

    int curr_l = 0, curr_r = -1, l, r;
    ll curr_ans = 0;
    for (int i = 0; i < queries; i++) // O((q + n) * sqrt(n))
    {
        l = q[i].l, r = q[i].r;
        l--, r--; // zero based index

        while (curr_r < r)
        {
            curr_r++;
            curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }
        while (curr_l < l)
        {
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while (curr_r > r)
        {
            curr_ans -= a[curr_r];
            curr_r--;
        }
        
        res[q[i].idx] = curr_ans;
    }
    
    for (int i = 0; i < queries; i++)
    {
        cout << res[i] << nl;
    }

    return 0;
}
/*
Input:
9
1 5 -2 6 8 -7 2 1 11
3
7 8
1 6 
2 7

Output:
3
11
12
*/
// https://youtu.be/0Cu9Kg7RJYg?si=u8_M5Le6uCz_N-lu
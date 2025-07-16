#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
void merge(vector<int> &a, int l, int m, int r)
{
    int leftSz = m-l+1;
    int rightSz = r - m;
    int L[leftSz];
    int R[rightSz]; 
    
    int idx = 0;
    for (int i = l; i <= m; i++)
    {
        L[idx] = a[i];
        idx++;
    }
    idx = 0; 
    for (int i = m+1; i <= r; i++)
    {
        R[idx] = a[i];
        idx++;
    }

    int i = 0, j = 0;
    int cur = l; 
    while (i < leftSz && j < rightSz)
    {
        if(L[i] <= R[j])    
        {
            a[cur] = L[i];
            i++;
        }
        else 
        {
            a[cur] = R[j];
            j++;
        }
        cur++;
    }

    while (i < leftSz) a[cur] = L[i], i++, cur++;
    while (j < rightSz) a[cur] = R[j], j++, cur++;
}
void merge_sort(vector<int> &a, int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);

        merge(a, l, mid, r); 
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    
    merge_sort(a, 0, n-1);

    print(a);

    return 0;
}
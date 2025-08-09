#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> a = {1, 2, 3};
    sort(all(a)); // must ***

    while (next_permutation(all(a))) // O(n! * n)
    {
        print(a);
    }

    return 0;
}
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int LCM(int a, int b)
{
    return (a / __gcd(a, b)) * b; // safer against overflow
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // code here

    return 0;
}
/*
    For LCM, we consider the largest factors.
    18 --> 2, 3, 3
    24 --> 2, 2, 2, 3
    The highest powers are 2^3 and 3^2, so 8 * 9 = 72.

    If there are no common factors, we assume the smallest factor has a power of zero.
*/
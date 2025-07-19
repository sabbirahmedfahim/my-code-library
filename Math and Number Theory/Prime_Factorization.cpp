#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> prime_factors;
    for(int i = 2; i*i <= n; i++) // O(sqrt(n))
    {
        while(n%i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n>1) prime_factors.push_back(n);
    
    for(auto prime: prime_factors)
    {
        cout<< prime <<" ";
    }

    return 0;
}
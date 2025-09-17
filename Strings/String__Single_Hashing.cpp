#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;

struct StringHash
{
    /*
        in main() write the following line for better randomness 
        srand(time(0));
    */
    vector<ll> bases = {131, 137, 277, 257};
    vector<ll> mods  = {127657753, 987654319, 1000000007, 972663749};
    ll base, mod;
    vector<ll> prefixHash, suffixHash, basePower;

    StringHash(const string &s)
    {
        int n = s.size();
        prefixHash.resize(n); basePower.resize(n); suffixHash.resize(n);
        base = bases[rand()%4];
        mod  = mods[rand()%4];
        
        buildPrefixHash(s); // O(n)
        // buildSuffixHash(s); // *** Uncomment when you need to build SuffixHash
    }
    
    void buildPrefixHash(const string &s) // O(n)
    {
        prefixHash[0] = s[0];
        basePower[0] = 1;
        for(int i=1;i<s.size();i++)
        {
            prefixHash[i] = ((prefixHash[i-1] * base) + s[i]) % mod;
            basePower[i]  = (basePower[i-1] * base) % mod;
        }
    }

    void buildSuffixHash(const string &s) // O(n) if called
    {
        int n = s.size();
        suffixHash[n-1] = s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixHash[i] = ((suffixHash[i+1] * base) + s[i]) % mod;
        }
    }

    ll quickHash(const string &s) // O(n)
    {
        ll Hash = s[0];
        for(int i=1;i<s.size();i++)
        {
            Hash = ((Hash*base) + s[i]) % mod;
        }
        return Hash;
    }
    
    ll getPrefixHash(int l, int r) // O(1)
    {
        if(l==0) return prefixHash[r];
        ll val = (prefixHash[r] - (prefixHash[l-1] * basePower[r-l+1]) % mod + mod) % mod;
        return val;
    }

    ll getSuffixHash(int l, int r)  // O(1)
    {
        int n = suffixHash.size();
        if(r == n-1) return suffixHash[l];
        ll val = (suffixHash[l] - (suffixHash[r+1] * basePower[r-l+1]) % mod + mod) % mod;
        return val;
    }

    ll concatSubstr(int l1,int r1,int l2,int r2) // O(1)
    {
        ll hashLeft  = getPrefixHash(l1,r1);
        ll hashRight = getPrefixHash(l2,r2);
        return (hashLeft + hashRight * basePower[r2-l2+1]) % mod;
    }

    ll concatHash(const ll& left, const ll& right, int lenRight) // O(1)
    {
        return (left * basePower[lenRight] + right) % mod;
    }

    void appendChar(char c) // O(1)
    {
        ll newVal = (prefixHash.back() * base + c) % mod;
        prefixHash.push_back(newVal);
        
        ll powVal = (basePower.back() * base) % mod;
        basePower.push_back(powVal);
    }
};

void solve()
{
    string s; cin >> s;

    StringHash hash(s);

    // Example: append a character
    s.push_back('a');
    hash.appendChar('a');
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    srand(time(0)); // call once under main function

    solve();
}

/*
* Notes:
* - buildPrefixHash() is auto-called in the constructor; buildSuffixHash() must be 
*   uncommented when a suffix hash is needed.
* - Random base/mod helps reduce collisions but keep consistent for reproducibility.
* - appendChar() updates the hash in O(1) when extending the string.
* - concatSubstr() works well even if multiple hashes are declared.
*/
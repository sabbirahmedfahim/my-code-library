#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9; vector<bool> isPrime(N, true);

// using bitset you can solve upto around N = 10^8 in 1s
// const int N = 1E8 + 5; bitset<N> isPrime; // to have O(N/64) memory complexity

void sieve() 
{
    // isPrime.set(); // sets all bits to true
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j < N; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
}
int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    sieve();

    int n; cin >> n;
    if(isPrime[n]) cout << "Prime" << '\n';
    else cout << "Not Prime" << '\n';
}
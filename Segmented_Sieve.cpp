/**
    Segmented Sieve O(1)
    Preprocessing: O(N log log N)
    Per Query: O(1)
    Space: O(N)
**/

#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

const int N = 1000006;
int isPrime[N];
int isSegPrime[N];
vector<int> primeList;

void sieve(int n)
{
    for (int i = 0; i <= n; i++) {
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += 2*i) {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == 1) primeList.push_back(i);
    }
}

void segmentedSieve(ll l, ll r)
{
    int n = r - l + 1;
    for (int i = 0; i <= n; i++) {
        isSegPrime[i] = 1;
    }
    if (l == 1) isSegPrime[0] = 0;
    for (int i = 0; (1LL * primeList[i]) * primeList[i] <= r; i++) {
        ll j = l;
        ll t = l % primeList[i];
        if (t != 0) j += (primeList[i] - t);
        if (primeList[i] == j) j += primeList[i];
        for ( ; j <= r; j += primeList[i]) {
            isSegPrime[j - l] = 0;
        }
    }
}

int main()
{
    sieve(1000000);
    int t = 1; cin >> t;
    int l, r; cin >> l >> r;
    segmentedSieve(l, r);
    while (t--) {
        int n; cin >> n;
        if (isSegPrime[n - l]) {
            cout << "prime\n";
        }
        else {
            cout << "not prime\n";
        }
    }
    return 0;
}

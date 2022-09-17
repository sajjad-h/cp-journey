/**
    Ferment Primality Test O(log n)
    Preprocessing: no
    Per Query: O(log n)
    Space: O(1)
**/

#include <bits/stdc++.h>
using namespace std;

#define  ll   long long int

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0;
    while (b) {
        if (b & 1) {
            res  = (res + a) % mod;
        }
        a = (2 * a) % mod;
        b = b >> 1;
    }
    return res;
}

ll bigmod(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = mulmod(res, a, mod);;
        }
        a = mulmod(a, a, mod);
        b = b >> 1;
    }
    return res;
}

int isPrime(ll n, int iterations = 5)
{
    if (n < 4) {
        return n == 2 || n == 3;
    }
    while (iterations--) {
        ll a = 2 + rand() % (n - 3);
        ll res = bigmod(a % n, n - 1, n);
        if (res != 1) return false; // not prime (sure)
    }
    return true; // prime (probably)
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    srand(time(0));
    int t = 1; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (isPrime(n)) {
            cout << "prime\n";
        }
        else {
            cout << "not prime\n";
        }
    }
    return 0;
}


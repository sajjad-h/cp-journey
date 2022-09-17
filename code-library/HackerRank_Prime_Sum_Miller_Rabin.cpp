/**
    Miller-Rabin Primality Test (Non-Deterministic) O(log n)
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
            res = (res + a) % mod;
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

int check_composite(ll a, ll s, ll d, ll n)
{
    ll x = bigmod(a, d, n);
    if (x == 1 || x == n - 1) {
        return 0; // not composite
    }
    for (ll r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1) {
            return 0; // not composite
        }
    }
    return 1; // composite
}

int isPrime(ll n, int iterations = 5)
{
    if (n < 4) {
        return n == 2 || n == 3;
    }
    if (n % 2 == 0) return 0;
    ll d = n - 1, s = 0;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }
    while (iterations--) {
        ll a = 2 + rand() % (n - 3);
        if (check_composite(a, s, d, n)) {
            return 0; // not prime (sure)
        }
    }
    return 1; // prime (probably)
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    srand(time(0));
    int t = 1; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        if (k == 1) {
            if (isPrime(n)) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
        else if (k == 2) {
            if (n % 2 == 0) {
                if (n > 2) {
                    cout << "Yes\n";
                }
                else {
                    cout << "No\n";
                }
            }
            else {
                if (isPrime(n - 2)) {
                    cout << "Yes\n";
                }
                else {
                    cout << "No\n";
                }
            }
        }
        else {
            ll mn = k * 2;
            if (n % 2) mn++;
            if (n >= mn) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}

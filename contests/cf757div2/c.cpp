#include <bits/stdc++.h>
using namespace std;

#define     ll      long long int

const ll mod = 1000000007;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b / 2, mod);
    c = (c * c) % mod;
    if (b % 2 == 1) c = (c * a) % mod;
    return c;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        ll n, m;
        ll orvalue = 0;
        cin >> n >> m;
        while (m--) {
            ll l, r, d;
            cin >> l >> r >> d;
            orvalue = orvalue | d;
        }
        ll res = (orvalue * bigmod(2, n - 1, mod)) % mod;
        cout << res << '\n';
    }
    return 0;
}

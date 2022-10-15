#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const ll base = 131; // 37, 129, 131
const ll mod = 1000000007; // 1000000009;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b / 2, mod);
    c = (c * c) % mod;
    if (b & 1) c = (c * a) % mod;
    return c;
}

void rabin_karp(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();

    ll t = 0;
    ll p = 0;
    ll h = bigmod(base, m - 1, mod);

    for (int i = 0; i < m; i++) {
        t = (base * t + txt[i]) % mod;
        p = (base * p + pat[i]) % mod;
    }

    for (int i = 0; i <= (n - m); i++) {
        if (p == t) {
            if (txt.substr(i, m) == pat) {
                cout << "Pattern found at " << (i + 1) << "\n";
            }
        }

        if (i < (n - m)) {
            t = (base * (t - txt[i] * h) + txt[i + m]) % mod;
            if (t < 0) t += mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    rabin_karp(txt, pat);
    return 0;
}

/**



**/

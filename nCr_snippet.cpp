
const int N = 1e5 + 5;
const int mod = 1000000007;

ll fac[N];
ll inv[N];
ll fac_inv[N];

void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[1] = 1;
    for(int i = 2; i <=n; ++i) {
        inv[i] = mod - (mod/i) * inv[mod % i] % mod;
    }
    fac_inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac_inv[i] = (fac_inv[i - 1] * inv[i]) % mod;
    }
}

ll ncr(ll n, ll r)
{
    if (n == r) return 1;
    if (n < r) return 0;
    ll res = ((fac[n] * fac_inv[r]) % mod * fac_inv[n - r]) % mod;
    return res;
}

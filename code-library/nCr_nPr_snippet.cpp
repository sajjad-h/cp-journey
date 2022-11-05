
const int N = 200005;
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
    for(int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    fac_inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac_inv[i] = (fac_inv[i - 1] * inv[i]) % mod;
    }
}

ll nCr(ll n, ll r)
{
    if (n < r) return 0;
    if (n == r || r == 0) return 1;
    ll res = ((fac[n] * fac_inv[r]) % mod * fac_inv[n - r]) % mod;
    return res;
}

ll nPr(ll n, ll r)
{
    if (n < r) return 0;
    if (r == 0) return 1;
    if (n == r) return fac[n];
    ll res = (fac[n] * fac_inv[n - r]) % mod;
    return res;
}

void pre()
{
    // C(n,r) = C(n-1,r-1) + C(n-1,r)
    for (int i = 1; i <= 30; i++) {
        ncr[i][0] = 1;
        ncr[i][1] = i;
        ncr[i][i] = 1;
    }
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}
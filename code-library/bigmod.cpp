ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b/2, mod);
    c = (c * c) % mod;
    if (b & 1) c = (c * a) % mod;
    return c;
}
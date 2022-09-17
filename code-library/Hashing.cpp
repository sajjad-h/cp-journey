const ll base = 31; // 37, 129, 131
const ll mod = 1000000007; // 1000000009;
vector<ll> preHash;

ll hashing(string s)
{
    int n = s.size();
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * base) % mod;
    }

    vector<ll> preHash = vector<ll>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preHash[i + 1] = (preHash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    return preHash[n];
}

const ll base = 31; // 37, 129, 131
const ll mod = 1000000007; // 1000000009;
vector<ll> preHash;

ll hashing(string s)
{
    int n = s.size();
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * base) % mod;
    }
    vector<ll> preHash = vector<ll>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preHash[i + 1] = (preHash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    return preHash[n];
}
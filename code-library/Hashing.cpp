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


/**
    Problem Link: https://vjudge.net/contest/516851#problem/D
**/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 2222;;
const ll base = 31; // 37, 129, 131
const ll mod = 1000000007; // 1000000009;
vector<ll> preHash;
vector<ll> p_pow;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b/2, mod);
    c = (c * c) % mod;
    if (b & 1) c = (c * a) % mod;
    return c;
}

void preCal(int n)
{
    p_pow = vector<ll>(n + 5);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * base) % mod;
    }
}

ll hashing(string s)
{
    int n = s.size();
    preHash = vector<ll>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preHash[i + 1] = (preHash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    return preHash[n];
}

ll getHash(int l, int r)
{
    ll l_hash = preHash[l - 1];
    ll r_hash = preHash[r];
    ll ans = (r_hash - l_hash) % mod;
    if (ans < 0) ans += mod;
    ans = (ans * bigmod(p_pow[l - 1], mod - 2, mod)) % mod;
    return ans;
}

void testcase()
{
    string s; cin >> s;
    hashing(s);
    int n = s.size();
    for (int i = n / 3 + 1; i <= n / 2; i++) {
        ll p1 = getHash(1, i);
        ll p2 = getHash(i + 1, 2*i);
        ll baki = n - 2*i;
        if (baki >= i + 1) continue;
        if (p1 == p2) {
            if (baki > 0) {
                ll p3 = getHash(2*(i + 1) + 1, n);
                if (p3 == getHash(1, baki)) {
                    for (int i = 0; i < 8; i++) {
                        cout << s[(n + i) % i];
                    }
                    cout << "...\n";
                    return ;
                }
            }
            for (int j = 0; j < 8; j++) {
                cout << s[(n + j) % i];
            }
            cout << "...\n";
            return ;
        }
    }
}

int main()
{
    preCal(2000);
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}

/**



**/










/**
    Problem Link: https://vjudge.net/contest/516851#problem/I
**/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 200005;

int pi[N];
int ans[N];

const ll base = 31; // 37, 129, 131
const ll mod = 1000000007; // 1000000009;
vector<ll> preHash;
vector<ll> p_pow;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll c = bigmod(a, b/2, mod);
    c = (c * c) % mod;
    if (b & 1) c = (c * a) % mod;
    return c;
}

void preCal(int n)
{
    p_pow = vector<ll>(n + 5);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * base) % mod;
    }
}

ll hashing(string s)
{
    int n = s.size();
    preHash = vector<ll>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preHash[i + 1] = (preHash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    return preHash[n];
}

ll getHash(int l, int r)
{
    ll l_hash = preHash[l - 1];
    ll r_hash = preHash[r];
    ll ans = (r_hash - l_hash) % mod;
    if (ans < 0) ans += mod;
    ans = (ans * bigmod(p_pow[l - 1], mod - 2, mod)) % mod;
    return ans;
}

void prefix_function(string s)
{
    int n = (int) s.size();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void testcase()
{
    string s; cin >> s;
    int n = s.size();
    prefix_function(s);

    // Counting the number of occurrences of each prefix
    for (int i = 0; i < n; i++) {
        ans[pi[i]]++;
    }
    for (int i = n - 1; i > 0; i--) {
        ans[pi[i - 1]] += ans[i];
    }
    for (int i = 0; i <= n; i++) {
        ans[i]++;
    }
    
    preCal(s.size());
    hashing(s);
    vector< pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
        if (getHash(1, i) == getHash(n - i + 1, n)) {
            v.push_back({i, ans[i]});
        }
    }
    cout << v.size() << "\n";
    for (auto [x, y] : v) {
        cout << x << ' ' << y << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}

/**



**/

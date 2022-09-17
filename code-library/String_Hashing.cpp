#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

const int N = 205;
vector<ll> g[N];
ll par[N];
ll vis[N];
string s;
string ss;
ll n;

void dfs(int u, int p)
{
    par[u] = p;
    vis[u] = 1;
    ss.push_back(s[u - 1]);
    for (auto v : g[u]) {
        if (v == p || vis[v] == 1) continue;
        dfs(v, u);
    }
}

ll lcm(ll a, ll b)
{
    ll g = __gcd(a, b);
    return (a / g) * b;
}

ll getCycle(string s)
{
    int n = s.size();

    const ll p = 31;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        if (n % l != 0) continue;
        set<ll> hs;
        for (int i = 0; i <= n - l; i += l) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        if (hs.size() == 1) return l;
    }
}

void testcase()
{
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        par[i] = -1;
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ss = "";
        if (vis[i] == 0) {
            dfs(i, 0);
            ll cycle = getCycle(ss);
            ans = lcm(ans, cycle);
        }
    }
    cout << ans << '\n';
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

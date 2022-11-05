#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 200005;
vector<int> g[N];
int dis[N];
ll dp[N];
int sz[N];
ll ans[N];
int n;

void dfs(int u, int par)
{
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == par) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
        dp[u] += (dp[v] + sz[v]);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int par)
{
    for (auto v : g[u]) {
        if (v == par) continue;
        ans[v] = (dp[v] - (sz[v] - 1) * dis[v]);  // answer for subtree at v
        ll x = ans[u] - (sz[v] + ans[v]);         // answer for subtree at u cutting u-v edge
        ans[v] += (x + (n - sz[v]));              // adding the value after cutting and number of left nodes
        dfs2(v, u);
    }
}

void testcase()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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

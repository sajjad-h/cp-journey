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

void testcase()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int mx = 0;
    int mx_node = 1;
    for (int i = 2; i <= n; i++) {
        if (dis[i] > mx) {
            mx = dis[i];
            mx_node = i;
        }
    }
    dis[mx_node] = 0;
    dfs(mx_node, -1);
    mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dis[i]);
    }
    cout << mx << "\n";
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

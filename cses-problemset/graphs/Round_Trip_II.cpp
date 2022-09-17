#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
int n, m;
vector<int> g[N];
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;
int ara[N];
 
int dfs(int u)
{
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return 1;
        }
        else if (color[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return 1; // cycle found
        }
    }
    color[u] = 2;
    return 0; // cycle not found in u
}
 
void findCycle()
{
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;
 
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(i)) {
            break;
        }
    }
 
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else  {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (auto x : cycle) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
 
void testcase()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    findCycle();
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
 
/**
 
 
 
**/
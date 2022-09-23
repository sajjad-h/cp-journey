const int N = 300005;

vector<int> g[N];
int vis[N];
int col[N];
int n, m;
int odd, even;

int dfs(int u)
{
    if (col[u]) odd++;
    else        even++;
    for (auto v : g[u]) {
        if (vis[v] == 0) {
            vis[v] = 1;
            col[v] = !col[u];
            if (!dfs(v)) {
                return 0;
            }
        }
        else if (col[v] == col[u]) {
            return 0;
        }
    }
    return 1;
}

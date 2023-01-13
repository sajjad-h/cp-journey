vector<vector<int>> g;
vector<int> dis, vis;
vector<int> tmp;

void dfs(int u, int par) {
    tmp.push_back(u);
    vis[u] = 1;
    for (auto v : g[u]) {
        if (v == par) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

int findDiameter(int source) {
    dfs(source, -1);
    int mx = 0;
    int mx_node = source;
    for (auto x : tmp) {
        if (dis[x] > mx) {
            mx = dis[x];
            mx_node = x;
        }
    }
    dis[mx_node] = 0;
    dfs(mx_node, -1);
    mx = 0;
    for (auto x : tmp) {
        mx = max(mx, dis[x]);
    }
    tmp.clear();
    return mx;
}
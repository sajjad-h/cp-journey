class Solution {
public:
    
    vector<vector<int>> g;
    vector<int> dis;
    vector<int> par;
    int ans;
    
    void dfs(int u, int p) {
        par[u] = p;
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    }
    
    void dfs2(int u, int p, int cur, int val, vector<int>& amount) {
        if (dis[u] == cur) val += amount[u] / 2;
        else if (dis[u] > cur) val += amount[u];
        int child = 0;
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs2(v, u, cur + 1, val, amount);
            child++;
        }
        if (child == 0) ans = max(ans, val);
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        g = vector<vector<int>>(n);
        dis = vector<int>(n, INT_MAX);
        par = vector<int>(n, -1);
        for (auto vv : edges) {
            int u = vv[0];
            int v = vv[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        int p = bob;
        int time = 0;
        while (p != -1) {
            dis[p] = time++;
            p = par[p];
        }
        ans = INT_MIN;
        dfs2(0, -1, 0, 0, amount);
        return ans;
    }
};
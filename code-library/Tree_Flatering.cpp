/**
    https://www.spoj.com/problems/PLNDTREE/en/
**/

#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

const int N = 1000005;
vector<int> g[N];
int ara[N];
int timer = 0;
int startTime[N];
int endTime[N];
string ss;

ll tree[4*N + 5][27];

void segBuild(int node, int s, int e)
{
    if (s == e) {
        tree[node][ss[ara[s] - 1] - 'a']++;
        return ;
    }
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    segBuild(left, s, mid);
    segBuild(right, mid + 1, e);
    for (int i = 0; i < 26; i++) {
        tree[node][i] = tree[left][i] + tree[right][i];
    }
}

void segUpdate(int node, int s, int e, int l, int r, int ind, char ch)
{
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    if (s > e || r < s || e < l) return ;
    if (l <= s && e <= r) {
        tree[node][ss[ind - 1] - 'a']--;
        ss[ind - 1] = ch;
        tree[node][ss[ind - 1] - 'a']++;
        return ;
    }
    segUpdate(left, s, mid, l, r, ind, ch);
    segUpdate(right, mid + 1, e, l, r, ind, ch);
    for (int i = 0; i < 26; i++) {
        tree[node][i] = tree[left][i] + tree[right][i];
    }
}

vector<int> segQuery(int node, int s, int e, int l, int r)
{
    vector<int> ans(27, 0);
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    if (s > e || r < s || e < l) return ans;
    if (l <= s && e <= r) {
        for (int i = 0; i < 26; i++) {
            ans[i] += tree[node][i];
        }
        return ans;
    }
    vector<int> lftAns = segQuery(left, s, mid, l, r);
    vector<int> rgtAns = segQuery(right, mid + 1, e, l, r);
    for (int i = 0; i < 26; i++) {
        ans[i] += (lftAns[i] + rgtAns[i]);
    }
    return ans;
}

void dfs(int u, int p)
{
    timer++;
    startTime[u] = timer;
    ara[timer] = u;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    endTime[u] = timer;
}

void testcase()
{
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> ss;
    dfs(1, 0);
    segBuild(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            vector<int> qara = segQuery(1, 1, n, startTime[x], endTime[x]);
            int odd = 0;
            for (int i = 0; i < 26; i++) {
                if (qara[i] % 2 == 1) odd++;
            }
            if (odd > 1) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            int x; cin >> x;
            char ch; cin >> ch;
            segUpdate(1, 1, n, startTime[x], startTime[x], x, ch);
        }
    }
}

int main()
{
    int t = 1; //cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

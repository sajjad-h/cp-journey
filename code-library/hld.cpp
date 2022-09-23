/**
    Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2-retake/challenges/answer-the-queries-4/problem
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int D = 18;
const int S = (1<<D);

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N][D], dep[N];
int st[S][62], id[N], tp[N];
string ss;

int getInt(char ch)
{
    if (ch >= '0' && ch <= '9') return ch - '0';
    else if (ch >= 'a' && ch <= 'z') return (ch - 'a') + 10;
    else if (ch >= 'A' && ch <= 'Z') return (ch - 'A') + 36;
    else assert(false);
}

void update(int idx, int ch, int val, int i=1, int l=1, int r=n)
{
    if(l == r)
    {
        st[i][ch] += val;
        return;
    }
    int m = (l+r)/2;
    if(idx <= m) update(idx, ch, val, i*2, l, m);
    else update(idx, ch, val, i*2+1, m+1, r);
    for (int j = 0; j < 62; j++)
    {
        st[i][j] = st[i*2][j] + st[i*2+1][j];
    }
}

vector<int> mergeQuery(vector<int> a, vector<int> b)
{
    for (int j = 0; j < 62; j++)
    {
        a[j] += b[j];
    }
    return a;
}

vector<int> query(int lo, int hi, int i=1, int l=1, int r=n)
{
    vector<int> cnt(62, 0);
    if(lo > r || hi < l) return cnt;
    if(lo <= l && r <= hi)
    {
        for (int j = 0; j < 62; j++)
        {
            cnt[j] = st[i][j];
        }
        return cnt;
    }
    int m = (l+r)/2;
    return mergeQuery(query(lo, hi, i*2, l, m),
                      query(lo, hi, i*2+1, m+1, r));
}

int dfs_sz(int cur, int par)
{
    sz[cur] = 1;
    for(int chi : adj[cur])
    {
        if(chi == par) continue;
        dep[chi] = dep[cur] + 1;
        p[chi][0] = cur;
        sz[cur] += dfs_sz(chi, cur);
    }
    return sz[cur];
}

void init_lca()
{
    for(int d = 1; d < 18; d++)
        for(int i = 1; i <= n; i++)
            p[i][d] = p[p[i][d - 1]][d - 1];
}

int ct = 1;
void dfs_hld(int cur, int par, int top)
{
    id[cur] = ct++;
    tp[cur] = top;
    update(id[cur], getInt(ss[cur]), +1);
    int h_chi = -1, h_sz = -1;
    for(int chi : adj[cur])
    {
        if(chi == par) continue;
        if(sz[chi] > h_sz)
        {
            h_sz = sz[chi];
            h_chi = chi;
        }
    }
    if(h_chi == -1) return;
    dfs_hld(h_chi, cur, top);
    for(int chi : adj[cur])
    {
        if(chi == par || chi == h_chi) continue;
        dfs_hld(chi, cur, chi);
    }
}

int lca(int a, int b)
{
    if(dep[a] < dep[b]) swap(a, b);
    for(int d = D - 1; d >= 0; d--)
    {
        if(dep[a] - (1<<d) >= dep[b])
        {
            a = p[a][d];
        }
    }
    for(int d = D - 1; d >= 0; d--)
    {
        if(p[a][d] != p[b][d])
        {
            a = p[a][d];
            b = p[b][d];
        }
    }
    if(a != b)
    {
        a = p[a][0];
        b = p[b][0];
    }
    return a;
}

vector<int> path(int chi, int par)
{
    vector<int>ret(62, 0);
    while(chi != par)
    {
        if(tp[chi] == chi)
        {
            ret[getInt(ss[chi])]++;
            chi = p[chi][0];
        }
        else if(dep[tp[chi]] > dep[par])
        {
            auto res = query(id[tp[chi]], id[chi]);
            for (int i = 0; i < 62; i++)
            {
                ret[i] += res[i];
            }
            chi = p[tp[chi]][0];
        }
        else
        {
            auto res = query(id[par]+1, id[chi]);
            for (int i = 0; i < 62; i++)
            {
                ret[i] += res[i];
            }
            break;
        }
    }
    return ret;
}

void testcase()
{
    cin >> n >> q;
    cin >> ss;
    ss = "#" + ss;
    for(int i = 2; i <= n; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_sz(1, 1);
    init_lca();
    memset(st, 0, sizeof st);
    dfs_hld(1, 1, 1);
    while(q--)
    {
        int t; cin >> t;
        if(t == 2)
        {
            int u; cin >> u;
            char ch; cin >> ch;
            update(id[u], getInt(ss[u]), -1);
            ss[u] = ch;
            update(id[u], getInt(ss[u]), +1);
        }
        else
        {
            int a, b; cin >> a >> b;
            int c = lca(a, b);
            vector<int> res = mergeQuery(path(a,c), path(b,c));
            res[getInt(ss[c])]++;
            set<int> st;
            for (int i = 0; i < 62; i++)
            {
                if (res[i] > 0) {
                    st.insert(res[i]);
                }
            }
            if (st.size() == 1) cout << "Yes\n";
            else                cout << "No\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}

/**



**/

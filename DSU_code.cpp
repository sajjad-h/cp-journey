#include <bits/stdc++.h>
using namespace std;

#define     ll     long long int

const int inf = 100000000;
const int N = 200005;
vector< tuple<int, int, int, int, int> > edges;
int par[N];
int sz[N];
int ans[N];

void init(int n)
{
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int findParent(int u)
{
	if (par[u] == u) return u;
	return par[u] = findParent(par[u]);
}

void makeUnion(int a, int b)
{
	int par_a = findParent(a);
	int par_b = findParent(b);
	if (par_a > par_b) swap(par_a, par_b);
	if (par_a != par_b) {
		par[par_b] = par_a;
		sz[par_a] += sz[par_b];
	}
}

void solve()
{
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back(make_tuple(c, 1, u, v, 0));
	}
	for (int i = 1; i <= q; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back(make_tuple(c, 0, u, v, i));
	}
	sort(edges.begin(), edges.end());
	init(n);
	for (int i = 0; i < (m + q); i++) {
		auto [c, b, u, v, ind] = edges[i];
		int par_u = findParent(u);
		int par_v = findParent(v);
		if (par_u != par_v) {
			if (b == 0) {
				ans[ind] = 1;
			} else {
				makeUnion(par_u, par_v);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		if (ans[i] == 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

int main()
{
	solve();
	return 0;
}


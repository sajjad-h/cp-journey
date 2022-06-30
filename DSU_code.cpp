#include <bits/stdc++.h>
using namespace std;

#define     ll     long long int

const int N = 200005;
int par[N];
int sz[N];

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
	if (sz[par_a] < sz[par_b]) swap(par_a, par_b);
	if (par_a != par_b) {
		par[par_b] = par_a;
		sz[par_a] += sz[par_b];
	}
}

int main()
{
	cout << "DSU code snippet\n";
	return 0;
}

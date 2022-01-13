#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

const int N = 100005;
ll tree[4*N];
ll lazy[4*N];
ll ara[N];
ll n, x, y;

void build(int node, int start, int end)
{
    int left = node << 1;
    int right = left | 1;
    if(start == end)
    {
    	lazy[node] = -1;
        tree[node] = ara[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(left, start, mid);
        build(right, mid+1, end);
    	lazy[node] = -1;
        tree[node] = tree[left] + tree[right];
    }
}

void updateRange(int node, int start, int end, int l, int r, ll val)
{
    int mid = (start + end) / 2;
    int left = node << 1;
    int right = left | 1;
    if(lazy[node] != -1)
    {
        tree[node] = (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[left] = lazy[node];
            lazy[right] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        tree[node] = (end - start + 1) * val;
        if(start != end)
        {
            lazy[left] = val;
            lazy[right] = val;
        }
        return;
    }
    updateRange(left, start, mid, l, r, val);
    updateRange(right, mid + 1, end, l, r, val);
    tree[node] = tree[left] + tree[right];
}

ll queryRange(int node, int start, int end, int l, int r)
{
    int mid = (start + end) / 2;
    int left = node << 1;
    int right = left | 1;
    if(start > end or start > r or end < l)
        return 0LL;
    if(lazy[node] != -1) {
        tree[node] = (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[left] = lazy[node];
            lazy[right] = lazy[node];
        }
        lazy[node] = -1;
    }
    if(start >= l and end <= r) {
        return tree[node];
    }
    ll p1 = queryRange(left, start, mid, l, r);
    ll p2 = queryRange(right, mid + 1, end, l, r);
    return (p1 + p2);
}

void solve()
{
	int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	vector<int> pos(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<ll> ans(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		if (pos[a[i]] == -1) {
			ans[i] += i;
			ans[n + 1] -= i;
		} else {
			ans[i] += (i - pos[a[i]]);
			ans[n + 1] -= (i - pos[a[i]]);
		}
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
	}
	for (int i = 0; i < q; i++) {
		int type, k; cin >> type >> k;
		if (type == 2) {
			cout << ans[k] << '\n';
		}
	}
}

int main()
{
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}


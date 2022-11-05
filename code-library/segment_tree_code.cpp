#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

const int N = 200000;
ll tree[4*N + 5];
ll lazy[4*N + 5];
ll ara[N + 5];

void segBuild(int node, int s, int e)
{
    if (s == e) {
        tree[node] = ara[s];
        return ;
    }
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    segBuild(left, s, mid);
    segBuild(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

void segUpdate(int node, int s, int e, int l, int r, ll val)
{
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    if (lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s > e || r < s || e < l) return ;
    if (l <= s && e <= r) {
        tree[node] += (e - s + 1) * val;
        if (s != e) {
            lazy[left] += val;
            lazy[right] += val;
        }
        return ;
    }
    segUpdate(left, s, mid, l, r, val);
    segUpdate(right, mid + 1, e, l, r, val);
    tree[node] = tree[left] + tree[right];
}

ll segQuery(int node, int s, int e, int l, int r)
{
    int mid = (s + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    if (lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s > e || r < s || e < l) return 0;
    if (l <= s && e <= r) {
        return tree[node];
    }
    return (segQuery(left, s, mid, l, r) + segQuery(right, mid + 1, e, l, r));
}

void testcase()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    segBuild(1, 1, n);
    int ones = tree[1] / n;
    vector<int> ans(n + 1, 0);
    for (int i = n; ones > 0 && i >= 1; i--) {
        segUpdate(1, 1, n, i - ones + 1, i, -1);
        ll a = segQuery(1, 1, n, i, i);
        if (a > 0) {
            ans[i] = 1;
            ones--;
        }
    }
    if (ones > 0) {
        ans[1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int t; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

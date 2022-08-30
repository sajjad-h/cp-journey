/**
 * Problem Link: https://www.spoj.com/problems/DQUERY/
 */

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 30005;
const ll mod = 1000000007;

int ara[N];
int last[1000006];
int n, q;
int bit[N];
vector< pair<int, int> > qq[1000006];

void init()
{
    for (int i = 0; i <= n; i++) {
        bit[i] = 0;
    }
    for (int i = 0; i <= 1000000; i++) {
        last[i] = 0;
    }
}

int query(int r)
{
    int res = 0;
    for ( ; r >= 0; r = (r & (r + 1)) - 1) {
        res += bit[r];
    }
    return res;
}

void add(int idx, int delta)
{
    for ( ; idx <= n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
    }
}

void testcase()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    init();
    cin >> q;
    vector<int> result(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        qq[r].push_back({l, i});
    }
    for (int i = 1; i <= n; i++) {
        if (last[ara[i]] == 0) {
            add(i, +1);
        }
        else {
            add(last[ara[i]], -1);
            add(i, +1);
        }
        last[ara[i]] = i;
        for (auto [l, ind] : qq[i]) {
            int ans = query(i) - query(l - 1);
            result[ind] = ans;
        }
    }
    for (auto x : result) {
        cout << x << "\n";
    }
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

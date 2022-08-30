#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 1000006;
const ll mod = 1000000007;

pair<int, int> segs[N];
vector<int> endpoints[N];
int n, q;
int bit[N];
vector< pair<int, int> > qq[N];

void init()
{
    for (int i = 0; i <= 1000000; i++) {
        bit[i] = 0;
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

void update(int idx, int delta)
{
    for ( ; idx <= 1000000; idx = idx | (idx + 1)) {
        bit[idx] += delta;
    }
}

void testcase()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        segs[i] = {l, r};
        endpoints[l].push_back(r);
    }
    init();
    cin >> q;
    vector<int> result(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        qq[l].push_back({r, i});
    }
    for (int i = 1; i <= 10; i++) {
        for (auto x : endpoints[i]) {
            update(x, +1);
        }
        for (auto [r, ind] : qq[i]) {
            int ans = query(10) - query(r - 1);
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

Input:

5
6 8
5 7
1 2
6 10
3 7
3
3 9
4 7
6 7



Output:
0
1
4


**/

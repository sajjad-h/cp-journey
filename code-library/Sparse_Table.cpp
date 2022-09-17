#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

const int N = 100005;
int sp[33][N];
int ara[N];

void build(int n)
{
    for (int i = 1; i <= n; i++) {
        sp[0][i] = ara[i];
    }
    int k = log2(n);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n - (1<<i) + 1; j++) {
            sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1<<(i - 1))]);
        }
    }
}

int query(int l, int r)
{
    int d = log2(r - l + 1);
    return min(sp[d][l], sp[d][r - (1<<d) + 1]);
}

void testcase(int caseno)
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    build(n);
    cout << "Case " << caseno << ":\n";
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}

int main()
{
    int t = 1; cin >> t;
    int ts = 1;
    while (t--) {
        testcase(ts++);
    }
    return 0;
}

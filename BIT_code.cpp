// Problem: https://codeforces.com/contest/1591/problem/D
// BIT, inversion counting

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

int n;
const int N = 500005;
int bit[N];
int ara[N];

void init()
{
    for (int i = 0; i <= n; i++) {
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

void add(int idx, int delta)
{
    for ( ; idx <= n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        int yes = 0;
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
            mp[ara[i]]++;
            if (mp[ara[i]] > 1) {
                yes = 1;
            }
        }
        if (yes) {
            cout << "YES\n";
            continue;
        }
        init();
        ll s = 0;
        for (int i = 0; i < n; i++) {
            ll cnt = query(n) - query(ara[i]);
            s += cnt;
            add(ara[i], 1);
        }
        if (s % 2 == 0) cout << "YES\n";
        else            cout << "NO\n";
    }

    return 0;
}

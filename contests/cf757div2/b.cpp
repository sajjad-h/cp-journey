#include <bits/stdc++.h>
using namespace std;

#define    FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define    ll       long long int

const int inf = 1e9 + 9;

int cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second > b.second;
}

int main()
{
    FASTIO

    int t; cin >> t;
    while (t--) {
        ll n;
        vector< pair<ll, ll> > v;
        cin >> n;
        vector<ll> x(n + 5);
        for (ll i = 0; i < n; i++) {
            ll d; cin >> d;
            v.push_back(make_pair(i + 1, d));
        }
        sort(v.begin(), v.end(), cmp);
        ll l = 0, r = 2, toggle = 1;
        x[0] = 1;
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            ll d = v[i].second;
            ll ind = v[i].first;
            if (toggle) {
                res += 2 * (r - 1) * v[i].second;
                x[ind] = r;
                r++;
            } else {
                res += 2 * (1 - l) * v[i].second;
                x[ind] = l;
                l--;
            }
            toggle = !toggle;
        }
        cout << res << '\n';
        for (ll i = 0; i <= n; i++) {
            if (i != 0) cout << ' ';
            cout << x[i];
        }
        cout << '\n';
    }
    return 0;
}

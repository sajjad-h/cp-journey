#include <bits/stdc++.h>
using namespace std;

#define    FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e9 + 9;

int main()
{
    FASTIO

    int t; cin >> t;
    while (t--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int d; cin >> d;
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (l <= v[i] && v[i] <= r) {
                if (k - v[i] >= 0) {
                    k -= v[i];
                    res++;
                } else {
                    break;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}

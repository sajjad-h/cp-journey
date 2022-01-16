#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

const int N = 5000006;
int multiples[N], cnt[N];
ll dp[N];

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n, mx = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        cnt[d]++;
        mx = max(mx, d);
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            multiples[i] += cnt[j];
        }
    }
    ll ans = 0;
    for (int i = mx; i >= 1; i--) {
        dp[i] = multiples[i] * (ll) i;
        for (int j = 2 * i; j <= mx; j += i) {
            dp[i] = max(dp[i], dp[j] + (multiples[i] - multiples[j]) * (ll) i);
        }
        ans = max(ans, dp[i] + (n - multiples[i]));
    }
    cout << ans << '\n';
    return 0;
}

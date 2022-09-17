#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll total = 0;
    for (auto x : a) total += x;
    sort(a.begin(), a.end());
    ll s_left = 0;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        s_left += a[i];
        ll s_right = total - s_left;
        ll cost = ((i + 1) * a[i] - s_left) + (s_right - (n - i - 1) * a[i]);
        ans = min(ans, cost);
    }
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}
 
/**
 
 
 
**/
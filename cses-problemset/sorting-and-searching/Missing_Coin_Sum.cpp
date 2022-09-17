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
    sort(a.begin(), a.end());
    ll res = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > res) break;
        res += a[i];
    }
    cout << res << "\n";
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
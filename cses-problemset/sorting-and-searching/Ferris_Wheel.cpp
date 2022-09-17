#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            i++;
            j--;
            ans++;
        }
        else {
            j--;
            ans++;
        }
    }
    if (i == j) ans++;
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
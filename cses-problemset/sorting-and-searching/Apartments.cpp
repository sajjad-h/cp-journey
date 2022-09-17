#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int i = 0, j = 0;
    while (j < b.size() && i < a.size()) {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            i++;
            j++;
            ans++;
        }
        else if (a[i] + k < b[j]) i++;
        else if (a[i] - k > b[j]) j++;
        else {
            assert(false);
        }
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
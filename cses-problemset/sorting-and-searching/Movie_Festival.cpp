#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n; cin >> n;
    vector< pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
         });
    int ans = 0;
    int pre = 0;
    for (auto [x, y] : v) {
        if (pre <= x) {
            ans++;
            pre = y;
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
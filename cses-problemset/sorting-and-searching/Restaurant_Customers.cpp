#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        mp[a]++;
        mp[b + 1]--;
    }
    int pre = 0;
    int ans = 0;
    for (auto [x, c] : mp) {
        pre += c;
        ans = max(ans, pre);
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
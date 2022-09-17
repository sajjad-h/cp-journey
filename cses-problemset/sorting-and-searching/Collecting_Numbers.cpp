#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n; cin >> n;
    int a[n + 2];
    int pos[n + 2];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i - 1] > pos[i]) ans++;
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
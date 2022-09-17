#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n, m; cin >> n >> m;
    int ara[n + 2];
    int pos[n + 2];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;
        ara[i] = x;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i - 1] > pos[i]) ans++;
    }
    while (m--) {
        int x, y; cin >> x >> y;
        int a = ara[x];
        int b = ara[y];
        swap(ara[x], ara[y]);
        if (a > b) swap(a, b);
        if (a - 1 >= 1) if (pos[a - 1] > pos[a]) ans--;
        if (a + 1 <= n) if (pos[a] > pos[a + 1]) ans--;
        if (b - 1 >= 1 && a + 1 < b) if (pos[b - 1] > pos[b]) ans--;
        if (b + 1 <= n) if (pos[b] > pos[b + 1]) ans--;
        swap(pos[a], pos[b]);
        if (a - 1 >= 1) if (pos[a - 1] > pos[a]) ans++;
        if (a + 1 <= n) if (pos[a] > pos[a + 1]) ans++;
        if (b - 1 >= 1 && a + 1 < b) if (pos[b - 1] > pos[b]) ans++;
        if (b + 1 <= n) if (pos[b] > pos[b + 1]) ans++;
        cout << ans << "\n";
    }
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
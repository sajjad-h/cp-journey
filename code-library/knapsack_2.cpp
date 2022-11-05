/**
 * Problem Link: https://vjudge.net/contest/523165#problem/E
**/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 105;
const ll mod = 1000000007;

ll w[N], v[N];
int n, W;
ll dp[102][100005];

ll solve(int at, int taken)
{
    if (at == n) {
        if (taken <= 0) return 0;
        return INT_MAX;
    }
    if (taken <= 0) return 0;
    if (dp[at][taken] != -1) return dp[at][taken];
    ll ans = solve(at + 1, taken);
    ans = min(ans, w[at] + solve(at + 1, taken - v[at]));
    return dp[at][taken] = ans;
}

void testcase()
{
    cin >> n >> W;
    int sumVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        sumVal += v[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sumVal; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = sumVal; i >= 0; i--) {
        if (solve(0, i) <= W) {
            cout << i << "\n";
            return ;
        }
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

/**

https://atcoder.jp/contests/dp/tasks/dp_u?lang=en

**/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 16;
ll f[1<<N];
ll dp[1<<N];
ll ara[N][N];
int n;

void testcase()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ara[i][j];
        }
    }
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask>>i) & 1) {
                for (int j = i + 1; j < n; j++) {
                    if ((mask>>j) & 1) {
                        f[mask] += ara[i][j];
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1<<n); mask++) {
        dp[mask] = f[mask];
        for (int subset = mask; subset > 0; subset = (subset - 1) & mask) {
            int complementSet = mask ^ subset;
            dp[mask] = max(dp[mask], dp[subset] + dp[complementSet]);
        }
    }
    cout << dp[(1<<n) - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case #" << tc << ": ";
        testcase();
    }
    return 0;
}

/**



**/

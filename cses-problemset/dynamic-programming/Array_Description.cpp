#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1000000007;
int n, m;
int ara[100005];
int dp[100002][102];
 
int solve(int at, int d)
{
    if (abs(ara[at - 1] - ara[at - 2]) > 1 && at >= 3)
        return 0;
    if (at == n + 1)
        return 1;
    if (dp[at][d] != -1)
        return dp[at][d];
    int r1, r2, r3, r, i, j, k;
    r1 = r2 = r3 = r = 0;
    if (ara[at] == 0)
    {
        if (at == 1)
        {
            for (i = 1; i <= m; i++)
            {
                ara[at] = i;
                r = (r + solve(at + 1, i)) % mod;
                //cout << i << " " << r << "\n";
                ara[at] = 0;
            }
        }
        else
        {
            for (i = ara[at - 1], j = 0; j < 2 && i <= m; i++, j++)
            {
                ara[at] = i;
                r = (r + solve(at + 1, i)) % mod;
                //cout << i << " " << r << "\n";
                ara[at] = 0;
            }
            for (i = ara[at - 1] - 1, j = 0; j < 1 && i >= 1; i--, j++)
            {
                ara[at] = i;
                r = (r + solve(at + 1, i)) % mod;
                //cout << i << " " << r << "\n";
                ara[at] = 0;
            }
        }
    }
    else
        r = (r + solve(at + 1, 0)) % mod;
    dp[at][d] = r;
    return r;
}
 
int main( )
{
    //freopen("in.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    int i;
    for (i = 1; i <= n; i++)
        cin >> ara[i];
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0) << "\n";
    return 0;
}
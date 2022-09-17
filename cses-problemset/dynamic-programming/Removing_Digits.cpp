#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1000000000;
int n;
int dp[10000006];
 
int solve(int n)
{
    //cout << n << "\n";
    if (n < 10)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int d, t = n;
    int r = inf;
    while (t != 0)
    {
        d = t % 10;
        t /= 10;
        if (d == 0) continue;
        r = min(r, 1 + solve(n - d));
    }
    dp[n] = r;
    return r;
}
 
int main( )
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << solve(n) << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define    ll    long long int
 
const ll mod = 1000000007;
int dp[1000006][7];
ll solve(int sum, int d)
{
    if (sum == 0)
        return 1;
    if (dp[sum][d] != -1)
        return dp[sum][d];
    ll res = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (sum - i >= 0)
        {
            res += solve(sum - i, i);
            if (res >= mod)
                res -= mod;
        }
    }
    dp[sum][d] = res;
    return res;
}
 
int main( )
{
    int n;
    memset(dp, -1, sizeof dp);
    cin >> n;
    cout << solve(n, 0) << "\n";
    return 0;
}
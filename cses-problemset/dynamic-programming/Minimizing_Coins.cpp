#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1000000000;
int x, n;
int coin[111];
int dp[1000002];
 
int main( )
{
    cin >> n >> x;
    int i, j;
    for (i = 1; i <= n; i++)
        cin >> coin[i];
    for (i = 1; i <= x; i++)
        dp[i] = inf;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i - coin[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
        }
    }
    if (dp[x] >= inf)
        cout << "-1\n";
    else
        cout << dp[x] << "\n";
    return 0;
}
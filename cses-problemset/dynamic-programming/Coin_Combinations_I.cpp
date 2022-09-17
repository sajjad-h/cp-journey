#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const ll mod = 1000000007;
ll n, m;
ll coin[111];
ll dp[1000006];
 
/**
    n = number of coins,
    m = amount need to make
    Let, n = 3, m = 9
    Coins: {2, 3, 5}
 
    8 ways:
    2 + 2 + 5
    2 + 5 + 2
    3 + 3 + 3
    5 + 2 + 2
    2 + 2 + 2 + 3
    2 + 2 + 3 + 2
    2 + 3 + 2 + 2
    3 + 2 + 2 + 2
**/
 
int main( )
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    for (int i = 0; i <= m; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i - coin[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coin[j]]) % mod;
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1000000007;
int n, m;
int dp[5002][5002];
string s, t;
 
int solve(int i, int j)
{
    if (i == n)
        return (m - j);
    if (j == m)
        return (n - i);
    int r1, r2, r3, r;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        r = solve(i + 1, j + 1);
    else
    {
        r1 = 1 + solve(i, j + 1);
        r2 = 1 + solve(i + 1, j);
        r3 = 1 + solve(i + 1, j + 1);
        r = min(r1, min(r2, r3));
    }
    dp[i][j] = r;
    return r;
}
 
int main( )
{
    //freopen("in.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> s >> t;
    n = (int) s.size( );
    m = (int) t.size( );
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << "\n";
    return 0;
}
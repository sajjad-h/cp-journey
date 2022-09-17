#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1e9;
int dp[555][555];
 
int solve(int a, int b)
{
    //cout << a << ' ' << b << '\n';
    if (a == b) {
        return 0;
    }
    if (a > b) {
        swap(a, b);
    }
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    int mn = inf;
    for (int i = 1; i < a; i++) {
        int res = 1 + solve(i, b) + solve(a - i, b);
        mn = min(mn, res);
    }
    for (int i = 1; i < b; i++) {
        int res = 1 + solve(i, a) + solve(b - i, a);
        mn = min(mn, res);
    }
    dp[a][b] = mn;
    return mn;
}
 
int main( )
{
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << solve(a, b) << '\n';
    return 0;
}
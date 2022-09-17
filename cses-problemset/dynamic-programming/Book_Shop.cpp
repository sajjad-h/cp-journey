#include <bits/stdc++.h>
using namespace std;
 
struct data
{
    int price, page;
    data( )
    {
        price = page = 0;
    }
};
 
bool cmp(data a, data b)
{
    return a.price > b.price;
}
 
data books[1002];
int dp[1002][100005];
int n, x;
 
int solve( )
{
    int i, j;
    for (i = 1; i <= n + 1; i++)
    {
        for (j = 1; j <= x; j++)
        {
            if (books[i - 1].price <= j)
                dp[i][j] = max(dp[i - 1][j], books[i - 1].page + dp[i - 1][j - books[i - 1].price]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n + 1][x];
}
 
int main( )
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> books[i].price;
    for (int i = 1; i <= n; i++)
        cin >> books[i].page;
    cout << solve( ) << "\n";
    return 0;
}
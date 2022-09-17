#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1000000007;
char grid[1002][1002];
int way[1002][1002];
int n;
 
int solve(int x, int y)
{
    if (x == n && y == n)
        return 1;
    if (way[x][y] != -1)
        return way[x][y];
    int r1 = 0, r2 = 0, r;
    if (x + 1 <= n && grid[x + 1][y] == '.')
        r1 = solve(x + 1, y);
    if (y + 1 <= n && grid[x][y + 1] == '.')
        r2 = solve(x, y + 1);
    r = (r1 + r2) % mod;
    way[x][y] = r;
    return r;
}
 
int main( )
{
    scanf("%d", &n);
    getchar( );
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%c", &grid[i][j]);
        }
        getchar( );
    }
    memset(way, -1, sizeof way);
    if (grid[1][1] == '*')
        cout << "0\n";
    else
        cout << solve(1, 1) << "\n";
    return 0;
}
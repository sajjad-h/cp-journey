/**
    Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2-retake/challenges/jumping-jack-5-1/problem
**/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const ll M = 33;
const ll mod = 1000000007;

void matMul(ll a[][M], ll b[][M], ll res[][M], ll m)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            res[i][j] = 0;
            for (int k = 1; k <= m; k++) {
                res[i][j] += (a[i][k] * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
}

void matCopy(ll a[][M], ll b[][M], ll m)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void matExpo(ll a[][M], ll n, ll m, ll res[][M])
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) res[i][j] = 1;
            else        res[i][j] = 0;
        }
    }
    ll tmp[M][M];
    while (n) {
        if (n & 1) {
            matMul(res, a, tmp, m);
            matCopy(res, tmp, m);
            n--;
        }
        matMul(a, a, tmp, m);
        matCopy(a, tmp, m);
        n /= 2;
    }
}

void testcase()
{
    ll n, m; cin >> n >> m;
    ll tran[M][M], res[M][M];
    memset(tran, 0, sizeof tran);
    for (int i = 2, j = 1; i <= m && j <= m; i++, j++) {
        tran[i][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        tran[i][m] = 1;
    }
    matExpo(tran, n - 1, m, res);
    ll ans = 0;
    ll p = 2;
    for (int i = 1; i < m; i++) {
        ans += (p * res[i][1]) % mod; ans %= mod;
        p = p << 1;
    }
    ans += ((p - 1) * res[m][1]) % mod; ans %= mod;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        testcase();
    }
    return 0;
}

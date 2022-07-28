#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const ll M = 5;
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
    ll a, b, n; cin >> a >> b >> n;
    ll tran[M][M], res[M][M];
    tran[1][1] = 0; tran[1][2] = 1;
    tran[2][1] = 1; tran[2][2] = 1;
    matExpo(tran, n, 2, res);
    cout << (a * res[1][1] + b * res[2][1]) % mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

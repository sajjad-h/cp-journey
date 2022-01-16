#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

const int N = 20000007;
int multiples[N], cnt[N];
ll dp[N];
vector<int> primes;
int isPrime[N];

void seive(int n)
{
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = 1;
    }
    int root = sqrt(n);
    for (int i = 3; i <= root; i++) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == 0) primes.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    seive(N - 1);
    int n, mx = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        cnt[d]++;
        mx = max(mx, d);
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            multiples[i] += cnt[j];
        }
    }
    ll ans = 0;
    for (int i = mx; i >= 1; i--) {
        dp[i] = multiples[i] * (ll) i;
        for (int j = 0; i * primes[j] <= mx; j++) {
            int mul = i * primes[j];
            dp[i] = max(dp[i], dp[mul] + (multiples[i] - multiples[mul]) * (ll) i);
        }
        ans = max(ans, dp[i] + (n - multiples[i]));
    }
    cout << ans << '\n';
    return 0;
}

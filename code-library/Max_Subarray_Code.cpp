// CF 1373D solution

#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

ll maxSubarray(vector<ll> v)
{
    ll ans = LLONG_MIN;
    ll pre = 0;
    for (auto x : v) {
        pre = pre + x;
        ans = max(ans, pre);
        if (pre < 0) pre = 0;
    }
    return ans;
}

void testcase()
{
    int n; cin >> n;
    ll ara[n + 5];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ara[i];
        if (i % 2 == 0) {
            sum += ara[i];
        }
    }
    vector<ll> v1, v2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (i + 1 < n) {
                v1.push_back(ara[i + 1] - ara[i]);
            }
        }
        else {
            if (i + 1 < n) {
                v2.push_back(ara[i] - ara[i + 1]);
            }
        }
    }
    cout << max(sum, sum + max(maxSubarray(v1), maxSubarray(v2))) << '\n';
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

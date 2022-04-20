// CF 1373D solution

#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

ll maxSubarray(vector<ll> v)
{
    ll maxSoFar = LLONG_MIN;
    ll maxEndingHere = 0;
    for (int i = 0; i < v.size(); i++) {
        maxEndingHere = maxEndingHere + v[i];
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
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

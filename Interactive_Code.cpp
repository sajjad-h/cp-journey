#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

int askQuery(int l, int r)
{
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}

void testcase()
{
    int n, t; cin >> n >> t;
    int k; cin >> k;
    int lo = 1;
    int hi = n;
    int ans = n + 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int q = askQuery(1, mid);
        int zeroes = mid - q;
        if (zeroes == k) {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else if (zeroes > k) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}


// https://codeforces.com/contest/1520/problem/F1

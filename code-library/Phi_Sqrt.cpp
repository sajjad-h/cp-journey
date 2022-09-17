/**
    Euler Totient Function O(sqrt(N))
    Preprocessing: no
    Per Query: O(sqrt(N))
    Space: O(1)
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << phi(n) << "\n";
    }
    return 0;
}

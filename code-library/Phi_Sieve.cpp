/**
    Euler Totient Function O(1)
    Preprocessing: O(N log log N)
    Per Query: O(1)
    Space: O(N)
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int phi[N];

void phiSieve(int n)
{
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 4; i <= n; i += 2) {
        phi[i] /= 2;
    }
    for (int i = 3; i <= n; i += 2) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

int main()
{
    phiSieve(1000000);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << phi[n] << "\n";
    }
    return 0;
}

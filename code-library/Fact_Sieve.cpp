/**
    Prime Factorizaton (using Seive)
    Preprocessing: O(N log log N)
    Per Query: O(log n)
    Space: O(N)
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int minPrime[N];

void factSieve(int n)
{
    for (int i = 0; i <= n; i++) {
        minPrime[i] = -1;
    }
    for (int i = 4; i <= n; i += 2) {
        minPrime[i] = 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (minPrime[i] == -1) {
            for (int j = i * i; j <= n; j += 2*i) {
                minPrime[j] = i;
            }
        }
    }
}

vector<int> factQuery(int n)
{
    vector<int> factors;
    while (minPrime[n] != -1) {
        factors.push_back(minPrime[n]);
        n = n / minPrime[n];
    }
    factors.push_back(n);
    return factors;
}

int main()
{
    factSieve(1000000);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> factors = factQuery(n);
        cout << n << " = ";
        cout << factors[0];
        for (int i = 1; i < factors.size(); i++) {
            cout << " * " << factors[i];
        }
        cout << "\n";
    }
    return 0;
}

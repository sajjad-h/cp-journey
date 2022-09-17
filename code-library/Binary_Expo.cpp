/**
    Binary Exponentiation O(log n)
    Preprocessing: no
    Per Query: O(log n)
    Space: O(1)
**/

#include <bits/stdc++.h>
using namespace std;

int binExpo(int a, int n)
{
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * a;
            n--;
        }
        a = (a * a);
        n /= 2;
    }
    return res;
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        int a, n; cin >> a >> n;
        cout << binExpo(a, n) << "\n";
    }
    return 0;
}


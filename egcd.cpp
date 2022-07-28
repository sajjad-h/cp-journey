/**
    Extended Euclidean Algorithm O(log n)
    Find x, y given ax + by = gcd(a, b)
    Preprocessing: no
    Per Query: O(log n)
    Space: O(1)
**/

#include <bits/stdc++.h>
using namespace std;

#define  ll   long long int

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    int t = 1; cin >> t;
    while (t--) {
        ll a, b, x, y;
        cin >> a >> b;
        ll g = egcd(a, b, x, y);
        cout << g << " " << x << " " << y << "\n";
        cout << a << " * " << x << " + " << b << " * " << y << " = " << g << "\n";
    }
    return 0;
}


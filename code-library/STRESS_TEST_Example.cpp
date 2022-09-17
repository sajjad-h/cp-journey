/**
    Problem Link: https://vjudge.net/problem/Gym-100886G
*/

#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

const int N = 200005;
const ll mod = 1000000007;

ll to_integer(string sa)
{
    ll res = 0;
    for (auto ch : sa) {
        res = res * 10 + (ch - '0');
    }
    return res;
}

ll digitProduct(ll x)
{
    ll res = 1;
    while (x) {
        res *= (x % 10);
        x /= 10;
    }
    return res;
}

ll soln1(ll a, ll b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    ll ans = a;
    for (int i = 0; i < sb.size(); i++) {
        if (sb[i] == '0') continue;
        string sc = sb;
        sc[i] = ((sc[i] - '0') - 1) + '0';
        for (int j = i + 1; j < sc.size(); j++) {
            sc[j] = '9';
        }
        ll c = to_integer(sc);
        if (c >= a && digitProduct(ans) < digitProduct(c)) {
            ans = c;
        }
    }
    return ans;
}

ll soln2(ll a, ll b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    ll ans = b;
    for (int i = 0; i < sb.size(); i++) {
        if (sb[i] == '0') continue;
        string sc = sb;
        sc[i] = ((sc[i] - '0') - 1) + '0';
        for (int j = i + 1; j < sc.size(); j++) {
            sc[j] = '9';
        }
        ll c = to_integer(sc);
        if (c >= a && digitProduct(ans) < digitProduct(c)) {
            ans = c;
        }
    }
    return ans;
}

void testcase()
{
    ll a = rand() % 100 + 1, b = rand() % 100 + 1;
    if (a > b) swap(a, b);
    ll ans_a = soln1(a, b);
    ll ans_b = soln2(a, b);
    if (digitProduct(ans_a) != digitProduct(ans_b)) {
        cout << ans_a << " " << ans_b << " " << a << " " << b << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case " << tc << ": ";
        testcase();
    }
    return 0;
}

/**



**/

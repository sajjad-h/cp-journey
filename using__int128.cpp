#include <bits/stdc++.h>
using namespace std;

#define   ll    long long int

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

void testcase()
{
    ll n; cin >> n;
    map<ll, ll> mp;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
        mp[x]++;
    }
    __int128 ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        ll baki = (n - i) - (mp[x] + mp[x + 1] + mp[x - 1]);
        ll s = sum - (mp[x] * x + mp[x + 1] * (x + 1) + mp[x - 1] * (x - 1));
        if (baki) ans += (s - baki * x);
        sum -= x;
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}

/**

Problem Link: https://codeforces.com/contest/903/problem/D

**/
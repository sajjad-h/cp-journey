#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n, x; cin >> n >> x;
    vector<int> v;
    map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
        mp[x].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        int d = x - v[i];
        if (mp.count(d)) {
            for (auto p : mp[d]) {
                if (p != (i + 1)) {
                    cout << i + 1 << " " << p << "\n";
                    return ;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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
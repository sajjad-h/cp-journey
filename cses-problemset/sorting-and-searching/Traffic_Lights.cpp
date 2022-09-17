#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
void testcase()
{
    int x, n; cin >> x >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set< pair<int, int> > st;
    st.insert({1, x});
    map<int, int> mp;
    mp[x]++;
    for (auto x : a) {
        auto it = st.lower_bound({x, INT_MAX}); it--;
        auto [u, v] = *it;
        mp[v - u + 1]--;
        if (mp[v - u + 1] == 0) mp.erase(v - u + 1);
        st.erase({u, v});
        st.insert({u, x});
        st.insert({x + 1, v});
        mp[x - u + 1]++;
        mp[v - x]++;
        cout << (*mp.rbegin()).first << " ";
    }
    cout << "\n";
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
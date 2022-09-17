#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
void testcase()
{
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    multiset<int> st;
    st.insert(a[0]);
    for (int i = 1; i < n; i++) {
        auto it = st.upper_bound(a[i]);
        if (it == st.end()) {
            st.insert(a[i]);
        }
        else {
            st.erase(it);
            st.insert(a[i]);
        }
    }
    cout << (int) st.size() << "\n";
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
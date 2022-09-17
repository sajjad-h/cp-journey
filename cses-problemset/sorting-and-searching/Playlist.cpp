#include <bits/stdc++.h>
using namespace std;
 
#define   ll    long long int
 
const int N = 200005;
const ll mod = 1000000007;
 
void testcase()
{
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> st;
    st.insert(a[0]);
    int i = 0, j = 1;
    int ans = 1;
    while (i < n && j < n) {
        ans = max(ans, (j - i));
        if (st.find(a[j]) == st.end()) {
            st.insert(a[j]);
            j++;
        }
        else {
            while (a[i] != a[j]) {
                st.erase(a[i]);
                i++;
            }
            i++;
            j++;
        }
    }
    ans = max(ans, (j - i));
    cout << ans << "\n";
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